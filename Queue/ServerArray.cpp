/*-------------------------------------
CSIT314 Project Part B - Queueing system under test

Group Leader Name: Andrew Bentley
Subject: CSIT314
Computer Lab: CL/05 Thu 15:30
Assessment Item: Project Part B - System Under Test
File: ServerArray.cpp

Code taken from CSCI203 Assignment 2 Submission,
Spring 2019 by Andrew Bentley
Created: 11/9/2019 15:06

Code updated for CSIT314 Project Part B - Queueing system Under Test
Autumn 2021 by Andrew Bentley
Updated: 3/5/2021 00:09
-------------------------------------*/

#include "ServerArray.h"

// ServerArray - Constructors
ServerArray::ServerArray()
{
	numServers = 0;
	servers = nullptr;
}

ServerArray::~ServerArray()
{
	delete servers;
}

// ServerArray - Mutators
void ServerArray::buildArray(File* dataFile)
{
	numServers = dataFile->readServerCount();
	servers = new Server * [numServers];

	for (int i = 0; i < numServers; i++)
	{
		Server* s = dataFile->readNextServer();
		servers[i] = s;
	}

}

Server* ServerArray::getBestServer()
{
	Server* retval = nullptr;
	double bestEfficiency = 0.0;

	for (int i = 0; i < numServers; i++)
	{
		if (servers[i]->getEfficiency() > bestEfficiency)
		{
			retval = servers[i];
			bestEfficiency = servers[i]->getEfficiency();
		}
	}

	if (retval != nullptr)
	{
		retval->setBusy(true);
	}

	return retval;
}

// ServerArray - Accessors
bool ServerArray::isServerAvailable()
{
	bool retval = false;

	for (int i = 0; i < numServers; i++)
	{
		if (!(servers[i]->getBusy()))
		{
			retval = true;
		}
	}

	return retval;
}

void ServerArray::display()
{
	for (int i = 0; i < numServers; i++)
	{
		servers[i]->display();
	}
}