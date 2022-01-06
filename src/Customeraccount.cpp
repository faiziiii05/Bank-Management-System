#include "Customeraccount.h"


/************DEFINATION OF CUSTOMERACCOUNT CLASS SETTERS*************/


/*******************DISPLAY CUSTOMER RECORD FUNCTION**********************/

void Customeraccount::customerdisplay()
{
	int search_account;
	cout << "\nEnter Account Number You Want to Search : ";
	cin >> search_account;
	bool found = check(search_account);
	if (found)
	{
		AccountManager::outputline();
		AccountManager::OUTPUT();
	}
	else
	{
		cout << "\n\t\tSORRY!!!!No Information available";
	}
	cout << "\n\n\t\t\t\t\tPRESS ANY KEY TO CONTINEUE";

	_getch();

}

/*******************DEPOSIT MONEY IN PERSONAL ACCOUNT FUNCTION**********************/


void Customeraccount::customerupdate()
{
	fstream up;
	int update_account;
	cout << "\nEnter Account Number you want to update : ";
	cin >> update_account;
	bool U = check(update_account);
	if (U)
	{
		up.open("Bank.DAT", ios::app | ios::ate);
		outputline();
		OUTPUT();
		cout << "\n\n\n\n\t\t\t\tFor Withdraw Money Press 1\n";
		cout << "\n\t\t\t\tFor Deposit Money Press 2\n";
		char upch;
		cout << "\nEnter You Choice : ";
		cin >> upch;
		switch (upch)
		{
		case'1':
		{
			double transaction;
			cout << "\nEnter Money For Withdraw : ";
			cin >> transaction;
			double oldbalance = get_balance();
			set_balance(oldbalance - transaction);
			outputline();
			OUTPUT();
			//	up.tellp();
			up.seekp(up.tellp() * 1 - sizeof(AccountManager), ios::cur);
			up.write((char*)this, sizeof(*this));
			break;

		}
		case'2':
		{
			double Transaction;
			cout << "\nEnter Money For Deposit : ";
			cin >> Transaction;
			double Oldbalance = get_balance();
			set_balance(Oldbalance + Transaction);
			outputline();
			OUTPUT();
			up.write((char*)this, sizeof(*this));
			break;

		}
		default:
		{
			customeraccounts_choice();
		}
		}
	}
	else
	{
		cout << "\n\t\t\t\tSORRY!!! NO RECORD FOUND\n";
	}
	cout << "\n\t\t\tPress Any Key To Contineue\n";
	_getch();
}
void Customeraccount::customeraccounts_choice()
{
	system("cls");
	char ch;
	do
	{
		cout << "\n\t\t*****************************WELCOME TO ACCOUNTS SECTION*****************************";
		cout << "\n\t\t\t\t\tFor View Your Account Press 1\n";
		cout << "\n\t\t\t\t\tFor Update Your Account Press 2\n";
		cout << "\n\t\t\t\t\tFor Exit Press 3\n";
		cout << "\n\t\t\t\t\tEnter Your Choice : ";
		cin >> ch;
		switch (ch)
		{
			/*******************CUSTOMER ACCOUNT DISPLAY CASE**********************/

		case'1':
		{
			system("cls");
			cout << "\n\t\t*****************************WELCOME TO DISPLAY SECTION*****************************";
			customerdisplay();
			break;
		}
		/*******************CUSTOMER UPDATE CASE**********************/
		case '2':
		{
			system("cls");
			cout << "\n\t\t*****************************WELCOME TO UPDATE SECTION*****************************";
			customerupdate();
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
			customeraccounts_choice();
		}
		}

	} while (ch != '3');

}
