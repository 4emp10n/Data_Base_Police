#pragma once

#include <iostream>
#include <string>

#include "TypeOfViolation.h"
#include "CarOwner.h"

using namespace std;

struct Date
{
	int day,
		month,
		years;
};

class ViolationLog
{
private:
	Date date;
	string* surname,
		* name,
		* patronymic;
	TypeOfViolation type;

public:
	ViolationLog();
	ViolationLog(Date D, TypeOfViolation T, CarOwner* C, int n);
	~ViolationLog();

	Date GetDate() { return date; }
	string* GetSurname() { return surname; }
	string* GetName() { return name; }
	string* GetPatronymic() { return patronymic; }
	TypeOfViolation GetType() { return type; }

	void SetParametrs(Date D, TypeOfViolation T, CarOwner* C, int n);
	void AddToFile(string nameF, int n);
	void Print(int n);

};