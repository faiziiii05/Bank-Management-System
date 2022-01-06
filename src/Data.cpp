#include "Data.h"



/*******************DATA CLASS FUNCTIONS DEFINATION**********************/

/************DEFINATION OF DATA CLASS SETTERS*************/
void Data::set_adress(string a)
{
	adress = a;
}
void Data::set_name(string n)
{
	name = n;
}
void Data::set_cnic(string c)
{
	cnic = c;
}
void Data::set_number(string n)
{
	number = n;
}
/************DEFINATION OF DATA CLASS GETTERS*************/

string Data::get_name()
{
	return name;
}
string Data::get_adress()
{
	return adress;
}
string Data::get_cnic()
{
	return cnic;
}
string Data::get_number()
{
	return number;

}

/*******************DATA CLASS INPUT FUNCTION**********************/

void Data::input()
{
	string Name, Adress, Cnic, Number;
	cin.ignore();
	cout << "\nEnter Name : ";
	getline(cin, Name);
	cout << "\nEnter Adress : ";
	getline(cin, Adress);
	do {
		cout << "Enter CNIC number\t\t  : ";
		cin >> Cnic;
		if (Cnic.length() != 15)
		{
			cout << "wrong NIC number numbers limit is 15 with '-'!! \n";
		}
	} while (Cnic.length() != 15);
	do {
		cout << "Enter Phone Number\t\t  : ";
		cin >> Number;
		if (Number.length() != 12)
		{
			cout << "wrong Phone number!! Numbers limit is 12 with country Code !! \n";
		}
	} while (Number.length() != 12);
	/***************SETTING VALUES IN SETTER********************/
	set_name(Name);
	set_adress(Adress);
	set_cnic(Cnic);
	set_number(Number);

}

/*******************DATA CLASS DISPLAYING FUNCTION**********************/

void Data::display()
{
	cout << "\nName is : " << get_name();
	cout << "\nAdress is : " << get_adress();
	cout << "\nCNIC Number is : " << get_cnic();
	cout << "\nPhone Number is : +" << get_number();
}