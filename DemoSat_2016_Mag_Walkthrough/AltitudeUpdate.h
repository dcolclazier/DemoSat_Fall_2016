#pragma once
#include "EventAction.h"
#include <Adafruit_BMP085_U.h>
#include <Adafruit_BNO055.h>

class AltitudeUpdate : public EventAction 
{

public:

	AltitudeUpdate(const Adafruit_BMP085_Unified& bmp);
	void execute(EventData* data) override;
private:
	Adafruit_BMP085_Unified _bmp;
};





