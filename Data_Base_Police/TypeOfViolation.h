#pragma once

#include <iostream>
#include <string>

using namespace std;

class TypeOfViolation
{
private:
	string violation;
	int sizeFine;

public:
	TypeOfViolation();
	TypeOfViolation(string V, int S);
	~TypeOfViolation();

	void Print();
	string GetViolation() { return violation; }
	int GetSF() { return sizeFine; }
	void SetParametrs(string V, int S);

};