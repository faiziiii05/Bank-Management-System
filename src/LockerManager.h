#pragma once
#ifndef LockerManager_H
#define LockerManager_H
#include"Data.h"
#include<iomanip>
#include<conio.h>
#include<fstream>

/*******************LOCKER MANAGER CLASS**********************/

class LockerManager :public Data
{
protected:
	int lockernumber;
public:
	void outputline();
	void OUTPUT();
	bool check(int);
	void lockeradd();
	void lockerdisplay();
	void lockerdelete();
	void lockermanager_choice();
};
#endif