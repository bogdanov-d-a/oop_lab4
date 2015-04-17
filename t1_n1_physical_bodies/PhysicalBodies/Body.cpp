#include "stdafx.h"
#include "Body.h"

using namespace std;

CBody::~CBody()
{}

string CBody::ToString() const
{
	return (
		GetName() +
		"; density = " + to_string(GetDensity()) +
		", volume = " + to_string(GetVolume()) +
		", mass = " + to_string(GetMass())
	);
}
