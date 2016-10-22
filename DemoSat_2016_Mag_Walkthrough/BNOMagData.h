#pragma once
#include "EventData.h"
//BNO055 Magnetometer EventData - contains the x,y,z components of the magnetometer as well as the internal temp of the sensor.
struct BNOMagData : EventData {
	float x;
	float y;
	float z;
	int temp;
};
