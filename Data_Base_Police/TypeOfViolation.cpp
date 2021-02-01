#include "TypeOfViolation.h"

TypeOfViolation::TypeOfViolation()
{
	violation = "";
	sizeFine = 0;
}

TypeOfViolation::TypeOfViolation(string V, int S)
{
	violation = V;
	sizeFine = S;
}

TypeOfViolation::~TypeOfViolation()
{
}

void TypeOfViolation::Print()
{
	cout << "Violation type: " << violation << endl;
	cout << "Fine size: " << sizeFine << " hrn" << endl;
}

void TypeOfViolation::SetParametrs(string V, int S)
{
	violation = V;
	sizeFine = S;
}
