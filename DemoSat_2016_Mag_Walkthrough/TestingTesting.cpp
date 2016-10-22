#include "TestingTesting.h"
#include "BNOMagData.h"
#include "Arduino.h"
#include "BMPAltData.h"

void TestingTesting::execute(EventData* data)
{
	//we need to "cast" the EventData pointer into the actual event data it is... In other words, if EventData was a fruit,
	//												we need to "cast" the Fruit pointer into the apple pointer it actually is... 

	//Since we know the TestingTesting action responds to the "MagUpdate" event and none other, we
	//can guarantee that the EventData pointer points to BNOMagData (MagnetometerUpdate.cpp, line 20)
	//So we convert the EventData pointer to a BNOMagData pointer, so we can reach in and access the data inside.
	auto altitudeData = static_cast<BMPAltData*>(data);

	//If for some reason something went wrong and magData returned null, get out of here! This should never happen.
	if (!altitudeData) return;

	//reach into the magData and print it to the serial window.
	Serial.print("Altitude: ");
	Serial.println(altitudeData->altitude);
	
	
}
