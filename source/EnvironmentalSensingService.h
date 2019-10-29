/* mbed Microcontroller Library
 * Copyright (c) 2006-2013 ARM Limited
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __ENVIRONMENTALSENSING_TEMPERATURE_SERVICE_H__
#define __ENVIRONMENTALSENSING_TEMPERATURE_SERVICE_H__

class EnvironmentalSensingService {
public:
    const static uint16_t ES_SERVICE_UUID                       = 0x181a;
    const static uint16_t ES_Temperature_CHARACTERISTIC_UUID    = 0x2a6e;
    
    typedef int16_t  TemperatureType_t;
    typedef uint16_t HumidityType_t;
    typedef uint32_t PressureType_t;    

    EnvironmentalSensingService(BLE &_ble) :
        ble(_ble), 
        tempratureState(ES_Temperature_CHARACTERISTIC_UUID, &temprature)
    {
        GattCharacteristic *charTable[] = {&tempratureState};
        GattService         esService(EnvironmentalSensingService::ES_SERVICE_UUID, charTable, sizeof(charTable) / sizeof(GattCharacteristic *));
        ble.gattServer().addService(esService);
    }

    void updateTempratureState(float newTemperatureVal) {
        //ble.gattServer().write(tempratureState.getValueHandle(), (uint16_t *)&newState, sizeof(uint16_t), false);
        //temperature = (TemperatureType_t) (newTemperatureVal * 100);
        //ble.gattServer().write(tempratureState.getValueHandle(), (uint8_t *) &temperature, sizeof(TemperatureType_t));        
    }

private:
    BLE                                             &ble;
    ReadOnlyGattCharacteristic<HumidityType_t>      humidityCharacteristic;
    TemperatureType_t                               temperature;
};

#endif /* #ifndef __ENVIRONMENTALSENSING_TEMPERATURE_SERVICE_H__ */