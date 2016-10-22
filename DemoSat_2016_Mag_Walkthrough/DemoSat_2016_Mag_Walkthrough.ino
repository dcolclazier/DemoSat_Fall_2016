#include <Adafruit_BMP085_U.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include "Arduino.h"
#include "EventHandler.h"
#include "EventAction.h"
#include "EventData.h"
#include "Time.h"
#include "ArduinoUno.h"
/*
 name:		DemoSat_2016_Mag_Walkthrough.ino
 Created:	9/30/2016 7:22:48 PM
 Author:	DemoSat Software Team
*/

void setup() {
	Serial.begin(115200);

	//initialize all time events here.
	EventHandler::instance().add_event("1s");


	//initializes all our sensors, which initialize their own events.
	//also initializes all of our event actions.
	static ArduinoUno mainBoard;
	mainBoard.begin();
}

//these need to be global to be accessed by loop without resetting each loop run...
int _prevTime = 0;
Time RunTime;

// the loop function runs over and over again until power down or reset
void loop() {

	int currentTime = millis() / 100; // .1 seconds
	if (currentTime - _prevTime < 1) return; //only run loop every .1s
	
	RunTime.Tenths++; //.1s has passed.
	
	if(RunTime.Tenths == 10) //1 second has passed.
	{
		RunTime.Seconds++; //increment seconds... reset tenths.
		RunTime.Tenths = 0;
		EventHandler::instance().trigger("1s"); //trigger the 1second event

		if(RunTime.Seconds == 60) //1 minute has passed.
		{
			RunTime.Seconds = 0; //increment minutes... reset seconds.
			RunTime.Minutes++;
			if(RunTime.Minutes == 60) //1 hour has passed.
			{
				RunTime.Minutes = 0; //increment hours... reset minutes.
				RunTime.Hours++;
			}
		}
	}
	//how long the loop took to run
	int loopExecutionTime = millis() / 100 - currentTime; 

	//update time for clock
	_prevTime = currentTime + loopExecutionTime;
	
}