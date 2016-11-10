#pragma once
#include "EventData.h"
//BNO055 Magnetometer EventData - contains the x,y,z components of the magnetometer as well as the internal temp of the sensor.
struct BNOData : EventData {
	
	float magx;
	float magy;
	float magz;

	float gyrox;
	float gyroy;
	float gyroz;
	
	float accX;
	float accY;
	float accZ;

	float orientX;
	float orientY;
	float orientZ;

	int temp;
};
