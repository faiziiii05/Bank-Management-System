#pragma once
#ifndef Data_H
#define Data_H

#include<iostream>
#include<string>
using namespace std;

class Data
{
private:
	string name, adress, cnic, number;
public:
	/************SETTERS*************/
	void set_name(string);
	void set_adress(string);
	void set_cnic(string);
	void set_number(string);
	/************GETTERS*************/
	string get_adress();
	string get_name();
	string get_cnic();
	string get_number();
	/************FUNCTIONS HADDERS*************/
	virtual bool check(int) = 0;
	virtual void outputline() = 0;
	virtual void OUTPUT() = 0;
	void input();
	void display();
};

#endif