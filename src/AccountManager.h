#pragma once
#ifndef AccountManager_H
#define AccountManager_H

#include"Data.h"
#include<iomanip>
#include<conio.h>
#include<fstream>
/*******************ACCOUNT MANAGER CLASS**********************/

class AccountManager :public Data
{
protected:
	int account_number;
	double balance;
public:
	void outputline();
	void OUTPUT();
	void accountadd();
	void accountdisplay();
	void accountdelete(int);
	bool check(int);
	void accountmanager_choice();
	void set_balance(double);
	double get_balance();
};
#endif