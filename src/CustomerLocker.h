#pragma once
#ifndef CustomerLocker_H
#define CustomerLocker_H

#include"LockerManager.h"

/*******************CUSTOMER ACCOUNTS CLASS**********************/

class CustomerLocker :public LockerManager
{
public:
	void lockercustomerdisplay();
	void lockercustomerupdate();
	void lockercustomer_choice();
};
#endif
