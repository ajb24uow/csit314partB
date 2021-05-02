/*-------------------------------------
CSIT314 Project Part B - Queueing system under test

Group Leader Name: Andrew Bentley
Subject: CSIT314
Computer Lab: CL/05 Thu 15:30
Assessment Item: Project Part B - System Under Test
File: CustomerQueue.cpp

Code taken from CSCI203 Assignment 2 Submission,
Spring 2019 by Andrew Bentley
Created: 11/9/2019 15:06

Code updated for CSIT314 Project Part B - Queueing system Under Test
Autumn 2021 by Andrew Bentley
Updated: 3/5/2021 00:09
-------------------------------------*/

#include <iostream>

#include "CustomerQueue.h"

// CustomerQueue - Constructor
CustomerQueue::CustomerQueue()
{
	customerQueue = new Customer * [MAX_SIZE + 1];
	start = 1;
	next = 1;
}

// CustomerQueue - Mutators
void CustomerQueue::enqueue(Customer* item)
{
	std::cout << "?";
	customerQueue[next] = item;
	next++;
	if (next > MAX_SIZE)
	{
		next = 1;
	}

}

Customer* CustomerQueue::dequeue()
{
	Customer* retval = NULL;
	if (start != next)
	{
		retval = customerQueue[start];
		start++;

		if (start > MAX_SIZE)
		{
			start = 1;
		}
	}

	return retval;
}

// CustomerQueue - Accessors
bool CustomerQueue::isEmpty()
{
	return start == next;
}

int CustomerQueue::getSize()
{
	int retval = next - start;

	if (retval < 0)
	{
		retval += MAX_SIZE;
	}

	return retval;
}