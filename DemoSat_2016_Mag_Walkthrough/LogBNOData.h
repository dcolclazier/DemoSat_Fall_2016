#pragma once
#include <Adafruit_BMP085_U.h>
#include "EventAction.h"
#include "Logger.h"

class Adafruit_BNO055;
class EventData;

class LogBNOData : public EventAction
{

public:
	void execute(EventData* data) override;


	explicit LogBNOData(Logger* logger)
		: _logger(logger)
	{
	}

private:
	Adafruit_BMP085_Unified _bmp;
	Logger* _logger;
};
