#include <stdio.h>
#include <stdint.h>
// #include <iostream>

typedef struct
{
    /* data */
    uint8_t crc; // 2 bits
    uint8_t status; // 1 bit
    uint16_t payload; // 12 bits
    uint8_t bat; // 3 bits
    uint8_t sensor; // 3 bits 
    uint8_t longAddr; // 8 bits long
    uint8_t shortAddr; // 2 bits short
    uint8_t addrMode; // 1 bit char
} Packet_t;


void print_binary(unsigned int number);

int main(void)
{

    Packet_t packet;

    // asks for 32 bit packet value;
    // ex: 0x03FF1234

    printf("Enter a 32 bit packet value:\n0x");
    uint32_t packet_input;
    scanf("%X", &packet_input);

    packet.crc = (uint8_t)(packet_input & 0x3); // first 2 bits
    packet.status = (uint8_t)((packet_input >> 2) & 0x1); // 3rd bit
    packet.payload = (uint16_t)((packet_input >> 3) & 0xFFF); // next 12 bits
    packet.bat = (uint8_t)((packet_input >> 15) & 0x7); // next 3 bits
    packet.sensor = (uint8_t)((packet_input >> 18) & 0x7); // next 3 bits
    packet.longAddr = (uint8_t)((packet_input >> 21) & 0xFF); // next 8 bits
    packet.shortAddr = (uint8_t)((packet_input >> 29) & 0x3); // next 2 bits
    packet.addrMode = (uint8_t)((packet_input >> 31) & 0x1); // last bit


    // uint32_t totalSize = sizeof(Packet_t);
    // Packet_t* pPacket = &packet;

    // for(int i = 0; i < totalSize; i++) {
    //     printf("%X\n", *pPacket);
    //     pPacket++;
    // }

    // 0xFFD37F76
    
    printf("\npacket.crc = %#x\n", packet.crc);
    printf("binary = ");
    print_binary(packet.crc);

    printf("\npacket.status = %#x\n", packet.status);
    printf("binary = ");
    print_binary(packet.status);

    printf("\npacket.payload = %#x\n", packet.payload);
    printf("binary = ");
    print_binary(packet.payload);

    printf("\npacket.bat = %#x\n", packet.bat);
    printf("binary = ");
    print_binary(packet.bat);

    printf("\npacket.sensor = %#x\n", packet.sensor);
    printf("binary = ");
    print_binary(packet.sensor);

    printf("\npacket.longAddr = %#x\n", packet.longAddr);
    printf("binary = ");
    print_binary(packet.longAddr);

    printf("\npacket.shortAddr = %#x\n", packet.shortAddr);
    printf("binary = ");
    print_binary(packet.shortAddr);

    printf("\npacket.addrMode = %#x\n", packet.addrMode);
    printf("binary = ");
    print_binary(packet.addrMode);
    printf("\n");

    return 0;
}

void print_binary(unsigned int number)
{
    if (number >> 1) {
        print_binary(number >> 1);
    }
    putc((number & 1) ? '1' : '0', stdout);
}