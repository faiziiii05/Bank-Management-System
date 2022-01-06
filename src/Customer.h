#pragma once
#ifndef Customer_H
#define Customer_H

#include"Customeraccount.h"
#include"CustomerLocker.h"
/*******************CUSTOMERS CLASS**********************/

class Customer:public Customeraccount,public CustomerLocker
{
private:
	char CHOICE;
public:
	void customerchoice();
};
#endif