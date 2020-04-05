#include <iostream>
#include <string>
#include "Worker.h"
#include "Engineer.h"

using namespace std;

int main()
{
	Worker* B = new Worker("Jonny",35,Person::Male,0,"Office",40,25);
	//B->PrintInfo(); cout << endl;
	//B->CalculateSalary();
	//B->PrintInfo(); cout << endl;
	Engineer* C = new Engineer("Edward",21,Person::Male,0,"Factory",32,78.5);
	//C->PrintInfo(); cout << endl;
	//C->CalculateSalary();
	//C->PrintInfo(); cout << endl;
	Engineer* D = new Engineer("Alex", 23, Person::Female, 0, "Home", 27, 73.5);
	//D->PrintInfo(); cout << endl;
	//D->CalculateSalary();
	//D->PrintInfo(); cout << endl;
	Worker* E = new Worker("Elizabeth", 31, Person::Female, 0, "Office", 48, 30);
	//E->PrintInfo(); cout << endl;
	//E->CalculateSalary();
	//E->PrintInfo(); cout << endl;

	string rwformat = "txt";
	int menu = 10;
	int choice = 0;
	int choice_2 = 0;
	int person_i = 0;
	Person* person = B;
	string name;
	bool gender;
	int age;
	int i;
	int hours=0;
	int points = 0;
	double coef = 0;

	while (menu)
	{
		system("cls");
		cout << "Number of persons: " << Person::GetCount() << endl << "\nMenu:\t\t" << "format:" << rwformat.c_str() << "\n1.Add new person\n2.Edit person\n3.Delete person\n4.Show person's info\n5.Show all persons\n6.Calculate salary\n7.Save persons data\n8.Read persons data\n9.Change read/write format\n0.Exit\n";
		cin >> menu;
		switch(menu)
		{
		case 1:
			while (true)
			{
				system("cls");
				cout << "Menu:\n1.Add worker\n2.Add engineer\n";
				cin >> choice;
				if (choice == 1)
				{
					person = new Worker("Name");
					break;
				}
				if (choice == 2)
				{
					person = new Engineer("Name");
					break;
				}
			}
			name = "Name";
			system("cls");
			cout << "Enter name:\n";
			cin >> name;
			person->SetName(name);

			age = 0;
			system("cls");
			cout << "Enter age:\n";
			cin >> age;
			person->SetAge(age);

			if (choice == 1)
			{
				hours = 0;
				system("cls");
				cout << "Enter work hours:\n";
				cin >> hours;
				static_cast<Worker*>(person)->SetHours(hours);

				coef = 0;
				system("cls");
				cout << "Enter payment per hour:\n";
				cin >> coef;
				static_cast<Worker*>(person)->SetCoef(coef);
			}
			if (choice == 2)
			{
				points = 0;
				system("cls");
				cout << "Enter work points:\n";
				cin >> points;
				static_cast<Engineer*>(person)->SetPoints(points);

				coef = 0;
				system("cls");
				cout << "Enter payment per point:\n";
				cin >> coef;
				static_cast<Engineer*>(person)->SetCoef(coef);
			}

			gender = Person::Male;
			choice = 3;
			while (!(choice == 1 || choice == 2))
			{
				system("cls");
				cout << "Choose gender:\n1.Male\n2.Female\n";
				cin >> choice;
			}
			(choice == 1) ? person->SetGender(Person::Male) : person->SetGender(Person::Female);


			break;
		case 2:
			system("cls");
			cout << "Select person to edit:\n";
			for (i = 0; i < Person::GetCount(); i++)
			{
				cout << i + 1 << ". " << (*person)[i].GetName() << endl;
			}
			person_i = -1;
			do
			{
				cin >> person_i;
				person_i--;
			} while (person_i >= Person::GetCount() && person_i > 0);
			if ((*person)[person_i].GetType() == "Worker")
			{
				cout << "\n Select field to edit:\n1.Name\n2.Age\n3.Gender\n4.Work hours\n5.Hour coefficient\n0.Menu\n";
				cin >> choice;
				switch (choice)
				{
				case 1:
					system("cls");
					cout << "Enter name:\n";
					cin >> name;
					(*person)[person_i].SetName(name);
					break;
				case 2:
					system("cls");
					cout << "Enter age:\n";
					cin >> age;
					(*person)[person_i].SetAge(age);
					break;
				case 3:
					gender = Person::Male;
					choice_2 = 3;
					while (!(choice_2 == 1 || choice_2 == 2))
					{
						system("cls");
						cout << "Choose gender:\n1.Male\n2.Female\n";
						cin >> choice_2;
					}
					(choice_2 == 1) ? (*person)[person_i].SetGender(Person::Male) : (*person)[person_i].SetGender(Person::Female);
					break;
				case 4:
					system("cls");
					cout << "Enter hours:\n";
					cin >> hours;
					static_cast<Worker*>(&(*person)[person_i])->SetHours(hours);
					break;
				case 5:
					system("cls");
					cout << "Enter hour coefficient:\n";
					cin >> coef;
					static_cast<Worker*>(&(*person)[person_i])->SetCoef(coef);
					break;
				}
			}
			else
			{
				cout << "\n Select field to edit:\n1.Name\n2.Age\n3.Gender\n4.Work points\n5.Point coefficient\n0.Menu\n";
				cin >> choice;
				switch (choice)
				{
				case 1:
					system("cls");
					cout << "Enter name:\n";
					cin >> name;
					(*person)[person_i].SetName(name);
					break;
				case 2:
					system("cls");
					cout << "Enter age:\n";
					cin >> age;
					(*person)[person_i].SetAge(age);
					break;
				case 3:
					gender = Person::Male;
					choice_2 = 3;
					while (!(choice_2 == 1 || choice_2 == 2))
					{
						system("cls");
						cout << "Choose gender:\n1.Male\n2.Female\n";
						cin >> choice_2;
					}
					(choice_2 == 1) ? (*person)[person_i].SetGender(Person::Male) : (*person)[person_i].SetGender(Person::Female);
					break;
				case 4:
					system("cls");
					cout << "Enter work points:\n";
					cin >> points;
					static_cast<Engineer*>(&(*person)[person_i])->SetPoints(points);
					break;
				case 5:
					system("cls");
					cout << "Enter work coefficient:\n";
					cin >> coef;
					static_cast<Engineer*>(&(*person)[person_i])->SetCoef(coef);
					break;
				}
			}
			break;
		case 3:
			system("cls");
			cout << "Select person to delete:\n";
			for (i = 0; i < Person::GetCount(); i++)
			{
				cout << i + 1 << ". " << (*person)[i].GetName() << endl;
			}
			person_i = -1;
			do
			{
				cin >> person_i;
				person_i--;
			} while (person_i >= Person::GetCount() && person_i > 0);
			delete &(*person)[person_i];
			break;
		case 4:
			system("cls");
			cout << "Select person to show info:\n";
			person = person->First();
			for (i = 0; i < Person::GetCount(); i++)
			{
				cout << i + 1 << ". " << person->GetName() << endl;
				person = person->Next();
			}
			person_i = -1;
			do
			{
				cin >> person_i;
				person_i--;
			} while (person_i >= Person::GetCount() && person_i > 0);
			system("cls");
			(*person)[person_i].PrintInfo();
			system("pause");
			//cout << "\n Press any button to continue..\n";
			//cin >> choice_2;
			break;
		case 5:
			system("cls");
			for (i = 0; i < Person::GetCount(); i++)
			{
				(*person)[i].PrintInfo();
				cout << endl;
			}
			system("pause");
			//cout << "\n Press any button to continue..\n";
			//cin >> choice_2;
			break;
		case 6:
			system("cls");
			for (i = 0; i < Person::GetCount(); i++)
			{
				if ((*person)[i].GetType() == "Worker")
				{
					static_cast<Worker*>(&(*person)[i])->CalculateSalary();
				}
				if ((*person)[i].GetType() == "Engineer")
				{
					static_cast<Engineer*>(&(*person)[i])->CalculateSalary();
				}

				cout << endl;
			}
			system("pause");
			//cout << "\n Press any button to continue..\n";
			//cin >> choice_2;
			break;
		case 7:
			if (rwformat == "txt")
				person->SaveInTxt("persons.txt");
			if (rwformat == "bin")
				person->SaveInBin("persons.bin");
			system("pause");
			break;
		case 8:
			if (rwformat == "txt")
				person->OpenFromTxt("persons.txt");
			if (rwformat == "bin")
				person->OpenFromBin("persons.bin");
			system("pause");
			break;
		case 9:
			if (rwformat == "txt")
				rwformat = "bin";
			else if (rwformat == "bin")
				rwformat = "txt";
			break;
		}

	}
	return 0;
}