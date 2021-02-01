#include "ViolationLog.h"

ViolationLog::ViolationLog()
{
	date.day = 0;
	date.month = 0;
	date.years = 0;
}

ViolationLog::ViolationLog(Date D, TypeOfViolation T, CarOwner* C, int n)
{
	surname = new string[n];
	name = new string[n];
	patronymic = new string[n];
	date.day = D.day;
	date.month = D.month;
	date.years = D.years;

	for (int i = 0; i < n; i++)
	{
		surname[i] = C[i].GetSurname();
		name[i] = C[i].GetName();
		patronymic[i] = C[i].GetPatronymic();
	}

	type.SetParametrs(T.GetViolation(), T.GetSF());
}

ViolationLog::~ViolationLog()
{
}

void ViolationLog::SetParametrs(Date D, TypeOfViolation T, CarOwner* C, int n)
{
	surname = new string[n];
	name = new string[n];
	patronymic = new string[n];
	date.day = D.day;
	date.month = D.month;
	date.years = D.years;

	for (int i = 0; i < n; i++)
	{
		surname[i] = C[i].GetSurname();
		name[i] = C[i].GetName();
		patronymic[i] = C[i].GetPatronymic();
	}

	type.SetParametrs(T.GetViolation(), T.GetSF());
}

void ViolationLog::AddToFile(string nameF, int n)
{
	ofstream fout(nameF, std::ios::app);
	
	if (fout.is_open())
	{
		fout<< "Violations data: " << date.day << " dd. " << date.month << " mm. " << date.years << " year. " << endl;

		for (int i = 0; i < n; i++)
		{
			if (surname[i] != "")
			{
				cout << "Violation FIO #" << i + 1 << " :" << surname[i] << "  " << name[i] << "  " << patronymic[i] << endl;
			}
		}
		fout << "Violation type: " << type.GetViolation() << endl;
		fout << "Fine size: " << type.GetSF() << "hrn" << endl;
		fout << "________\n";
	}
	else
	{
		cout << "Error open file\n";
	}
	fout.close();
}

void ViolationLog::Print(int n)
{
	cout << "Violations data: " << date.day << " dd. " << date.month << " mm. " << date.years << " year. " << endl;

	for (int i = 0; i < n; i++)
	{
		if (surname[i] != "")
		{
			cout << "Violation FIO #"  << i + 1 << " :" << surname[i] << "  " << name[i] << "  " << patronymic[i] << endl;
		}
	}
	type.Print();
}




