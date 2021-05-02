/*-------------------------------------
CSIT314 Project Part B - Queueing system under test

Group Leader Name: Andrew Bentley
Subject: CSIT314
Computer Lab: CL/05 Thu 15:30
Assessment Item: Project Part B - System Under Test
File: EventQueue.h

Code taken from CSCI203 Assignment 2 Submission,
Spring 2019 by Andrew Bentley
Created: 11/9/2019 15:06

Code updated for CSIT314 Project Part B - Queueing system Under Test
Autumn 2021 by Andrew Bentley
Updated: 3/5/2021 00:09
-------------------------------------*/

#pragma once

#ifndef AJB24_EVENTQUEUE_H
#define AJB24_EVENTQUEUE_H

#include "Event.h"

class EventQueue
{
private:

	static const int MAX_SIZE;
	int queueSize;
	Event** data;

public:
	void insertMinHeap(Event* data);
	void makeMinHeap();
	void siftUpMinHeap(int index = 1);
	void siftDownMinHeap(int index = 1);

	void displayHeapArray();
	void displayHeapArray(int startIndex, int endIndex);
	void swap(int indexA, int indexB);
	int getQueueSize();


public:
	EventQueue();

	Event* getNextEvent();
};

#endif
