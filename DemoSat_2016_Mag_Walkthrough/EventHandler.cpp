#include "EventHandler.h"
#include "Event.h"
//adds an event to the list of events (must include a name with the event!)
//will not add the event if it already exists...
void EventHandler::add_event(const String& event_name)
{
	auto eventToAdd = new Event(event_name);
	if (contains(event_name)) return;

	_eventList.push_back(eventToAdd);
}

//adds an action to an event (only if the event exists)
void EventHandler::add_eventAction(const String& event_name, EventAction* action)
{
	if (!contains(event_name)) return;
	get(event_name)->add_action(action);
}

//retreives an event from the list... returns null if event doesn't exist.
Event* EventHandler::get(const String& event_name)
{
	for (auto i = 0; i < _eventList.size(); i++) {
		if (_eventList[i]->name() == event_name) return _eventList[i];
	}
	return nullptr;
}
// returns true if the list contains a particular event.
bool EventHandler::contains(const String& event_name) const
{
	for (auto i = 0; i < _eventList.size(); i++) {
		if (_eventList[i]->name() == event_name) return true;
	}
	return false;
}
//triggers the event, and sends a reference to some EventData along with the trigger.
void EventHandler::trigger(const String& event_name, EventData* data)
{
	if (!contains(event_name)) return;
	get(event_name)->trigger(data);
}

//triggers an event and sends a nullptr along as EventData (none required)
void EventHandler::trigger(const String& event_name)
{
	if (!contains(event_name)) return;
	get(event_name)->trigger(nullptr);
}




