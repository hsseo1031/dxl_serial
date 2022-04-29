#ifndef DXL_SERIAL_H
#define DXL_SERIAL_H

#include "ros/ros.h"
#include "std_msgs/String.h"

// C library headers
#include <stdio.h>
#include <string.h>

// Linux headers
#include <fcntl.h> // Contains file controls like O_RDWR
#include <errno.h> // Error integer and strerror() function
#include <termios.h> // Contains POSIX terminal control definitions
#include <unistd.h> // write(), read(), close()

// typedef unsigned char TYPE;

class dxl_serial_node{
protected:
    unsigned char H1 = 0xFF;
    unsigned char H2 = 0xFF;
    unsigned char H3 = 0xFD; 
    unsigned char RSRV = 0x00;

public:
    int motor_id;
    int baudrate;
    int serial_port;
    unsigned int encorder;

    unsigned char CRC_L;
    unsigned char CRC_H;
    unsigned short CRC;
    
    unsigned char buffer_data;

    int setting(int baudrate);

    unsigned char read_buffer(int serial_port);
    void Torque_On();

    void position1(unsigned int encorder);
    void position2();
    unsigned short update_crc(unsigned char *TxPacket, unsigned short data_blk_size);
};

#endif // DXL_SERIAL_H