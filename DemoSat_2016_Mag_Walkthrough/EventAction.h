#pragma once

//We don't need to #include "EventData" because the only
//reference to EventData in this file is a pointer. A pointer only
//requires a forward declaration of the class, which is what line 6 is.
class EventData;

//Interface for event actions - every event action subscribes to
//this interface, and must implement the execute method to avoid compiler errors.
//In this way, an "Interface" (java term) acts like a contract for future
//event actions to ensure they work correctly with existing code without
//introducing logic errors when a programmer forgets something.
class EventAction
{
public:
	//this contains the executable code for the action.
	virtual void execute(EventData* data) = 0;
	virtual ~EventAction() {}
};
