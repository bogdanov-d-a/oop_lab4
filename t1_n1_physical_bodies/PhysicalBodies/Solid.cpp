#include "stdafx.h"
#include "Solid.h"

using namespace std;

CSolid::CSolid(double density)
	:m_density(density)
{
	if (density <= 0)
	{
		throw invalid_argument("Density should be positive");
	}
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
