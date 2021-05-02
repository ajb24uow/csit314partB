/*-------------------------------------
CSIT314 Project Part B - Queueing system under test

Group Leader Name: Andrew Bentley
Subject: CSIT314
Computer Lab: CL/05 Thu 15:30
Assessment Item: Project Part B - System Under Test
File: EventQueue.cpp

Code taken from CSCI203 Assignment 2 Submission,
Spring 2019 by Andrew Bentley
Created: 11/9/2019 15:06

Code updated for CSIT314 Project Part B - Queueing system Under Test
Autumn 2021 by Andrew Bentley
Updated: 3/5/2021 00:09
-------------------------------------*/

#include <iostream>
#include <string>

#include "EventQueue.h"

// EventQueue - Constructors
EventQueue::EventQueue()
{
	data = new Event * [MAX_SIZE + 1];
	queueSize = 0;
}

// EventQueue - Mutators
void EventQueue::insertMinHeap(Event* item)
{
	if (queueSize == MAX_SIZE)
	{
		throw(std::string("Heap full, cannot add further entries"));
	}

	queueSize++;
	data[queueSize] = item;

	siftUpMinHeap(queueSize);
}

void EventQueue::makeMinHeap()
{
	for (int index = queueSize / 2; index >= 1; index--)
	{
		siftDownMinHeap(index);
	}
}

void EventQueue::siftUpMinHeap(int childIndex)
{
	// move item at index to correct location
	if (childIndex == 1)
	{
		return;
	}

	int parentIndex = childIndex / 2;

	// if parent is smaller than this node, nothing needs to be done
	if (data[parentIndex]->getEventTime() < data[childIndex]->getEventTime())
	{
		return;
	}
	// otherwise we need to swap parent and child, and rebuild tree above
	else
	{
		swap(childIndex, parentIndex);
		siftUpMinHeap(parentIndex);
	}
}

void EventQueue::siftDownMinHeap(int parentIndex)
{
	int childIndex = parentIndex * 2;

	// determine which child is larger
	if (childIndex <= queueSize - 1
		&& data[childIndex]->getEventTime() > data[childIndex + 1]->getEventTime())
	{
		childIndex++;
	}

	// if child is smaller than parent, swap and then rebuild tree below
	if (childIndex <= queueSize
		&& data[parentIndex]->getEventTime() > data[childIndex]->getEventTime())
	{
		swap(parentIndex, childIndex);
		siftDownMinHeap(childIndex);
	}
}

void EventQueue::swap(int indexA, int indexB)
{
	Event* tmp = data[indexB];
	data[indexB] = data[indexA];
	data[indexA] = tmp;
}

Event* EventQueue::getNextEvent()
{
	Event* retval = data[1];
	data[1] = data[queueSize];
	makeMinHeap();
	queueSize--;

	return retval;
}

// EventQueue - Accessors
void EventQueue::displayHeapArray()
{
	for (int index = 1; index <= queueSize; index++)
	{
		data[index]->display();
	}
	std::cout << std::endl;
}

void EventQueue::displayHeapArray(int startIndex, int endIndex)
{
	for (int index = startIndex; index <= endIndex; index++)
	{
		data[index]->display();
	}
	std::cout << std::endl;
}

int EventQueue::getQueueSize()
{
	return queueSize;
}