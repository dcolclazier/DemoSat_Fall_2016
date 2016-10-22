#pragma once
#include "vector.h"
#include <WString.h>


//We don't need to #include "EventData" or #include "EventAction" because the only
//reference to the EventData or EventAction class in this file is via a pointer. A pointer only
//requires a forward declaration of the class, which is what line 6 is.
class EventAction;
class EventData;

//What's an event? You might think the big-bang was, and you'd be right.... Anything can be an event! It's the occurance 
//of "something" that we want to listen for in our code, such that when it occurs, other pieces of code execute... We can 
//"subscribe" "actions" to our events, such that when the event occurs, the actions are executed... 
class Event
{
public:
	//Constructor - initializes our private field (the name) through an "initialization list" - syntactic sugar in c++.
	explicit Event(const String& cs) : _name(cs) {}

	//A "getter" for the _name private field - is marked const so we guarantee it never changes the name.
	String name() const { return _name; }

	//This triggers the event, executing all actions that have been added to it.
	void trigger(EventData* data);

	//This adds an action to the event, such that the action is executed when the event triggers.
	void add_action(EventAction* actionToAdd);

private:
	//The name of the event
	String _name;

	//A list of all actions that execute when the event triggers.
	vector<EventAction*> _actionList;
};

