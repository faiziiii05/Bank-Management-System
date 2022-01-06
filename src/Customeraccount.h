#pragma once
#ifndef Customeraccount_H
#define Customeraccount_H

#include"AccountManager.h"

/*******************CUSTOMER ACCOUNTS CLASS**********************/

class Customeraccount :public AccountManager
{
public:
	void customerdisplay();
	void customerupdate();
	void customeraccounts_choice();
};
#endif
