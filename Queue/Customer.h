/*-------------------------------------
CSIT314 Project Part B - Queueing system under test

Group Leader Name: Andrew Bentley
Subject: CSIT314
Computer Lab: CL/05 Thu 15:30
Assessment Item: Project Part B - System Under Test
File: Customer.h

Code taken from CSCI203 Assignment 2 Submission,
Spring 2019 by Andrew Bentley
Created: 11/9/2019 15:06

Code updated for CSIT314 Project Part B - Queueing system Under Test
Autumn 2021 by Andrew Bentley
Updated: 3/5/2021 00:09
-------------------------------------*/

#pragma once

#ifndef AJB24_CUSTOMER_H
#define AJB24_CUSTOMER_H

class Customer
{
private:
	double arrivalTime;
	double tallyTime;
	bool paymentByCard;

public:
	Customer();
	Customer(double arrivalTime, double tallyTime = 0, bool paymentByCard = false);
	Customer(Customer& orig);
	~Customer();

	void setArrivalTime(double arrivalTime);
	void setTallyTime(double tallyTime);
	void setPaymentByCard(bool paymentByCard);

	double getArrivalTime();
	double getTallyTime();
	bool getPaymentByCard();

	void display();
};

#endif
