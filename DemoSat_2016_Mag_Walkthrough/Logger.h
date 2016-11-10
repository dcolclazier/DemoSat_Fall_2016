#pragma once
#include "QueueArray.h"
#include "vector.h"


class Logger
{
private:
	QueueArray<String> _buffer;
	unsigned int _bufferSize = 0;
	void flush(const String& bufferToFlush);
	void flush();
public:
	
	void addToBuffer(const String& stuffToAdd);

	Logger();
};
