#pragma once
#include <Adafruit_BNO055.h>
#include "EventAction.h"
#include "Time.h"


class MagnetometerUpdate : public EventAction
{
public:
	//constructor takes in a reference to the BNO055 sensor
	MagnetometerUpdate(const Adafruit_BNO055& bno);

	//This method overrides the virtual method "execute" in the EventAction class.
	//Because "execute" in EventAction is "pure virtual," it MUST be declared in this 
	//base class "Magnetometer Update." This code runs when whatever event this
	//action is tied to is triggered.
	void execute(EventData* data) override;

private:
	//a reference to the BNO055 sensor
	Adafruit_BNO055 _bno;
};
