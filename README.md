# MAVLink Custom Message Project (C++)

This project demonstrates how to:

- Add MAVLink as a git submodule
- Create a custom MAVLink message
- Generate MAVLink C headers from XML
- Encode and decode the custom message using C++

## Custom Message

Message name: SYSTEM_EXTENSION_STATUS  
Message ID: 42000

Defined in:
custom_messages/system_extension.xml

## Generate MAVLink Headers

```bash
python3.11 mavlink/pymavlink/tools/mavgen.py --lang=C --wire-protocol=2.0 --output=generated_custom custom_messages/system_extension.xml

g++ src/main.cpp -I generated_custom -o test_custom
./test_custom

