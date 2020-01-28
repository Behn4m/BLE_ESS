# BLE_ESS

This project is about to create a new service for Environment Sensing in Mbed platform on nRF52832 chip. I started project with a sample code provided for "BLE_Thermometer" in https://github.com/ARMmbed/mbed-os-example-ble

I used Mbed Studio and `mbed deploy` for adding Mbed to my project

## Creating new Service

**Step 1**: add the header file that defined your service parameters. for ES service I added:
`#include "ble/services/EnvironmentalService.h"`
you can find `EnvironmentalService.h"` in the `mbed-OS > features > FEATURES_BLE > ble` in project files.

**Step 2**: Update UUID with new `ES_SERVICE_UUID`

**Step 3**:define new BLE class I used `ES_Service` name for it
once should define it as a pointer

and then `new` in main code

**Step 4**: Add sensor driver files to project. I used this files to drive sensor, but I had to do some changes to main class to prevent errors (seems new version of Mbed-OS have some new rules to terminate defining to instance of one peripheral that this driver does not match to it)
https://os.mbed.com/teams/MtM/code/SHT2X/


**Step 5**: Create update functions
```
void UpdateTemperatureValue(void) {
        
        int16_t tempC;

        SHT20.measureTemperature(&tempC);
        _es_service->updateTemperature(tempC);
    }

    void UpdateHumidityValue(void) {
        
        int16_t relHumidty;
        SHT20.measureHumidty(&relHumidty);
        _es_service->updateHumidity(relHumidty);
    }```



