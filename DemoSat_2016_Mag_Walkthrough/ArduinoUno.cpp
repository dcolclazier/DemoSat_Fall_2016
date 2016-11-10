#include "ArduinoUno.h"
#include "EventHandler.h"
#include "BNO100Update.h"
#include "LogBNOData.h"
#include "LogBMPData.h"

//Implementation of ArduinoUno.h

//constructor - initializes private fields
ArduinoUno::ArduinoUno(): _logger(new Logger()), _bnoUpdate(nullptr), 
					_altUpdate(nullptr), _bnoLogger(nullptr), _bmpLogger(nullptr)
{ }


//destructor
ArduinoUno::~ArduinoUno()
{
	delete _bnoUpdate;
	delete _altUpdate;
	delete _bnoLogger;
	delete _bmpLogger;
}


//Starts up the BNO055, creates our eventActions, create logging actions
void ArduinoUno::begin()
{
	//start up the BNO055..
	if (!_bnoSensor.begin())
	{
		Serial.print("No BNO detected...");
		while (1); //performs if check again.
	}
	//start up the BMP180..
	if (!_bmpSensor.begin())
	{
		Serial.print("No BMP detected...");
		while (1); //performs if check again.
	}
	delay(1000);
	_bnoSensor.setExtCrystalUse(true);

	//create our magnetometer update action and add magnetometer update action to the 1second event.
	_bnoUpdate = new BNO100Update(_bnoSensor);
	EventHandler::instance().add_eventAction("1s", _bnoUpdate);

	//create our altitude update action and add altitude update action to the 1second event.
	_altUpdate = new AltitudeUpdate(_bmpSensor);
	EventHandler::instance().add_eventAction("1s", _altUpdate);

	//create our logging actions
	//_bnoLogger = new LogBNOData(_logger);
	//EventHandler::instance().add_eventAction("BNOUpdate", _bnoLogger);

	_bmpLogger = new LogBMPData(_logger);
	EventHandler::instance().add_eventAction("AltUpdate", _bmpLogger);

	
}
