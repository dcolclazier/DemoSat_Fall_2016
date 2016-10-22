#pragma once
#include <Adafruit_BMP085_U.h>
#include <Adafruit_BNO055.h>
#include "AltitudeUpdate.h"

class MagnetometerUpdate;
class TestingTesting;

class ArduinoUno
{
public:
	
	ArduinoUno();
	~ArduinoUno();

	void begin();
private:

	//arduino sensors
	Adafruit_BNO055 _bnoSensor;
	Adafruit_BMP085_Unified _bmpSensor;
	

	//event actions
	MagnetometerUpdate* _magUpdate;
	AltitudeUpdate* _altUpdate;
	TestingTesting* _tester;
	
};
