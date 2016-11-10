#include "AltitudeUpdate.h"
#include "EventHandler.h"
#include "BMPAltData.h"
#include <Adafruit_BMP085_U.h>
#include "BNOData.h"

AltitudeUpdate::AltitudeUpdate(const Adafruit_BMP085_Unified& bmp) :_bmp(bmp)
{
	//adds event Altitude Update
	EventHandler::instance().add_event("AltUpdate");
}

void AltitudeUpdate::execute(EventData* data)
{

	//This line's seaLevelPressure needs to be in terms of HPa for your current location.
	//Ensure that this is correct for your location
	auto seaLevelPressure = 1014.8500326800001;
	auto pressure = 0.0f;
	
	auto altData = BMPAltData();
	//This pulls the pressure value
	_bmp.getPressure(&pressure);
	//This determines the altitude in terms of atmospheric pressure and
	//saves this data for the Altitude Data and waits for the event
	altData.altitude = _bmp.pressureToAltitude(seaLevelPressure, pressure/100);

	//Trigger the event AltUpdate so that other things can act accordingly (like logging the data)
	EventHandler::instance().trigger("AltUpdate", &altData);
}


