#include "stdafx.h"
#include "Solid.h"

using namespace std;

CSolid::CSolid(double density)
	:m_density(density)
{
	ThrowOnNonPositiveValue("Density", density);
}

CSolid::~CSolid()
{}

double CSolid::GetDensity() const
{
	return m_density;
}

double CSolid::GetMass() const
{
	return (GetVolume() * GetDensity());
}

void CSolid::ThrowOnNonPositiveValue(const string &name, double value)
{
	if (value <= 0)
	{
		throw invalid_argument(name + " should be positive");
	}
}
