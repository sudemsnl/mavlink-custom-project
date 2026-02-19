#pragma once
// MESSAGE SYSTEM_EXTENSION_STATUS PACKING

#define MAVLINK_MSG_ID_SYSTEM_EXTENSION_STATUS 42000


typedef struct __mavlink_system_extension_status_t {
 float cpu_load; /*<  */
 float temperature; /*<  */
 uint32_t uptime_ms; /*<  */
 uint8_t health_state; /*<  */
} mavlink_system_extension_status_t;

#define MAVLINK_MSG_ID_SYSTEM_EXTENSION_STATUS_LEN 13
#define MAVLINK_MSG_ID_SYSTEM_EXTENSION_STATUS_MIN_LEN 13
#define MAVLINK_MSG_ID_42000_LEN 13
#define MAVLINK_MSG_ID_42000_MIN_LEN 13

#define MAVLINK_MSG_ID_SYSTEM_EXTENSION_STATUS_CRC 91
#define MAVLINK_MSG_ID_42000_CRC 91



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_SYSTEM_EXTENSION_STATUS { \
    42000, \
    "SYSTEM_EXTENSION_STATUS", \
    4, \
    {  { "cpu_load", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_system_extension_status_t, cpu_load) }, \
         { "temperature", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_system_extension_status_t, temperature) }, \
         { "health_state", NULL, MAVLINK_TYPE_UINT8_T, 0, 12, offsetof(mavlink_system_extension_status_t, health_state) }, \
         { "uptime_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_system_extension_status_t, uptime_ms) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_SYSTEM_EXTENSION_STATUS { \
    "SYSTEM_EXTENSION_STATUS", \
    4, \
    {  { "cpu_load", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_system_extension_status_t, cpu_load) }, \
         { "temperature", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_system_extension_status_t, temperature) }, \
         { "health_state", NULL, MAVLINK_TYPE_UINT8_T, 0, 12, offsetof(mavlink_system_extension_status_t, health_state) }, \
         { "uptime_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_system_extension_status_t, uptime_ms) }, \
         } \
}
#endif

/**
 * @brief Pack a system_extension_status message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param cpu_load  
 * @param temperature  
 * @param health_state  
 * @param uptime_ms  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_system_extension_status_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               float cpu_load, float temperature, uint8_t health_state, uint32_t uptime_ms)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SYSTEM_EXTENSION_STATUS_LEN];
    _mav_put_float(buf, 0, cpu_load);
    _mav_put_float(buf, 4, temperature);
    _mav_put_uint32_t(buf, 8, uptime_ms);
    _mav_put_uint8_t(buf, 12, health_state);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SYSTEM_EXTENSION_STATUS_LEN);
#else
    mavlink_system_extension_status_t packet;
    packet.cpu_load = cpu_load;
    packet.temperature = temperature;
    packet.uptime_ms = uptime_ms;
    packet.health_state = health_state;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SYSTEM_EXTENSION_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SYSTEM_EXTENSION_STATUS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SYSTEM_EXTENSION_STATUS_MIN_LEN, MAVLINK_MSG_ID_SYSTEM_EXTENSION_STATUS_LEN, MAVLINK_MSG_ID_SYSTEM_EXTENSION_STATUS_CRC);
}

/**
 * @brief Pack a system_extension_status message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param cpu_load  
 * @param temperature  
 * @param health_state  
 * @param uptime_ms  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_system_extension_status_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               float cpu_load, float temperature, uint8_t health_state, uint32_t uptime_ms)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SYSTEM_EXTENSION_STATUS_LEN];
    _mav_put_float(buf, 0, cpu_load);
    _mav_put_float(buf, 4, temperature);
    _mav_put_uint32_t(buf, 8, uptime_ms);
    _mav_put_uint8_t(buf, 12, health_state);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SYSTEM_EXTENSION_STATUS_LEN);
#else
    mavlink_system_extension_status_t packet;
    packet.cpu_load = cpu_load;
    packet.temperature = temperature;
    packet.uptime_ms = uptime_ms;
    packet.health_state = health_state;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SYSTEM_EXTENSION_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SYSTEM_EXTENSION_STATUS;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_SYSTEM_EXTENSION_STATUS_MIN_LEN, MAVLINK_MSG_ID_SYSTEM_EXTENSION_STATUS_LEN, MAVLINK_MSG_ID_SYSTEM_EXTENSION_STATUS_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_SYSTEM_EXTENSION_STATUS_MIN_LEN, MAVLINK_MSG_ID_SYSTEM_EXTENSION_STATUS_LEN);
#endif
}

/**
 * @brief Pack a system_extension_status message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param cpu_load  
 * @param temperature  
 * @param health_state  
 * @param uptime_ms  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_system_extension_status_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   float cpu_load,float temperature,uint8_t health_state,uint32_t uptime_ms)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SYSTEM_EXTENSION_STATUS_LEN];
    _mav_put_float(buf, 0, cpu_load);
    _mav_put_float(buf, 4, temperature);
    _mav_put_uint32_t(buf, 8, uptime_ms);
    _mav_put_uint8_t(buf, 12, health_state);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SYSTEM_EXTENSION_STATUS_LEN);
#else
    mavlink_system_extension_status_t packet;
    packet.cpu_load = cpu_load;
    packet.temperature = temperature;
    packet.uptime_ms = uptime_ms;
    packet.health_state = health_state;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SYSTEM_EXTENSION_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SYSTEM_EXTENSION_STATUS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SYSTEM_EXTENSION_STATUS_MIN_LEN, MAVLINK_MSG_ID_SYSTEM_EXTENSION_STATUS_LEN, MAVLINK_MSG_ID_SYSTEM_EXTENSION_STATUS_CRC);
}

/**
 * @brief Encode a system_extension_status struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param system_extension_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_system_extension_status_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_system_extension_status_t* system_extension_status)
{
    return mavlink_msg_system_extension_status_pack(system_id, component_id, msg, system_extension_status->cpu_load, system_extension_status->temperature, system_extension_status->health_state, system_extension_status->uptime_ms);
}

/**
 * @brief Encode a system_extension_status struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param system_extension_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_system_extension_status_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_system_extension_status_t* system_extension_status)
{
    return mavlink_msg_system_extension_status_pack_chan(system_id, component_id, chan, msg, system_extension_status->cpu_load, system_extension_status->temperature, system_extension_status->health_state, system_extension_status->uptime_ms);
}

/**
 * @brief Encode a system_extension_status struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param system_extension_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_system_extension_status_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_system_extension_status_t* system_extension_status)
{
    return mavlink_msg_system_extension_status_pack_status(system_id, component_id, _status, msg,  system_extension_status->cpu_load, system_extension_status->temperature, system_extension_status->health_state, system_extension_status->uptime_ms);
}

/**
 * @brief Send a system_extension_status message
 * @param chan MAVLink channel to send the message
 *
 * @param cpu_load  
 * @param temperature  
 * @param health_state  
 * @param uptime_ms  
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_system_extension_status_send(mavlink_channel_t chan, float cpu_load, float temperature, uint8_t health_state, uint32_t uptime_ms)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SYSTEM_EXTENSION_STATUS_LEN];
    _mav_put_float(buf, 0, cpu_load);
    _mav_put_float(buf, 4, temperature);
    _mav_put_uint32_t(buf, 8, uptime_ms);
    _mav_put_uint8_t(buf, 12, health_state);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SYSTEM_EXTENSION_STATUS, buf, MAVLINK_MSG_ID_SYSTEM_EXTENSION_STATUS_MIN_LEN, MAVLINK_MSG_ID_SYSTEM_EXTENSION_STATUS_LEN, MAVLINK_MSG_ID_SYSTEM_EXTENSION_STATUS_CRC);
#else
    mavlink_system_extension_status_t packet;
    packet.cpu_load = cpu_load;
    packet.temperature = temperature;
    packet.uptime_ms = uptime_ms;
    packet.health_state = health_state;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SYSTEM_EXTENSION_STATUS, (const char *)&packet, MAVLINK_MSG_ID_SYSTEM_EXTENSION_STATUS_MIN_LEN, MAVLINK_MSG_ID_SYSTEM_EXTENSION_STATUS_LEN, MAVLINK_MSG_ID_SYSTEM_EXTENSION_STATUS_CRC);
#endif
}

/**
 * @brief Send a system_extension_status message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_system_extension_status_send_struct(mavlink_channel_t chan, const mavlink_system_extension_status_t* system_extension_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_system_extension_status_send(chan, system_extension_status->cpu_load, system_extension_status->temperature, system_extension_status->health_state, system_extension_status->uptime_ms);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SYSTEM_EXTENSION_STATUS, (const char *)system_extension_status, MAVLINK_MSG_ID_SYSTEM_EXTENSION_STATUS_MIN_LEN, MAVLINK_MSG_ID_SYSTEM_EXTENSION_STATUS_LEN, MAVLINK_MSG_ID_SYSTEM_EXTENSION_STATUS_CRC);
#endif
}

#if MAVLINK_MSG_ID_SYSTEM_EXTENSION_STATUS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by reusing
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_system_extension_status_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  float cpu_load, float temperature, uint8_t health_state, uint32_t uptime_ms)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, cpu_load);
    _mav_put_float(buf, 4, temperature);
    _mav_put_uint32_t(buf, 8, uptime_ms);
    _mav_put_uint8_t(buf, 12, health_state);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SYSTEM_EXTENSION_STATUS, buf, MAVLINK_MSG_ID_SYSTEM_EXTENSION_STATUS_MIN_LEN, MAVLINK_MSG_ID_SYSTEM_EXTENSION_STATUS_LEN, MAVLINK_MSG_ID_SYSTEM_EXTENSION_STATUS_CRC);
#else
    mavlink_system_extension_status_t *packet = (mavlink_system_extension_status_t *)msgbuf;
    packet->cpu_load = cpu_load;
    packet->temperature = temperature;
    packet->uptime_ms = uptime_ms;
    packet->health_state = health_state;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SYSTEM_EXTENSION_STATUS, (const char *)packet, MAVLINK_MSG_ID_SYSTEM_EXTENSION_STATUS_MIN_LEN, MAVLINK_MSG_ID_SYSTEM_EXTENSION_STATUS_LEN, MAVLINK_MSG_ID_SYSTEM_EXTENSION_STATUS_CRC);
#endif
}
#endif

#endif

// MESSAGE SYSTEM_EXTENSION_STATUS UNPACKING


/**
 * @brief Get field cpu_load from system_extension_status message
 *
 * @return  
 */
static inline float mavlink_msg_system_extension_status_get_cpu_load(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field temperature from system_extension_status message
 *
 * @return  
 */
static inline float mavlink_msg_system_extension_status_get_temperature(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field health_state from system_extension_status message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_system_extension_status_get_health_state(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  12);
}

/**
 * @brief Get field uptime_ms from system_extension_status message
 *
 * @return  
 */
static inline uint32_t mavlink_msg_system_extension_status_get_uptime_ms(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  8);
}

/**
 * @brief Decode a system_extension_status message into a struct
 *
 * @param msg The message to decode
 * @param system_extension_status C-struct to decode the message contents into
 */
static inline void mavlink_msg_system_extension_status_decode(const mavlink_message_t* msg, mavlink_system_extension_status_t* system_extension_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    system_extension_status->cpu_load = mavlink_msg_system_extension_status_get_cpu_load(msg);
    system_extension_status->temperature = mavlink_msg_system_extension_status_get_temperature(msg);
    system_extension_status->uptime_ms = mavlink_msg_system_extension_status_get_uptime_ms(msg);
    system_extension_status->health_state = mavlink_msg_system_extension_status_get_health_state(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_SYSTEM_EXTENSION_STATUS_LEN? msg->len : MAVLINK_MSG_ID_SYSTEM_EXTENSION_STATUS_LEN;
        memset(system_extension_status, 0, MAVLINK_MSG_ID_SYSTEM_EXTENSION_STATUS_LEN);
    memcpy(system_extension_status, _MAV_PAYLOAD(msg), len);
#endif
}
