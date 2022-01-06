#pragma once
#ifndef Bank_H
#define Bank_H
#include"Customer.h"
#include"Manager.h"
/*******************BANK CLASS**********************/

class Bank
{
private:
	char DECISION;
	Manager manager;
	Customer customer;
public:
	void bankchoice();
};

#endif