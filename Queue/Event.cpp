/*-------------------------------------
CSIT314 Project Part B - Queueing system under test

Group Leader Name: Andrew Bentley
Subject: CSIT314
Computer Lab: CL/05 Thu 15:30
Assessment Item: Project Part B - System Under Test
File: Event.cpp

Code taken from CSCI203 Assignment 2 Submission,
Spring 2019 by Andrew Bentley
Created: 11/9/2019 15:06

Code updated for CSIT314 Project Part B - Queueing system Under Test
Autumn 2021 by Andrew Bentley
Updated: 3/5/2021 00:09
-------------------------------------*/

#include <iostream>

#include "Event.h"

// Event - Constructors
Event::Event()
{
	type = other;
	eventCustomer = nullptr;
	eventServer = nullptr;
	eventTime = -1;
}

// Constructor for creating customerArrival event
Event::Event(Customer* eventCustomer)
{
	type = customerArrival;
	this->eventCustomer = eventCustomer;
	eventServer = nullptr;
	this->eventTime = eventCustomer->getArrivalTime();
}

// Constructor for creating serverFinish event
Event::Event(Event* customerArrivalEvent, Server* eventServer)
{
	type = serverFinish;
	eventCustomer = customerArrivalEvent->getCustomer();
	this->eventServer = eventServer;

	// Calculate server finish time
	this->eventTime = customerArrivalEvent->getEventTime() +
		(eventCustomer->getTallyTime() *
			eventServer->getEfficiency());

	if (eventCustomer->getPaymentByCard())
	{
		this->eventTime += CARD_PAYMENT_TIME;
	}
	else
	{
		this->eventTime += CASH_PAYMENT_TIME;
	}


}

// Event - Mutators
void Event::setEventTime(double eventTime)
{
	this->eventTime = eventTime;
}


void Event::setCustomer(Customer* eventCustomer)
{
	this->eventCustomer = eventCustomer;
}

void Event::setServer(Server* eventServer)
{
	this->eventServer = eventServer;
}

// Event - accessors
double Event::getEventTime()
{
	return eventTime;
}

Customer* Event::getCustomer()
{
	return eventCustomer;
}

Server* Event::getServer()
{
	return eventServer;
}

void Event::display()
{
	if (type == customerArrival)
	{
		std::cout << "customerArrival:";
	}
	else if (type == serverFinish)
	{
		std::cout << "serverFinish:";
	}
	else
	{
		std::cout << "Other:";
	}

	std::cout << eventTime << ":";
	eventCustomer->display();
}

bool Event::isCustomerArrival()
{
	return type == customerArrival;
}

bool Event::isServerFinish()
{
	return type == serverFinish;
}