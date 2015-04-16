#include "stdafx.h"
#include "Sphere.h"

using namespace std;

CSphere::CSphere(double density, double radius)
	:CSolid(density)
	,m_radius(radius)
{
	ThrowOnNonPositiveValue("Radius", radius);
}

double CSphere::GetRadius() const
{
	return m_radius;
}

double CSphere::GetVolume() const
{
	return ((4.0 / 3) * M_PI * pow(m_radius, 3));
}

string CSphere::GetName() const
{
	return "Sphere";
}
