/*-------------------------------------
CSIT314 Project Part B - Queueing system under test

Group Leader Name: Andrew Bentley
Subject: CSIT314
Computer Lab: CL/05 Thu 15:30
Assessment Item: Project Part B - System Under Test
File: File.cpp

Code taken from CSCI203 Assignment 2 Submission,
Spring 2019 by Andrew Bentley
Created: 11/9/2019 15:06

Code updated for CSIT314 Project Part B - Queueing system Under Test
Autumn 2021 by Andrew Bentley
Updated: 3/5/2021 00:09
-------------------------------------*/

#include <fstream>
#include <string>

#include "File.h"

// File - Constructors
File::File()
{
	ifs = nullptr;
	countKnown = false;
	serverNum = 0;
	serversRead = 0;
	open("data.txt");
}

File::File(const char* filename)
{
	ifs = nullptr;
	countKnown = false;
	serverNum = 0;
	serversRead = 0;

	open(filename);
}

File::~File()
{
	close();
	delete ifs;
}

// File - Mutators
void File::open(const char* filename)
{
	ifs = new std::ifstream(filename);

	if (!ifs->good())
	{
		throw(std::string("Unable to open data file"));
	}
}

void File::close()
{
	ifs->close();
}

int File::readServerCount()
{
	int retval;

	if (!countKnown)
	{
		if (!(*ifs >> retval))
		{
			throw(std::string("Problem reading server count from file"));
		}
		countKnown = true;
	}
	else
	{
		throw(std::string("Attempted to read number of servers an additional time"));
	}

	serverNum = retval;
	return retval;
}

Server* File::readNextServer()
{
	Server* retval = NULL;
	if (countKnown && (serversRead < serverNum))
	{
		double efficiency;
		if (!(*ifs >> efficiency))
		{
			throw(std::string("Problem reading server from file"));
		}

		serversRead++;
		retval = new Server(efficiency);
	}

	return retval;
}

Customer* File::readNextCustomer()
{
	Customer* nextCustomer = NULL;

	if (countKnown && (serversRead == serverNum))
	{
		double arrivalTime = 0;
		double tallyTime = 0;
		char paymentType[30];
		bool paymentByCard = true;

		if (*ifs >> arrivalTime && *ifs >> tallyTime && *ifs >> paymentType)
		{
			if (paymentType[3] == 'h')
			{
				paymentByCard = false;
			}

			nextCustomer = new Customer(arrivalTime, tallyTime, paymentByCard);
		}
	}
	else
	{
		throw(std::string("Problem loading customer"));
	}

	return nextCustomer;
}