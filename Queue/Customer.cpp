/*-------------------------------------
CSIT314 Project Part B - Queueing system under test

Group Leader Name: Andrew Bentley
Subject: CSIT314
Computer Lab: CL/05 Thu 15:30
Assessment Item: Project Part B - System Under Test
File: Customer.cpp

Code taken from CSCI203 Assignment 2 Submission,
Spring 2019 by Andrew Bentley
Created: 11/9/2019 15:06

Code updated for CSIT314 Project Part B - Queueing system Under Test
Autumn 2021 by Andrew Bentley
Updated: 3/5/2021 00:09
-------------------------------------*/

#include <iostream>

#include "Customer.h"


Customer::Customer()
{
	arrivalTime = 0.0;
	tallyTime = 1.0;
	paymentByCard = false;
}

Customer::Customer(double arrivalTime, double tallyTime, bool paymentByCard)
{
	this->arrivalTime = arrivalTime;
	this->tallyTime = tallyTime;
	this->paymentByCard = paymentByCard;
}

Customer::Customer(Customer& orig)
{
	this->arrivalTime = orig.arrivalTime;
	this->tallyTime = orig.tallyTime;
	this->paymentByCard = orig.paymentByCard;
}

Customer::~Customer()
{

}

// Customer - Mutators
void Customer::setArrivalTime(double arrivalTime)
{
	this->arrivalTime = arrivalTime;
}

void Customer::setTallyTime(double tallyTime)
{
	this->tallyTime = tallyTime;
}

void Customer::setPaymentByCard(bool paymentByCard)
{
	this->paymentByCard = paymentByCard;
}

// Customer - Accessors
double Customer::getArrivalTime()
{
	return arrivalTime;
}

double Customer::getTallyTime()
{
	return tallyTime;
}

bool Customer::getPaymentByCard()
{
	return paymentByCard;
}

void Customer::display()
{
	std::cout << arrivalTime << ":" << tallyTime << ":";
	if (getPaymentByCard())
	{
		std::cout << "card" << std::endl;
	}
	else
	{
		std::cout << "cash" << std::endl;
	}
}