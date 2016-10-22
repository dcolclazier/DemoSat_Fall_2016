#pragma once
#include <Adafruit_BNO055.h>

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

	//event actions
	MagnetometerUpdate* _magUpdate;
	TestingTesting* _tester;
	
};
