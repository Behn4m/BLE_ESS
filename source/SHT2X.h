#ifndef SHT2X_H
#define SHT2X_H

/*
 * Constants used in communication
 *
 * Refer to datasheet for full explanation
 */ 
 
//Sensor I2C address
#define SHT_I2C_ADDR        0x80

//Commands...
//Trigger Temp with hold master
#define SHT_TRIG_TEMP_HOLD  0xE3
//Trigger RH with hold master
#define SHT_TRIG_RH_HOLD    0xE5
//Trigger Temp with no hold master
#define SHT_TRIG_TEMP       0xF3
//Trigger RH with no hold master
#define SHT_TRIG_RH         0xF5
//Write to user register
#define SHT_WRITE_REG       0xE6
//Read from user register
#define SHT_READ_REG        0xE7
//Soft reset the sensor
#define SHT_SOFT_RESET      0xFE

//User Register information

//Data precision settings
//RH 12 T 14 - default
#define SHT_PREC_1214       0x00
//RH 8  T 10 
#define SHT_PREC_0812       0x01
//RH 10 T 13
#define SHT_PREC_1013       0x80
//RH 11 T 11
#define SHT_PREC_1111       0x81

//Battery status
#define SHT_BATTERY_STAT    0x40
//Enable on chip heater
#define SHT_HEATER          0x04
//Disable OTP reload
#define SHT_DISABLE_OTP     0x02


//Fail conditions on the I2C bus
#define SHT_FAIL            1
#define SHT_SUCCESS         0

//Author fail conditions
//1, 2, 3 can be used because these are status bits
//in the received measurement value
#define SHT_GOOD            0xFFFC
#define SHT_TRIG_FAIL       1
#define SHT_READ_FAIL       2

#include "mbed.h"


class SHT2X {
    public:
        SHT2X();
        int readData(int16_t *tempC, int16_t *relHumidty);
        int measureTemperature(int16_t *tempC);
        int measureHumidty(int16_t *relHumidty);
        int setPrecision(char precision);
        bool softRest();
    protected:
        I2C m_i2c;
    private:
    
};

#endif