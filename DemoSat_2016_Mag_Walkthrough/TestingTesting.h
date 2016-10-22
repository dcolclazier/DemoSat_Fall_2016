#pragma once
#include "EventAction.h"

//Forward declaration of EventData class (needed because we used an EventData pointer)
class EventData;

//Another Event Action... This Action responds to the "MagUpdate" event
//and simply prints the magnetometer data from the BNO055 to the serial window.
class TestingTesting : public EventAction
{
public:

	//Contains the code that executes when the event this action is tied to gets triggered.
	void execute(EventData* data) override;

};

