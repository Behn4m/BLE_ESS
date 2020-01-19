#include "SHT2X.h"
 
SHT2X::SHT2X() : m_i2c(P0_29, P0_28) {
}
 
int SHT2X::measureTemperature(int16_t *tempC) {
    char command;
    command = SHT_TRIG_TEMP;
    
    m_i2c.write(SHT_I2C_ADDR, &command, 1, false);
    
    wait_ms(100);
    
    char rx[3];
    int16_t temperature;
    
    m_i2c.read(SHT_I2C_ADDR, rx, 3, false);
    temperature = (rx[0]<<8 | rx[1]);
    temperature += ~0x0003;

    
//    m_pc.printf(" uint_temp %d \r\n", temperature);
    *tempC = -46.85 + (175.72 *  temperature) / 65536;
    
    return 0;    
}
 
int SHT2X::measureHumidty(int16_t *relHumidty) {
    char command;
    command = SHT_TRIG_RH;
    
    m_i2c.write(SHT_I2C_ADDR, &command, 1, false);
    
    wait_ms(100);
    
    char rx[3];
    int16_t humidity;
    
    m_i2c.read(SHT_I2C_ADDR, rx, 3, false);
    
    humidity = (rx[0]<<8) + rx[1];
    humidity += ~0x0003;
    
    *relHumidty = -6 + 125 * (humidity) / 65536;
    
    return 0;
    
}
 
int SHT2X::readData(int16_t *tempC, int16_t *relHumidty) {
    measureTemperature(tempC);
    wait_ms(100);
    measureHumidty(relHumidty);
    return 0;
}
 
int SHT2X::setPrecision(char precision) {
 
    char command[2];
    command[0] = SHT_WRITE_REG;
    command[1] = precision;
 
    return m_i2c.write(SHT_I2C_ADDR, command, 2, false);
    
}
 
bool SHT2X::softRest() {
    char command = SHT_SOFT_RESET;
    
    if (m_i2c.write(SHT_I2C_ADDR, &command, 1, false) != 0) {
        return false;
    }
    
    return true;
}