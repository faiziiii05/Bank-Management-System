#include "EmployeeManager.h"


/*******************EMPLOYEE MANAGER CLASS FUNCTIONS DEFINATION**********************/
bool EmployeeManager::check(int id)
{
	bool E = false;
	fstream file("Locker.DAT", ios::in);
	file.seekg(0, ios::beg);
	while (file.read((char*)this, sizeof(EmployeeManager)))
	{
		if (id == employee_id)
			E = true;
		break;
	}
	file.close();
	return E;
}

void EmployeeManager::outputline()
{
	cout << "Employ ID" << setw(9) << "Name" << setw(19) << "Adress" << setw(24) << "CNIC" << setw(27) << "Designation" << endl;
}
void EmployeeManager::OUTPUT()
{
	cout << employee_id << setw(22) << get_name() << setw(21) << get_adress() << setw(27) << get_cnic() << setw(25) << designation << endl;
}


/*******************ADD NEW EMPLOY FUNCTION**********************/
void EmployeeManager::employeeadd()
{
	fstream ff;
	int ei;
	cout << "\nEnter Employee ID : ";
	cin >> ei;
	bool E = check(ei);
	if (E)
	{
		cout << "\n\t\t\tSORRY!!!!! Employee ID is Already Booked\n";
	}
	else
	{
		ff.open("Employee.DAT", ios::out | ios::app);
		cout << "\n\n";
		employee_id = ei;
		/*******************TAKING INPUT OF USER THROUGH INPUT FUNCTION**********************/
		Data::input();
		ff.write((char*)this, sizeof(EmployeeManager));
		cout << "\n\n\t\t\t\t\tCONGRATULATIONS!!!!EMPLOYEE IS HIRED NOW\n\n";

	}
	ff.close();
	cout << "\n\n\t\t\t\t\tPRESS ANY KEY TO CONTINEUE";
	_getch();
}

/*******************DISPLAY ALL EMPLOYEE FUNCTION**********************/

void EmployeeManager::employeedisplay()
{
	fstream employ;
	employ.open("Employee.DAT", ios::in);
	employ.seekg(0, ios::beg);
	outputline();
	while (employ.read((char*)this, sizeof(EmployeeManager)))
	{
		OUTPUT();
		cout << "\n\n";
	}
	employ.close();
	cout << "\n\n\t\t\t\t\tPRESS ANY KEY TO CONTINEUE";
	_getch();
}

/*******************DELETE EMPLOYEE FUNCTION**********************/

void EmployeeManager::employeedelete()
{
	int remove_employee;
	cout << "\nEnter Employee ID You Want to Remove : ";
	cin >> remove_employee;
	bool E = check(remove_employee);
	if (E)
	{
		fstream ee;
		ee.open("Employee.DAT", ios::in);
		fstream temp;
		temp.open("TEMP.DAT", ios::out);
		ee.seekg(0, ios::beg);
		while (!ee.eof())
		{
			ee.read((char*)this, sizeof(EmployeeManager));
			if (ee.eof())
				break;
			if (remove_employee != employee_id)
				temp.write((char*)this, sizeof(EmployeeManager));
		}
		ee.close();
		temp.close();
		ee.open("Locker.DAT", ios::out);
		temp.open("temp.Dta", ios::in);
		temp.seekg(0, ios::beg);
		while (!temp.eof())
		{
			temp.read((char*)this, sizeof(EmployeeManager));
			if (temp.eof())
				break;
			ee.write((char*)this, sizeof(EmployeeManager));
		}
		ee.close();
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

void EmployeeManager::employeemanager_choice()
{
	string user = "Employee Manager";
	string pass = "172B";
	string username, password;
	do
	{//   user name
		cout << "\n\t\t\t\t************************WELCOME TO EMPLYEE SECTION************************";
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
					{  // employee section
						system("cls");
						cout << "\n\t\t\t\t************************WELCOME TO EMPLOYEE SECTION************************";
						cout << "\n\t\t\t\tFor Hiring Employee press 1 ";
						cout << "\n\t\t\t\tFor Displaying Employees press 2 ";
						cout << "\n\t\t\t\tFor Delete Employee press 3 ";
						cout << "\n\t\t\t\tFor LOGOUT press 4 ";
						cout << "\n\t\t\tEnter your Choice : ";
						cin >> ch;
						switch (ch)
						{   //employee switch

						  /***************ADDING NEW EMPLOYEE CASE***************/

						case'1':
						{
							system("cls");
							cout << "\n\t\t\t\t*****************WELCOME TO HIRING NEW EMPLOYEE SECTION*****************\n";
							employeeadd();

							break;
						}

						/***************DISPLAYING ALL EMPLOYEES CASE***************/

						case '2':
						{
							system("cls");
							cout << "\n\t\t\t\t*****************WELCOME TO VIEWING EMPLOYEES SECTION*****************\n";

							employeedisplay();

							break;
						}

						/***************DELETE EMPLOYEE CASE***************/

						case '3':
						{
							system("cls");
							cout << "\n\t\t\t\t*****************WELCOME TO DELETE EMPLOYEE SECTION*****************\n";
							employeedelete();
							break;
						}

						/***************LOGOUT AS EMPLOYEE MANAGER CASE***************/


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
							employeemanager_choice();

						}
						}// employee switch



					} while (ch != '4');// employee switch while

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

