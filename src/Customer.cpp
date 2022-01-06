#include "Customer.h"



/*******************CUSTOMERS CLASS FUNCTIONS DEFINATION**********************/

void Customer::customerchoice()
{
	system("cls");
	cout << "\n\t\t*****************************WELCOME TO CUSTOMER SECTION*****************************\n";
	cout << "\n\t\t\t\t\tFor Visiting Accounts Section Press 1\n";
	cout << "\n\t\t\t\t\tFor Visiting Locker Section Press 2 \n";
	cout << "\n\t\t\t\t\tEnter Your Choice : ";
	cin >> CHOICE;
	switch (CHOICE)
	{  // customer switch 

		/*******************CUSTOMER ACCOUNTS CASE**********************/

	case'1':
	{  // account case
		customeraccounts_choice();
		break;
	}
	case '2':
	{
		lockercustomer_choice();
	}
		default:
	{
		customerchoice();
	}
	}  // customer switch
}

