#include "EventData.h"

//A container to hold time data... we use "byte" here because we don't need 
//more than 255 values to hold all of our time data... In other words, 
//none of the values below will ever be greater than 255.
struct Time : EventData
{
	byte Hours;
	byte Minutes;
	byte Seconds;
	byte Tenths;
	byte Hundredths;

	Time(): Hours(0), Minutes(0), Seconds(0), Tenths(0), Hundredths(0)
	{
	}
};
