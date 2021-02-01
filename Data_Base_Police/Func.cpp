#include "Func.h"

using namespace std;

int KolElFromFile(string nameFile)
{
	ifstream fin(nameFile);
	int k;
	if (fin.is_open())
	{
		fin >> k;
	}
	else
	{
		cout << "Error open file.\n";
		return 1;
	}

	fin.close();
	return k;
}

void ReadFromFileAboutCarOwner(CarOwner* C, string nameFile)
{
	ifstream fin(nameFile);

	int k;
	string S, N, P;
	Address D;
	string M;
	int Num;

	if (fin.is_open())
	{
		fin >> k;
		for (int i = 0; i < k; i++)
		{
			fin >> S >> N >> P;
			fin >> D.street >> D.house >> D.apartment;
			fin >> M;
			fin >> Num;
			C[i].SetParametrs(S, N, P, D, M, Num);
		}
	}
	else
	{
		cout << "Error open file\n";
	}
	fin.close();
}

void ReadFromFileAboutViolationLog(ViolationLog* V, CarOwner* C, int n, string nameFile)
{
	ifstream fin(nameFile);

	int k;
	Date D;
	string Vi, S = "", N = "", P = "";
	int Ss;
	Address A;
	int* index = new int[n];
	CarOwner* c = new CarOwner[n];
	bool w;

	cout << "Enter which violation did the driver: \n";

	if (fin.is_open())
	{
		fin >> k;
		cout << "Drivers are numbered from 1 to " << n << endl;
		cout << "Further numbers of all penalties will be listed. Indicate who made them.\n(1/0) -> (did/ did'nt)\n\n";
		
		for (int i = 0; i < k; i++)
		{
			cout << "*_*_*_**_*_*_*___*_*_*_*\n";
			cout << "Fine number: " << i + 1 << ": \n";

			for (int j = 0; j < n; j++)
			{
				cout << "Has the car owner #" << j + 1 << " committed a violation? (1/0): ";
				cin >> w;
				if (w)
				{
					c[j].SetParametrs(C[j].GetSurname(), C[j].GetName(), C[j].GetPatronymic(), C[j].GetAddress(), C[j].GetModelCar(), C[j].GetNum());
				}
				else
				{
					A.apartment = 0;
					A.house = 0;
					A.street = "";
					c[j].SetParametrs(S, N, P, A, S, 0);
				}
			}
			fin >> D.day >> D.month >> D.years;
			fin >> Vi;
			fin >> Ss;

			TypeOfViolation T(Vi, Ss);
			V[i].SetParametrs(D, T, c, n);
		}
	}
	else
	{
		cout << "Error open file\n";
	}
	fin.close();
}

void WriteInFileCarOwner(string nameF, CarOwner* C, int n)
{
	ofstream fout(nameF, std::ios::out);

	if (fout.is_open())
	{
		for (int i = 0; i < n; i++)
		{
			C[i].AddtoFile(nameF);
		}
	}
	else
	{
		cout << "Error open file\n";
	}
	fout.close();
}

void WriteInFileInputCarOwner(string nameF, CarOwner* C, int n)
{
	ofstream fout(nameF, std::ios::out);

	if (fout.is_open())
	{
		fout << n - 1 << endl;
			for (int i = 0; i < n; i++)
			{
				C[i].AddtoFile1(nameF);
			}
	}
	else
	{
		cout << "Error open file\n";
	}
	fout.close();
}

void WriteInFileViolationLog(string nameF, ViolationLog* V, int n, int m)
{
	ofstream fout(nameF, std::ios::app);

	if (fout.is_open())
	{
		for (int i = 0; i < n; i++)
		{
			V[i].AddToFile(nameF, m);
		}
	}
	else
	{
		cout << "Error open\n";
	}

	fout.close();
}


void WriteInFileInputCarOwner(int n, string nameF, CarOwner* C)
{
	ofstream fout(nameF, std::ios::out);

	if (fout.is_open())
	{
		fout << n << endl;
		for (int i = 0; i < n; i++)
		{
			C[i].AddtoFile1(nameF);
		}
	}
	else
	{
		cout << "Error open file\n";
	}
	fout.close();
}
