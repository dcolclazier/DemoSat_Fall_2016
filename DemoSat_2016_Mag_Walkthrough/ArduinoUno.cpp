#include "ArduinoUno.h"
#include "EventHandler.h"
#include "MagnetometerUpdate.h"
#include "TestingTesting.h"
//Implementation of ArduinoUno.h

//constructor - initializes private fields
ArduinoUno::ArduinoUno(): _magUpdate(nullptr), _tester(nullptr) { }


//destructor
ArduinoUno::~ArduinoUno()
{
	delete _magUpdate;
	delete _tester;
	delete _altUpdate;

}


//Starts up the BNO055, creates our eventActions
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
	_magUpdate = new MagnetometerUpdate(_bnoSensor);
	EventHandler::instance().add_eventAction("1s", _magUpdate);

	//create our altitude update action and add altitude update action to the 1second event.
	_altUpdate = new AltitudeUpdate(_bmpSensor);
	EventHandler::instance().add_eventAction("1s", _altUpdate);

	//create our magnetometer testing action
	_tester = new TestingTesting();

	//add our magnetometer testing action to the "MagUpdate" event
	// (the "MagUpdate" event was created by the MagnetometerUpdate 
	// action when it was created)
	EventHandler::instance().add_eventAction("AltUpdate", _tester);
}
