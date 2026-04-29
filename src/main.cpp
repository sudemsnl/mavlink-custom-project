#include <iostream>
#include <iomanip>
#include <thread>
#include <chrono>
#include <cstring>
#include <cstdint>

#ifdef _WIN32
#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "ws2_32.lib")
#else
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#endif

extern "C" {
#include "../generated_custom/system_extension/mavlink.h"
}

static uint64_t now_ms()
{
    using namespace std::chrono;
    return duration_cast<milliseconds>(
        steady_clock::now().time_since_epoch()
    ).count(); //şimdilik kullanılmıyor. sistemin sabit çalışan saatinden geçen sğreyi ms çevirmek için
}

static bool init_socket(
#ifdef _WIN32
    SOCKET &sock, // referans ile main içindeki sock değişkenine gerçekten yazılır
#else
    int &sock,
#endif
    sockaddr_in &target_addr,
    const char* ip,// dışarıdan hedef IP ve port gönderimi
    int port
)
{
#ifdef _WIN32
    WSADATA wsaData{};
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "WSAStartup failed\n";
        return false;
    }

    sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP); //UDP socket oluşturma, AF IPv4 SOCK_DGRAM UDP kullanılacak demek
    if (sock == INVALID_SOCKET) {
        std::cerr << "Socket creation failed\n";
        return false;
    }
#else
    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        std::cerr << "Socket creation failed\n";
        return false;
    }
#endif

    std::memset(&target_addr, 0, sizeof(target_addr)); //linux tarafı
    target_addr.sin_family = AF_INET;
    target_addr.sin_port = htons(port);

    if (inet_pton(AF_INET, ip, &target_addr.sin_addr) <= 0) {
        std::cerr << "Invalid target IP\n";
        return false;
    }

    return true;
}

static bool send_mavlink_message( //MAVlink mesajını udp ile gönderir
#ifdef _WIN32
    SOCKET sock,
#else
    int sock,
#endif
    const sockaddr_in &target_addr, //mesajın gönderileceği hedef adres alınır
    const mavlink_message_t &msg // gönderilecek MAVlink mesajı alınır
)
{
    uint8_t buffer[MAVLINK_MAX_PACKET_LEN]; // MAVLink mesajının byte haline çevrileceği kısım
    uint16_t len = mavlink_msg_to_send_buffer(buffer, &msg);

    int sent = sendto(
        sock,
        reinterpret_cast<const char*>(buffer), // buffer uint8_t tipinde ama sento için char tip dönüşümü yapılmalı
        len,
        0,
        reinterpret_cast<const sockaddr*>(&target_addr),
        sizeof(target_addr)
    );

    return sent == len;
} //gönderme işlemi tamamlanıyor

int main()
{
#ifdef _WIN32
    SOCKET sock;
#else
    int sock;
#endif
    sockaddr_in target_addr{};

    const char* target_ip = "127.0.0.1";
    const int target_port = 14551;

    if (!init_socket(sock, target_addr, target_ip, target_port)) {
        return 1;
    }

    const uint8_t system_id = 1;
    const uint8_t component_id = 191; // companion-computer benzeri bir ID

    std::cout << "UDP MAVLink sender started -> "
              << target_ip << ":" << target_port << "\n";

    float cpu_load = 25.0f;
    float temperature = 41.5f;
    uint8_t health_state = 1;
    uint32_t uptime_ms = 0;

    while (true)// sürekli çalışma
    {
        {
            mavlink_message_t heartbeat_msg{};
            mavlink_msg_heartbeat_pack(
                system_id,
                component_id,
                &heartbeat_msg, //paketlenen mesaj buraya yazılıyor
                MAV_TYPE_ONBOARD_CONTROLLER,
                MAV_AUTOPILOT_INVALID,
                0,
                0,//base ve custom mode alanları
                MAV_STATE_ACTIVE
            );

            if (!send_mavlink_message(sock, target_addr, heartbeat_msg)) { //HEARBEAT artık udp ile gönderiliyor 
                std::cerr << "HEARTBEAT send failed\n";
            }
        }

        {
            mavlink_message_t custom_msg{}; //custom için Yenni bir MAVlink mesaj nesnesi oluşturuluyor
            mavlink_msg_system_extension_status_pack(  // bu fonksiyon MAVLink XML dosyasından üretildi
                system_id,
                component_id,
                &custom_msg,
                cpu_load,
                temperature,
                health_state,
                uptime_ms
            );

            if (!send_mavlink_message(sock, target_addr, custom_msg)) {
                std::cerr << "CUSTOM message send failed\n";
            } else {
                std::cout << "[TX] SYSTEM_EXTENSION_STATUS | "
                          << "cpu_load=" << std::fixed << std::setprecision(2) << cpu_load
                          << " temp=" << temperature
                          << " health=" << static_cast<int>(health_state)
                          << " uptime_ms=" << uptime_ms
                          << "\n";
            }
        }

        cpu_load += 1.3f;
        if (cpu_load > 95.0f) cpu_load = 15.0f;

        temperature += 0.4f;
        if (temperature > 72.0f) temperature = 40.0f;

        uptime_ms += 1000;

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

#ifdef _WIN32
    closesocket(sock);
    WSACleanup();
#else
    close(sock);
#endif

    return 0;
}
