#ifndef _SENSOR_SUHU_
#define _SENSOR_SUHU_

#include <SparkFunMLX90614.h>

class SensorSuhu {
  private:
    IRTherm* _therm;
  public:
    SensorSuhu(IRTherm* therm) {
      Wire.begin();
      _therm = therm;
      if (_therm->begin() == false) {
        Serial.println("Qwiic IR thermometer did not acknowledge!");
      }
      Serial.println("Qwiic IR Thermometer did acknowledge.");
      therm->setUnit(TEMP_C);
    }
    
    double getObjectTemperature() {
      if (_therm->read()) {
        return _therm->object();
      } else {
        return 0.0;
      }
    }
};

#endif _SENSOR_SUHU_
