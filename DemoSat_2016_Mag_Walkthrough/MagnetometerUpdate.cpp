#include "MagnetometerUpdate.h"
#include "EventHandler.h"
#include "BNOMagData.h"

MagnetometerUpdate::MagnetometerUpdate(const Adafruit_BNO055& bno) : _bno(bno)
{
	EventHandler::instance().add_event("MagUpdate");
}

void MagnetometerUpdate::execute(EventData* data)
{
	auto magVector = _bno.getVector(Adafruit_BNO055::VECTOR_MAGNETOMETER);
	auto magData = BNOMagData();
	magData.x = magVector.x();
	magData.y = magVector.y();
	magData.z = magVector.z();
	magData.temp = _bno.getTemp();

	EventHandler::instance().trigger("MagUpdate", &magData);
}
