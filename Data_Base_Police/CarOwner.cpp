#include "CarOwner.h"

CarOwner::CarOwner()
{
	name = "";
	surname = "";
	patronymic = "";
	address.apartment = 0;
	address.house = 0;
	address.street = "";
	modelCar = "";
	number = 0;

}

CarOwner::CarOwner(string S, string N, string P, Address A, string M, int NUM)
{
	name = N;
	surname = S;
	patronymic = P;
	address.apartment = A.apartment;
	address.house = A.house;
	address.street = A.street;
	modelCar = M;
	number = NUM;
}

CarOwner::~CarOwner()
{
}

void CarOwner::Print()
{
	if (surname != "")
	{
		cout << "FIO: " << surname << "  " << name << "  " << patronymic << endl;
		cout << "Address: " << address.street << "street,   " << address.house << "house,  " << address.street << "appartment." << endl;
		cout << "Car Model: " << modelCar << endl;
		cout << "Number: " << number << endl;
	}
}

void CarOwner::SetParametrs(string S, string N, string P, Address A, string M, int NUM)
{
	name = N;
	surname = S;
	patronymic = P;
	address.apartment = A.apartment;
	address.house = A.house;
	address.street = A.street;
	modelCar = M;
	number = NUM;
}

void CarOwner::AddtoFile(string NameF)
{
	ofstream fout(NameF, std::ios::app);

	if (fout.is_open())
	{
		fout << "FIO: " << surname << "  " << name << "  " << patronymic << endl;
		fout << "Address: " << address.street << "street,   " << address.house << "house,  " << address.street << "appartment." << endl;
		fout << "Car Model: " << modelCar << endl;
		fout << "Number: " << number << endl;
		fout << "__________________" << endl;
	}
	else
	{
		cout << "Erroe" << endl;
	}
	fout.close();
}

void CarOwner::AddtoFile1(string NameF)
{
	ofstream fout(NameF, std::ios::app);

	if (fout.is_open())
	{
		if (surname != "")
		{
			fout << surname << " " << name << " " << patronymic << endl;
			fout << address.street << " " << address.house << " " << address.apartment << " " << endl;
			fout << modelCar << endl;
			fout << number << endl;
		}	
	}

	else
	{
		cout << "Error open file.\n";
	}

	fout.close();
}

