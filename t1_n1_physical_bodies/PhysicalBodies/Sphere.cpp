#include "stdafx.h"
#include "Sphere.h"

using namespace std;

CSphere::CSphere(double density, double radius)
	:CSolid(density)
	,m_radius(radius)
{
	if (radius <= 0)
	{
		throw invalid_argument("Radius should be positive");
	}
}

double CSphere::GetRadius() const
{
	return m_radius;
}

double CSphere::GetVolume() const
{
	return ((4.0 / 3) * M_PI * pow(m_radius, 3));
}