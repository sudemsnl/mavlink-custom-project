#include <iostream>
#include <cstdint>

extern "C" {
    // Custom dialect'in ana header'ı
    #include "../generated_custom/system_extension/mavlink.h"
}

int main() {
    mavlink_message_t msg;
    uint8_t buffer[MAVLINK_MAX_PACKET_LEN];

    // Custom mesaj alanlarımız
    float cpu_load = 37.5f;          // %
    float temperature = 52.3f;       // Celsius
    uint8_t health_state = 0;        // 0=OK, 1=WARNING, 2=ERROR
    uint32_t uptime_ms = 1234567;    // ms

    // SYSTEM_EXTENSION_STATUS mesajını pack et
    // (sistem id=1, component id=200 örnek)
    mavlink_msg_system_extension_status_pack(
        1, 200, &msg,
        cpu_load,
        temperature,
        health_state,
        uptime_ms
    );

    // Byte buffer'a çevir
    uint16_t len = mavlink_msg_to_send_buffer(buffer, &msg);

    std::cout << "Custom MAVLink mesaj encode edildi!" << std::endl;
    std::cout << "Msg ID: " << msg.msgid << std::endl;
    std::cout << "Packet length: " << len << std::endl;

    //decode ederek doğrulayalım
    mavlink_system_extension_status_t decoded;
    mavlink_msg_system_extension_status_decode(&msg, &decoded);

    std::cout << "Decoded cpu_load: " << decoded.cpu_load << std::endl;
    std::cout << "Decoded temperature: " << decoded.temperature << std::endl;
    std::cout << "Decoded health_state: " << (int)decoded.health_state << std::endl;
    std::cout << "Decoded uptime_ms: " << decoded.uptime_ms << std::endl;

    return 0;
}
