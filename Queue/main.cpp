/*-------------------------------------
CSIT314 Project Part B - Queueing system under test

Group Leader Name: Andrew Bentley
Subject: CSIT314
Computer Lab: CL/05 Thu 15:30
Assessment Item: Project Part B - System Under Test
File: main.cpp

Code taken from CSCI203 Assignment 2 Submission,
Spring 2019 by Andrew Bentley
Created: 11/9/2019 15:06

Code updated for CSIT314 Project Part B - Queueing system Under Test
Autumn 2021 by Andrew Bentley
Updated: 3/5/2021 00:09
-------------------------------------*/

#include <iostream>
#include <fstream>
#include <string>

#include "Customer.h"
#include "Server.h"
#include "Event.h"
#include "File.h"
#include "CustomerQueue.h"
#include "EventQueue.h"
#include "ServerArray.h"

using namespace std;

const char* filename = "ass2.txt";
const bool DEBUG = false;

int customersServed = 0;
double accumCustomerServingTime = 0.0;
double timeLastCustomerServed = 0.0;
int maxCustomerQueueLength = 0;
double accumCustomerQueueLength = 0.0;
double accumCustomerQueueTime = 0.0;
int zeroQueueTimeCount = 0;

int Server::numServers = 0;
const int CustomerQueue::MAX_SIZE = 500;
const int EventQueue::MAX_SIZE = 1000;
const double Event::CASH_PAYMENT_TIME = 0.7;
const double Event::CARD_PAYMENT_TIME = 0.3;

// Entry point
int main()
{
	try
	{
		CustomerQueue customerQueue;
		EventQueue eventQueue;
		ServerArray servers;
		double currentTime = 0.0;

		File dataFile(filename);

		// load server information
		servers.buildArray(&dataFile);

		// Read first customer from file
		Customer* nextCustomer = dataFile.readNextCustomer();
		if (nextCustomer != NULL)
		{
			Event* newEvent = new Event(nextCustomer);
			currentTime = newEvent->getEventTime();
			eventQueue.insertMinHeap(newEvent);
		}

		while (eventQueue.getQueueSize() != 0)
		{
			// get event from event queue
			Event* currentEvent = eventQueue.getNextEvent();

			// DEBUG: display event
			if (DEBUG)
			{
				currentEvent->display();
			}

			// if event is customerArrival event
			if (currentEvent->isCustomerArrival())
			{
				// if idle server available
				if (servers.isServerAvailable())
				{
					// get fastest server, set their busy flag
					Server* eventServer = servers.getBestServer();

					// add server finish event to event queue
					Event* serverFinishEvent = new Event(currentEvent, eventServer);
					eventQueue.insertMinHeap(serverFinishEvent);
				}
				else
				{
					// add customer to customer queue
					customerQueue.enqueue(currentEvent->getCustomer());
					cout << customerQueue.getSize();

				}

				// Statistics
				accumCustomerQueueLength += customerQueue.getSize();
				if (customerQueue.getSize() > maxCustomerQueueLength)
				{
					maxCustomerQueueLength = customerQueue.getSize();
				}

				// read next customer from file
				nextCustomer = dataFile.readNextCustomer();

				// if read next customer good
				if (nextCustomer != NULL)
				{
					// add customer arrival event to event queue
					Event* customerArrivalEvent = new Event(nextCustomer);
					eventQueue.insertMinHeap(customerArrivalEvent);
				}
			}
			// else event is a server finish event
			else
			{
				currentEvent->getServer()->setBusy(false);

				// Update statistics;
				customersServed++;
				timeLastCustomerServed = currentEvent->getEventTime();

				if (!customerQueue.isEmpty())
				{
					// get next customer from customer queue
					nextCustomer = customerQueue.dequeue();

					// get fastest server, set their busy flag
					Server* eventServer = servers.getBestServer();

					// add server finish event to event queue
					Event* serverFinishEvent = new Event(currentEvent, eventServer);
					eventQueue.insertMinHeap(serverFinishEvent);
				}
			}
		}
	}
	catch (string ex)
	{
		cerr << ex << endl;
	}

	// Display Statistics
	cout << "Number of customers served: "
		<< customersServed << endl;
	cout << "Time taken to serve all customers: "
		<< timeLastCustomerServed << endl;
	cout << "Greatest length reached by the customer queue: "
		<< maxCustomerQueueLength << endl;
	cout << "Average length of customer queue: "
		<< 0 << accumCustomerQueueLength / (double)customersServed << endl;
	cout << "Average customer waiting time in queue: "
		<< accumCustomerQueueTime / (double)customersServed << endl;
	cout << "Percentage of customers with zero waiting time: "
		<< (double)zeroQueueTimeCount / (double)customersServed * 100 << endl;
}

// Customer - Constructors
