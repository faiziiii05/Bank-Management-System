
#include "CustomerLocker.h"


/************DEFINATION OF CUSTOMERLocker CLASS SETTERS*************/


/*******************DISPLAY CUSTOMER RECORD FUNCTION**********************/

void CustomerLocker::lockercustomerdisplay()
{
	int search_account;
	cout << "\nEnter Locker Number You Want to Search : ";
	cin >> search_account;
	bool found = check(search_account);
	if (found)
	{
		LockerManager::outputline();
		LockerManager::OUTPUT();
	}
	else
	{
		cout << "\n\t\tSORRY!!!!No Information available";
	}
	cout << "\n\n\t\t\t\t\tPRESS ANY KEY TO CONTINEUE";

	_getch();

}

/*******************DEPOSIT MONEY IN PERSONAL ACCOUNT FUNCTION**********************/


void CustomerLocker::lockercustomerupdate()
{
	fstream ui;
	int update_locker;
	cout << "\nEnter Locker Number you want to update : ";
	cin >> update_locker;
	bool U = check(update_locker);
	if (U)
	{
		ui.open("Locker.DAT", ios::app | ios::ate);
		outputline();
		OUTPUT();
		cout << "\nENter Thing you want to put in Locker : ";
		string things;
		getline(cin, things);
		ui.write((char*)this, sizeof(LockerManager));
		ui.close();
	}

	else
	{
		cout << "\n\t\t\t\tSORRY!!! NO RECORD FOUND\n";
	}
	cout << "\n\t\t\tPress Any Key To Contineue\n";
	_getch();
}
void CustomerLocker::lockercustomer_choice()
{
	system("cls");
	char ch;
	do
	{
		cout << "\n\t\t*****************************WELCOME TO ACCOUNTS SECTION*****************************";
		cout << "\n\t\t\t\t\tFor View Your Account Press 1\n";
		cout << "\n\t\t\t\t\tFor Update Your Account Press 2\n";
		cout << "\n\t\t\t\t\tFor Exit Press 4\n";
		cout << "\n\t\t\t\t\tEnter Your Choice : ";
		cin >> ch;
		switch (ch)
		{
			/*******************CUSTOMER ACCOUNT DISPLAY CASE**********************/

		case'1':
		{
			system("cls");
			cout << "\n\t\t*****************************WELCOME TO DISPLAY SECTION*****************************";
			lockercustomerdisplay();
			break;
		}
		/*******************CUSTOMER UPDATE CASE**********************/
		case '2':
		{
			system("cls");
			cout << "\n\t\t*****************************WELCOME TO UPDATE SECTION*****************************";
			lockercustomerupdate();
			break;
		}
		case '3':
		{
			system("cls");
			cout << "\n\t\t\t\tYou Are Going To Exit\n";
			cout << "\n\t\t\t\tPress Any key To Contineue\n";
			_getch();
			exit(0);
			break;
		}
		default:
		{
			lockercustomer_choice();
		}
		}

	} while (ch != '3');

}
