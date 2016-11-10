#include "BNO100Update.h"
#include "EventHandler.h"
#include "BNOData.h"

BNO100Update::BNO100Update(const Adafruit_BNO055& bno) : _bno(bno)
{
	EventHandler::instance().add_event("BNOUpdate");
}

void BNO100Update::execute(EventData* data)
{
	auto magVec = _bno.getVector(Adafruit_BNO055::VECTOR_MAGNETOMETER);
	auto gyroVec = _bno.getVector(Adafruit_BNO055::VECTOR_GYROSCOPE);
	auto accelVec = _bno.getVector(Adafruit_BNO055::VECTOR_ACCELEROMETER);
	auto magData = BNOData();
	//BUG - these are different collection frequencies.
	
	magData.magx = magVec.x();
	magData.magy = magVec.y();
	magData.magz = magVec.z();

	magData.gyrox = gyroVec.x();
	magData.gyroy = gyroVec.y();
	magData.gyroz = gyroVec.z();

	magData.accX = accelVec.x();
	magData.accY = accelVec.y();
	magData.accZ = accelVec.z();

	magData.orientX = accelVec.x();
	magData.orientY = accelVec.y();
	magData.orientZ = accelVec.z();

	//BUG - remove this to its own action.
	magData.temp = _bno.getTemp();



	EventHandler::instance().trigger("BNOUpdate", &magData);
}
