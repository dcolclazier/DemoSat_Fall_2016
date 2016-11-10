#include "LogBNOData.h"
#include "BNOData.h"

void LogBNOData::execute(EventData* data)
{
	auto bnoData = static_cast<BNOData*>(data);
	if (!bnoData) return;

	//Log BNOData
	String LogString = "";
	LogString += "B";
	LogString += bnoData->gyrox;
	LogString += ";";
	LogString += bnoData->gyroy;
	LogString += ";";
	LogString += bnoData->gyroz;
	LogString += "\\";

	LogString += bnoData->accX;
	LogString += ";";
	LogString += bnoData->accY;
	LogString += ";";
	LogString += bnoData->accZ;
	LogString += ";";

	LogString += bnoData->orientX;
	LogString += "\\";
	LogString += bnoData->orientY;
	LogString += "\\";
	LogString += bnoData->orientZ;
	LogString += "\\";
	LogString += bnoData->temp;

	//BUG _ INTEGRATE INTO LOGGER
	
	_logger->addToBuffer(LogString);
	
}
