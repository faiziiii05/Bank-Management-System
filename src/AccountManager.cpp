

#include "AccountManager.h"


/*******************ACCOUNTMANAGER CLASS FUNCTIONS DEFINATION**********************/
void AccountManager::set_balance(double rs)
{
	balance = rs;
}
double AccountManager::get_balance()
{
	return balance;
}
/*******************CREATE NEW ACCOUNT FUNCTION**********************/
void AccountManager::accountadd()
{
	int an;
	bool Check;
	fstream file;
	cout << "\nEnter Account Number : ";
	cin >> an;
	Check = check(an);
	if (Check)
	{
		cout << "\n\t\t\tSORRY!!!!! Account is Already Opened\n";
	}
	else
	{
		cout << endl << endl;
		file.open("Bank.DAT", ios::out | ios::app);
		account_number = an;
		/*******************TAKING INPUT OF USER THROUGH INPUT FUNCTION**********************/
		input();
		cout << "\nEnter Initial Balance of " << an << " Account Number : ";
		cin >> balance;
		cout << "\n\n\t\t\t\t\tCONGRATULATIONS!!!!ACCOUNT IS OPENED NOW\n\n";
		file.write((char*)this, sizeof(AccountManager));
	}
	file.close();
	cout << "\n\n\t\t\t\t\tPRESS ANY KEY TO CONTINEUE";
	_getch();
}

/*******************DISPLAY ALL ACCOUNTS FUNCTION**********************/

void AccountManager::accountdisplay()
{
	fstream file;
	file.open("Bank.DAT", ios::in);
	file.seekg(0, ios::beg);
	outputline();
	while (file.read((char*)this, sizeof(AccountManager)))
	{
		OUTPUT();
		cout << "\n\n";
	}
	file.close();
	cout << "\n\n\t\t\t\t\tPRESS ANY KEY TO CONTINEUE";
	_getch();
}

/*******************DELETE ACCOUNTS FUNCTION**********************/

void AccountManager::accountdelete(int remove_account)
{

	fstream file;
	file.open("Bank.DAT", ios::in);
	fstream temp;
	temp.open("Temp.DAT", ios::out);
	file.seekg(0, ios::beg);
	while (!file.eof())
	{
		file.read((char*)this, sizeof(AccountManager));

		if (file.eof())
		{
			break;
		}
		if (account_number != remove_account)
		{
			temp.write((char*)this, sizeof(AccountManager));
		}
	}
	file.close();
	temp.close();
	file.open("Bank.DAT", ios::out);
	temp.open("Temp.Dta", ios::in);
	temp.seekg(0, ios::beg);
	while (!temp.eof())
	{
		temp.read((char*)this, sizeof(AccountManager));
		if (temp.eof())
		{
			break;
		}
		file.write((char*)this, sizeof(AccountManager));
	}
	file.close();
	temp.close();
}
bool AccountManager::check(int ac)
{
	bool say = false;
	fstream aa;
	aa.open("Bank.DAT", ios::in);
	aa.seekg(0, ios::beg);
	while (aa.read((char*)this, sizeof(AccountManager)))
	{
		if (ac == account_number)
		{
			say = true;
			break;
		}
	}
	aa.close();
	return say;
}
void AccountManager::outputline()
{
	cout << "Account Number" << setw(9) << "Name" << setw(19) << "Adress" << setw(24) << "CNIC" << setw(27) << "Number" << setw(15) << "Balance" << right << endl;

}
void AccountManager::OUTPUT()
{
	cout << account_number << setw(22) << get_name() << setw(21) << get_adress() << setw(27) << get_cnic() << setw(25) << get_number() << setw(12) << balance << right;
}

/*******************ACCOUNT MAMAGER CHOICE**********************/

void AccountManager::accountmanager_choice()
{
	string user = "Account Manager";
	string pass = "172B";
	string username, password;
	do
	{//   user name
		cout << "\n\t\t\t\t************************WELCOME TO ACCOUNTS SECTION************************";
		cout << "\n\t\t\tEnter User Name : ";
		getline(cin, username);
		if (username == user)
		{   // user name if
			do
			{    // password
				cout << "\n\t\t\tEnter Password : ";
				getline(cin, password);
				if (password == pass)
				{   // password if
					char ch;

					do
					{  // account section
						system("cls");
						cout << "\n\t\t\t\t************************WELCOME TO ACCOUNTS SECTION************************";
						cout << "\n\t\t\t\tFor Adding Account press 1 ";
						cout << "\n\t\t\t\tFor Displaying Accounts press 2 ";
						cout << "\n\t\t\t\tFor Delete Account press 3 ";
						cout << "\n\t\t\t\tFor LOGOUT press 4 ";
						cout << "\n\t\t\tEnter your Choice : ";
						cin >> ch;
						switch (ch)
						{   //account switch

						  /***************ADDING NEW ACCOUNT CASE***************/

						case'1':
						{
							system("cls");
							cout << "\n\t\t\t\t*****************WELCOME TO ADDING NEW ACCOUNT SECTION*****************\n";
							accountadd();
							break;
						}

						/***************DISPLAYING ALL ACCOUNTS CASE***************/

						case '2':
						{
							system("cls");
							cout << "\n\t\t\t\t*****************WELCOME TO VIEWING ACCOUNT SECTION*****************\n";
							accountdisplay();
							break;
						}


						/***************DELETE ACCOUNT CASE***************/

						case '3':
						{
							system("cls");
							cout << "\n\t\t\t\t*****************WELCOME TO DELETE ACCOUNT SECTION*****************\n";
							int del_account;
							cout << "\nEnter Account Numbeer You Want To Delete : ";
							cin >> del_account;
							bool del = check(del_account);
							if (!del)
							{
								cout << "\n\t\t\t\tSORRY!! RECORD NOT FOUND\n";
							}
							else
							{
								cout << "\n\t\t\t\tYou Want to Delete ('Y' OR 'N') : ";
								char d;
								cin >> d;
								if (d == 'N' || d == 'n')
								{
									cout << "\n\t\t\t\tYOU DIDN;T DELETE THE ACCOUNT\n";
								}
								else
								{
									accountdelete(del_account);
								}
							}
							cout << "\n\t\t\t\tPress Any Key To Contineue\n";
							_getch();

							break;
						}

						/***************LOGOUT AS ACCOUNT MANAGER CASE***************/

						case '4':
						{
							cout << "\n\t\t\t\tYou Are Now Going To Logout\n";
							cout << "\n\t\t\t\tPress Any Key to Contineue\n";
							_getch();
							exit(0);
							break;
						}
						default:
						{
							accountmanager_choice();
						}
						}// account switch



					} while (ch != 4);// account switch while

				}  //password if
				else
				{
					cout << "\n\t\t\t\t\tWrong Password";
					cout << "\a\a\a\a";
				}
			} while (password != pass);   // password while
		}   // user name if
		else
		{
			cout << "\n\t\t\t\tWrong User Name";
			cout << "\a\a\a";
		}
	} while (username != user); //user name do
}
