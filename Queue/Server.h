/*-------------------------------------
CSIT314 Project Part B - Queueing system under test

Group Leader Name: Andrew Bentley
Subject: CSIT314
Computer Lab: CL/05 Thu 15:30
Assessment Item: Project Part B - System Under Test
File: Server.h

Code taken from CSCI203 Assignment 2 Submission,
Spring 2019 by Andrew Bentley
Created: 11/9/2019 15:06

Code updated for CSIT314 Project Part B - Queueing system Under Test
Autumn 2021 by Andrew Bentley
Updated: 3/5/2021 00:09
-------------------------------------*/

#pragma once

#ifndef AJB24_SERVER_H
#define AJB24_SERVER_H

#include "Customer.h"

class Server
{
private:
	bool busy;
	double efficiency;
	int id;
	static int numServers;
	Customer* currentCustomer;

public:
	Server();
	Server(double efficiency);

	void setEfficiency(double efficiency);
	void setBusy(bool busy);
	void setId(int id);
	void setCurrentCustomer(Customer* currentCustomer);

	double getEfficiency();
	bool getBusy();
	int getId();
	Customer* getCurrentCustomer();

	void display();
};

#endif
