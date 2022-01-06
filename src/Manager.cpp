#include "Manager.h"



/*******************MANAGER CLASS FUNCTIONS DEFINATION**********************/

void Manager::managerchoice()
{
	do
	{
		system("cls");
		cout << "\n\t\t\t\t********************************MANAGER SECTION********************************";
		cout << "\n\t\t\t\t\tIf you are Account Manager then Press 1\n";
		cout << "\n\t\t\t\t\tIf you are Locker Manager then Press 2\n";
		cout << "\n\t\t\t\t\tIf you are Employee Manager then Press 3\n";
		cout << "\n\t\t\t\t\tFor Exit Press 4\n";
		cout << "\n\t\t\t\tEnter Your Choice : ";
		cin >> CH;
		cin.ignore();
		switch (CH)
		{   // manager switch

			/******************************ACCOUNT MANAGER CASE*********************************/

		case'1':
		{   // manager case 1
			accountmanager_choice();
			break;    // account case break
		}   // case 1 end

		/******************************LOCKER MANAGER CASE*********************************/

		case'2':
		{   // manager case 2
			lockermanager_choice();
			break;    // account case break
		}   // case 2 end

			/******************************EMPLOYEE MANAGER CASE*********************************/

		case'3':
		{   // manager case 3
			employeemanager_choice();
			break;    // employee case break
		}   // case 3 end

		case '4':
		{
			cout << "\n\t\t\t\tYou Are Now Going To Exit\n";
			cout << "\nPress Any Key to Contineue\n";
			_getch();
			exit(0);
			break;
		}

		default:
		{
			managerchoice();
		}

		} // switch end
	} while (CH != '4');
}
