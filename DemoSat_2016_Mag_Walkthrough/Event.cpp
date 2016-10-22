#include "Event.h"
#include "EventAction.h"
//Implementation of "Event.h"

//loops through all of the actions assigned to this event and runs the execute method,
//passing along the EventData for the event.
void Event::trigger(EventData* data) {
	for (auto i = 0; i < _actionList.size(); i++) 	{
		_actionList[i]->execute(data);
	}
}

//Adds an action to the list, as long as the action hasn't been added before.
void Event::add_action(EventAction* actionToAdd) {
	if (_actionList.contains(actionToAdd)) return;

	_actionList.push_back(actionToAdd);
}
