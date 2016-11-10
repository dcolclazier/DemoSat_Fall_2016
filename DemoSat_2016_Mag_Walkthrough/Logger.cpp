#include "Logger.h"
#include "Time.h"

extern Time RunTime;

void Logger::flush(const String& bufferToFlush) 
{
	Serial.print(bufferToFlush);
}
void Logger::flush() 
{
	
}

void Logger::addToBuffer(const String& stuffToAdd)
{
	delay(10);
	//Serial.println(stuffToAdd);
	_buffer.enqueue(stuffToAdd);
	_bufferSize += stuffToAdd.length();
	Serial.println(_bufferSize);
	if (_bufferSize > 512) {
		String s = "";
		while (s.length() < 512)
		{
			auto thing = _buffer.pop();
			_bufferSize -= thing.length();
			s += thing;
		}
		Serial.print(s);
	}
	
	/*auto test = stuffToAdd.c_str();
	for(auto i = 0; i < stuffToAdd.length(); i++)
		addCharToBuffer(test[i]);*/
}

Logger::Logger()
{
	
		//initialize the OpenLog with whatever code we need.
		Serial.print("Log initiated at ");
		Serial.print(RunTime.Hours);
		Serial.print(":");
		Serial.print(RunTime.Minutes);
		Serial.print(":");
		Serial.println(RunTime.Seconds);
		
}

