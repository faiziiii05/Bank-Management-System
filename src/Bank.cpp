#include"Bank.h"
void Bank::bankchoice()
{
	do
	{
		cout << "\n\t\t\t\t\tIf You Are Manager then Press 1\n";
		cout << "\n\t\t\t\t\tIf You Are Customer then Press 2\n";
		cout << "\nEnter Your Choice  ";
		cin >> DECISION;
		switch (DECISION)
		{
		case '1':
		{
			system("cls");
			manager.managerchoice();
			break;
		}
		case '2':
		{
			system("cls");
			customer.customerchoice();
			break;
		}
		case '3':
		{
			cout << "\n\t\t\t\tTHANKS FOR USING THIS PROGRAM\n";
			cout << "\n\t\t\t\tPress Any Key To Contineue\n";
			_getch();
			exit(0);

		}
		default:
		{
			bankchoice();
		}
		}
	} while (DECISION != '3');
}
