#pragma once
#include "EventAction.h"
#include "Logger.h"

class LogBMPData: public EventAction
{
public:


	explicit LogBMPData(Logger* logger)
		: _logger(logger)
	{
	}

	void execute(EventData* data) override;

private:
	Logger* _logger;
};
