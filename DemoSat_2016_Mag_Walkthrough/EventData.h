#pragma once
//If an event has data associated with it, we package it up inside this class!

//This is the "interface" for any class that wants to hold data tied to an event. It's
//an example of "polymorphism" - we reference "EventData" pointers in our code that is generic to
// all event data, and then "cast" the "EventData" pointer into what it actually is when we need to access
// the specific Event Data... Because the only thing in this class is virtual, it marks the class as "abstract."
// "Abstract" classes cannot exist in your program (cannot be instantiated) - they must exist as a concrete class
// that "implements" this "interface" (Technically, it's just an abstract class... It functions identically to an interface in Java or C#.)
class EventData
{
public:
	virtual ~EventData() {}
};


