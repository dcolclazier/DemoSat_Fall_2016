#pragma once
#include "WString.h"
#include "vector.h"

//We don't need to #include "EventData" or #include "EventAction" or #include "Event" because the only
//reference to the Event, EventData or EventAction class in this file is via a pointer. A pointer only
//requires a forward declaration of the class, which is what line 6 is.
class EventData;
class Event;
class EventAction;

//This class Handles the execution and existence of "Events" in our program. To use an event,
//we need to add it to the event manager using "add_event". If we want to add an "action" to a particular
//event, we simply do so with "add_eventAction" - passing in the name of the event and an instance of the 
//"action" we want executed.
class EventHandler
{
public:
	//This is fancy syntax that defines this class as a "Singleton" class - google "Singleton" for more info!
	static EventHandler& instance()
	{
		static EventHandler me;
		return me;
	}

	//This adds an event to the event manager, allowing it to be triggered.
	void add_event(const String& event_name);

	//This adds an action to a particular event, such that it executes when the event is triggered.
	void add_eventAction(const String& event_name, EventAction* action);

	//This returns true if the event_name has been added to the event manager.
	bool contains(const String& event_name) const;

	//This retreives an event by name
	Event* get(const String& event_name);

	//This triggers an event by name, and sends a pointer to some EventData along with it
	void trigger(const String& name, EventData* data);
	
	//This triggers an event by name (an event that doesn't have any data associated with it)
	void trigger(const String& event_name);
	 
private:
	//We make our constructor, copy constructor, and assignment operator private - part of what makes this class a Singleton
	//We can't instantiate this class anywhere than other than in this class, which guarantees it only gets instantiated once (inside instance())
	EventHandler() 	{}
	EventHandler(EventHandler const&);
	void operator=(EventHandler const&);

	//A list of events that the event manager is aware of.
	vector<Event*> _eventList;
};


