#pragma once
#ifndef Manager_H
#define Manager_H

#include"AccountManager.h"
#include"LockerManager.h"
#include"EmployeeManager.h"

/*******************MANAGERS CLASS**********************/

class Manager:public AccountManager,public LockerManager,public EmployeeManager
{
private:
	char CH;
public:
	void managerchoice();
};
#endif