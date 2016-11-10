#pragma once
#include <Adafruit_BMP085_U.h>
#include <Adafruit_BNO055.h>
#include "AltitudeUpdate.h"
#include "Logger.h"
#include "LogBNOData.h"
#include "LogBMPData.h"

class BNO100Update;
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
	Logger* _logger;

	//event actions
	BNO100Update* _bnoUpdate;
	AltitudeUpdate* _altUpdate;
	LogBNOData* _bnoLogger;
	LogBMPData* _bmpLogger;
};
