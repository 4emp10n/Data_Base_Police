#pragma once

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Address
{
	string street;
	int house;
	int apartment;
};

class CarOwner
{
private:
	string name,
		surname,
		patronymic;
	Address address;
	string modelCar;
	int number;

public:
	CarOwner();
	CarOwner(string S, string N, string P, Address A, string M, int NUM);
	~CarOwner();

	void Print();
	void SetParametrs(string S, string N, string P, Address A, string M, int NUM);

	string GetSurname() { return surname; }
	string GetName() { return name; }
	string GetPatronymic() { return patronymic; }
	Address GetAddress() { return address; }
	string GetModelCar(){ return modelCar; }
	int GetNum() { return number; };
	void AddtoFile(string NameF);
	void AddtoFile1(string NameF);



};