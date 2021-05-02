/*-------------------------------------
CSIT314 Project Part B - Queueing system under test

Group Leader Name: Andrew Bentley
Subject: CSIT314
Computer Lab: CL/05 Thu 15:30
Assessment Item: Project Part B - System Under Test
File: Event.h

Code taken from CSCI203 Assignment 2 Submission,
Spring 2019 by Andrew Bentley
Created: 11/9/2019 15:06

Code updated for CSIT314 Project Part B - Queueing system Under Test
Autumn 2021 by Andrew Bentley
Updated: 3/5/2021 00:09
-------------------------------------*/

#pragma once

#ifndef AJB24_EVENT_H
#define AJB24_EVENT_H

#include "Customer.h"
#include "Server.h"

class Event
{
private:

	enum { customerArrival, serverFinish, other };

	int type;
	double eventTime;
	Customer* eventCustomer;
	Server* eventServer;

	static const double CASH_PAYMENT_TIME;
	static const double CARD_PAYMENT_TIME;

public:
	Event();
	Event(Customer* eventCustomer);
	Event(Event* customerArrivalEvent, Server* eventServer);

	void setEventTime(double eventTime);
	void setCustomer(Customer* eventCustomer);
	void setServer(Server* eventServer);

	double getEventTime();
	Customer* getCustomer();
	Server* getServer();

	void display();

	bool isCustomerArrival();
	bool isServerFinish();

};

#endif
