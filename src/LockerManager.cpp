#include "LockerManager.h"



/*******************LOCKER MANAGER CLASS FUNCTIONS DEFINATION**********************/

bool LockerManager::check(int locker_id)
{
	bool F = false;
	fstream file("Locker.DAT", ios::in);
	file.seekg(0, ios::beg);
	while (file.read((char*)this, sizeof(LockerManager)))
	{
		if (locker_id == lockernumber)
			F = true;
		break;
	}
	file.close();
	return F;
}

void LockerManager::outputline()
{
	cout << "Locker Number" << setw(9) << "Name" << setw(19) << "Adress" << setw(24) << "CNIC" << setw(27) << "Number" << endl;
}
void LockerManager::OUTPUT()
{
	cout << lockernumber << setw(22) << get_name() << setw(21) << get_adress() << setw(27) << get_cnic() << setw(25) << get_number() << endl;
}
/*******************ADD NEW LOCKERS FUNCTION**********************/
void LockerManager::lockeradd()
{
	fstream fin;
	int al;
	cout << "\nEnter Locker Number : ";
	cin >> al;
	bool L = check(al);
	if (L)
	{
		cout << "\n\t\t\tSORRY!!!!! Locker is Already Booked\n";
	}
	else
	{
		fin.open("Locker.DAT", ios::out | ios::app);
		cout << "\n\n";
		lockernumber = al;
		/*******************TAKING INPUT OF USER THROUGH INPUT FUNCTION**********************/
		Data::input();
		fin.write((char*)this, sizeof(LockerManager));
		cout << "\n\n\t\t\t\t\tCONGRATULATIONS!!!!LOCKER IS BOOKED NOW\n\n";

	}
	fin.close();
	cout << "\n\n\t\t\t\t\tPRESS ANY KEY TO CONTINEUE";
	_getch();
}

/*******************DISPLAY ALL LOCKERS FUNCTION**********************/

void LockerManager::lockerdisplay()
{

	fstream file;
	file.open("Locker.DAT", ios::in);
	file.seekg(0, ios::beg);
	outputline();
	while (file.read((char*)this, sizeof(LockerManager)))
	{
		OUTPUT();
		cout << "\n\n";
	}
	file.close();
	cout << "\n\n\t\t\t\t\tPRESS ANY KEY TO CONTINEUE";
	_getch();
}


/*******************DELETE LOCKERS FUNCTION**********************/

void LockerManager::lockerdelete()
{
	int remove_locker;
	cout << "\nEnter Locker Number You Want to Remove : ";
	cin >> remove_locker;
	bool R = check(remove_locker);
	if (R)
	{
		fstream file;
		file.open("Locker.DAT", ios::in);
		fstream temp;
		temp.open("temp.DAT", ios::out);
		file.seekg(0, ios::beg);
		while (!file.eof())
		{
			file.read((char*)this, sizeof(LockerManager));
			if (file.eof())
				break;
			if (remove_locker != lockernumber)
				temp.write((char*)this, sizeof(LockerManager));
		}
		file.close();
		temp.close();
		file.open("Locker.DAT", ios::out);
		temp.open("temp.Dta", ios::in);
		temp.seekg(0, ios::beg);
		while (!temp.eof())
		{
			temp.read((char*)this, sizeof(LockerManager));
			if (temp.eof())
				break;
			file.write((char*)this, sizeof(LockerManager));
		}
		file.close();
		temp.close();
		cout << "\n\t\tCONGRATULATIONS!! YOU DELETED THE WHOLE RECORD FILE\n";
	}
	else
	{
		cout << "\n\t\t\tSORRY!!! NO RECORD FOUND\n";
	}
	cout << "\n\t\t\tPress Any Key To Contineue\n";
	_getch();

}

void LockerManager::lockermanager_choice()
{
	string user = "Locker Manager";
	string pass = "172B";
	string username, password;
	do
	{//   user name
		cout << "\n\t\t\t\t************************WELCOME TO LOCKERS SECTION************************";
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
					{  // lockers section
						system("cls");
						cout << "\n\t\t\t\t************************WELCOME TO LOCKERS SECTION************************";
						cout << "\n\t\t\t\tFor Adding New Locker press 1 ";
						cout << "\n\t\t\t\tFor Displaying Lockers press 2 ";
						cout << "\n\t\t\t\tFor Delete Locker press 3 ";
						cout << "\n\t\t\t\tFor LOGOUT press 4 ";
						cout << "\n\t\t\tEnter your Choice : ";
						cin >> ch;
						switch (ch)
						{   //locker switch

						  /***************ADDING NEW LOCKER CASE***************/

						case'1':
						{
							system("cls");
							cout << "\n\t\t\t\t*****************WELCOME TO ADDING NEW LOCKERS SECTION*****************\n";
							lockeradd();

							break;
						}

						/***************DISPLAYING ALL LOCKERS CASE***************/

						case '2':
						{
							system("cls");
							cout << "\n\t\t\t\t*****************WELCOME TO VIEWING LOCKERS SECTION*****************\n";
							lockerdisplay();

							break;
						}



						/***************DELETE LOCKER CASE***************/

						case '3':
						{
							system("cls");
							cout << "\n\t\t\t\t*****************WELCOME TO DELETE LOCKER SECTION*****************\n";
							lockerdelete();
							break;
						}



						/***************LOGOUT AS LOCKER MANAGER CASE***************/

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
							lockermanager_choice();

						}
						}// locker switch



					} while (ch != '4');// locker switch while

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
