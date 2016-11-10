#include "LogBMPData.h"
#include "BMPAltData.h"
#include <HardwareSerial.h>

void LogBMPData::execute(EventData* data)
{
	auto altitudeData = static_cast<BMPAltData*>(data);
	if (!altitudeData) return;
	

	String test = "A";
	test += (altitudeData->altitude);

	/*Serial.print("A");
	Serial.println(altitudeData->altitude);*/

	_logger->addToBuffer(test);
}
