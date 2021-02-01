#include "Func.h"

using namespace std;

int stateM;

void Menu()
{
	cout << "Menu\n"
		<< "(0) Exit\n"
		<< "(1) Add\n"
		<< "(2) Delete\n"
		<< "(3) Change intruder parametrs\n"
		<< "(4) Get violation info\n"
		<< "(5) Get all car owners info\n"
		<< "(6) Get POMENYAT info\n"
		<< "Your choice: ";
	cin >> stateM;
}

int main()
{
	string InputCarOwner = { "InputCarOwner.txt" }, InputViolationLog = { "InputViolationLog.txt" };
	string OutputCarOwner = { "OutputCarOwner.txt" }, OutputViolationLog = { "OutputViolationLog.txt" };

	int kolCarOwner = KolElFromFile(InputCarOwner), kolViolationLog = KolElFromFile(InputViolationLog);

	CarOwner* C = new CarOwner[kolCarOwner];
	ViolationLog* V = new ViolationLog[kolViolationLog];

	ReadFromFileAboutCarOwner(C, InputCarOwner);
	ReadFromFileAboutViolationLog(V, C, kolCarOwner, InputViolationLog);

	//system("pause");
	system("cls");
	Menu();

	while (stateM != 0)
	{
		if (stateM == 1)
		{
			string S, N, P;
			Address A;
			string M;
			int Num;
			int newKolCarOwner = kolCarOwner + 1;
			CarOwner* C1 = new CarOwner[newKolCarOwner];
			ReadFromFileAboutCarOwner(C1, InputCarOwner);
			cout << "Enter FIO: ";
			cin >> S >> N >> P;
			cout << "Enter address (street -> house -> apartment): ";
			cin >> A.street >> A.house >> A.apartment;
			cout << "Enter car model: ";
			cin >> M;
			cout << "Enter car number: ";
			cin >> Num;

			C1[newKolCarOwner - 1].SetParametrs(S, N, P, A, M, Num);
			WriteInFileInputCarOwner(newKolCarOwner, InputCarOwner, C1);

			kolCarOwner = KolElFromFile(InputCarOwner);
			CarOwner* C = new CarOwner[kolCarOwner];
			ReadFromFileAboutCarOwner(C, InputCarOwner);
			system("pause");
			system("cls");
			Menu();
			system("cls");
		}
		if (stateM == 2)
		{
			system("cls");
			kolCarOwner = KolElFromFile(InputCarOwner);
			CarOwner* C = new CarOwner[kolCarOwner];
			ReadFromFileAboutCarOwner(C, InputCarOwner);

			string S = "", N = "", P = "";
			Address A;
			A.apartment = 0; A.house = 0; A.street = "";
			string M = "";
			int Num = 0;

			int indexDel;

			cout << "Select the number of the car owner who you want to delete from 1 to " << kolCarOwner << " : ";
			cin >> indexDel;
			C[indexDel - 1].SetParametrs(S, N, P, A, M, Num);
			WriteInFileInputCarOwner(InputCarOwner, C, kolCarOwner);

			kolCarOwner = KolElFromFile(InputCarOwner);
			C = new CarOwner[kolCarOwner];
			ReadFromFileAboutCarOwner(C, InputCarOwner);

			system("Pause");
			system("cls");
			Menu();
			system("cls");
		}
		if (stateM == 3)
		{
			system("cls");
			kolCarOwner = KolElFromFile(InputCarOwner);
			CarOwner* C = new CarOwner[kolCarOwner];
			string S, N, P;
			Address A;
			string M;
			int Num;

			int index;
			cout << "Enter the number of the owner whose data you want to change from 1 to "<<kolCarOwner<<" : ";
			cin >> index;

			cout << "Enter FIO: ";
			cin >> S >> N >> P;
			cout << "Enter address (street -> house -> apartment): ";
			cin >> A.street >> A.house >> A.apartment;
			cout << "Enter car model: ";
			cin >> M;
			cout << "Enter car number: ";
			cin >> Num;

			ReadFromFileAboutCarOwner(C, InputCarOwner);

			C[index - 1].SetParametrs(S, N, P, A, M, Num);
			

			kolCarOwner = KolElFromFile(InputCarOwner);
			WriteInFileInputCarOwner(kolCarOwner, InputCarOwner, C);
			C = nullptr;
			C = new CarOwner[kolCarOwner];
			ReadFromFileAboutCarOwner(C, InputCarOwner);

			system("pause");
			system("cls");
			Menu();
			system("cls");
		}
		if (stateM == 4)
		{
			system("cls");
			int index, sum = 0;
			bool fs = false, fN = false, fP = false, f = false;
			cout << "Enter the number of the car owner, the amount of fines you need to find out from 1 to " << kolCarOwner << " : ";
			cin >> index;

			for (int i = 0; i < kolViolationLog; i++)
			{
				for (int j = 0; j < kolCarOwner; j++)
				{
					if (C[index - 1].GetSurname() == V[i].GetSurname()[j] && C[index - 1].GetName() == V[i].GetName()[j] && C[index - 1].GetPatronymic() ==
						V[i].GetPatronymic()[j])
					{
						f = true;
						sum += V[i].GetType().GetSF();
					}
				}
			}

			if (f)
			{
				cout << "The sum of the penalties is " << sum << " hrns\n";
			}
			else
			{
				cout << "No matches found or no penalties found\n";
			}

			system("pause");
			system("cls");
			Menu();
			system("cls");
		}
		if (stateM == 5)
		{
			system("cls");
			bool w;
			cout << "Output file to console (1/0): ";
			cin >> w;
			system("cls");

			kolCarOwner - KolElFromFile(InputCarOwner);
			CarOwner* C = new CarOwner[kolCarOwner];
			ReadFromFileAboutCarOwner(C, InputCarOwner);

			if (w)
			{
				for (int i = 0; i < kolCarOwner; i++)
				{
					cout << "Car owner #" << i + 1 << " :\n";
					C[i].Print();
					cout << "**************\n"; 
				}
			}
			else
			{
				WriteInFileCarOwner(OutputCarOwner, C, kolCarOwner);
				cout << "Information record in file \"" << OutputCarOwner << "\"\n";
			}
			system("pause");
			system("cls");
			Menu();
			system("cls");
		}
		if (stateM == 6)
		{
			system("cls");

			bool w;
			cout << "Output file to console (1/0): ";
			cin >> w;
			system("cls");

			kolCarOwner = KolElFromFile(InputCarOwner);
			C = new CarOwner[kolCarOwner];
			ReadFromFileAboutCarOwner(C, InputCarOwner);

			if (w)
			{
				for (int i = 0; i < kolViolationLog; i++)
				{
					cout << "Violation #" << i + 1 << " \n";
					V[i].Print(kolCarOwner);
					cout << "************\n";
				}
			}
			else
			{
				WriteInFileViolationLog(OutputViolationLog, V, kolViolationLog, kolCarOwner);
				cout << "Information write in file \"" << OutputViolationLog << "\"\n";
			}
			system("pause");
			system("cls");
			Menu();
			system("cls");

			delete[] C;
			
		}
	}
}



