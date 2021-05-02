/*-------------------------------------
CSIT314 Project Part B - Queueing system under test

Group Leader Name: Andrew Bentley
Subject: CSIT314
Computer Lab: CL/05 Thu 15:30
Assessment Item: Project Part B - System Under Test
File: Server.cpp

Code taken from CSCI203 Assignment 2 Submission,
Spring 2019 by Andrew Bentley
Created: 11/9/2019 15:06

Code updated for CSIT314 Project Part B - Queueing system Under Test
Autumn 2021 by Andrew Bentley
Updated: 3/5/2021 00:09
-------------------------------------*/

#include <iostream>

#include "Server.h"

// Server - Constructors
Server::Server()
{
	numServers++;

	busy = false;
	efficiency = 0.0;
	id = numServers;
	currentCustomer = nullptr;
}

Server::Server(double efficiency)
{
	numServers++;

	busy = false;
	this->efficiency = efficiency;
	id = numServers;
	currentCustomer = nullptr;
}

// Server - Mutators
void Server::setEfficiency(double efficiency)
{
	this->efficiency = efficiency;
}

void Server::setBusy(bool busy)
{
	this->busy = busy;
}

void Server::setId(int id)
{
	this->id = id;
}

void Server::setCurrentCustomer(Customer* currentCustomer)
{
	this->currentCustomer = currentCustomer;

	if (currentCustomer == nullptr)
	{
		busy = false;
	}
	else
	{
		busy = true;
	}

}

// Server - Accessors
double Server::getEfficiency()
{
	return efficiency;
}

bool Server::getBusy()
{
	return busy;
}

int Server::getId()
{
	return id;
}

Customer* Server::getCurrentCustomer()
{
	return currentCustomer;
}

void Server::display()
{
	std::cout << id << ":" << efficiency << ":" << busy << std::endl;
}