#include "stdafx.h"
#include "Cylinder.h"

using namespace std;

CCylinder::CCylinder(double density, double baseRadius, double height)
	:CSolid(density)
	,m_baseRadius(baseRadius)
	,m_height(height)
{}

double CCylinder::GetBaseRadius() const
{
	return m_baseRadius;
}

double CCylinder::GetHeight() const
{
	return m_height;
}

double CCylinder::GetVolume() const
{
	return (M_PI * pow(m_baseRadius, 2) * m_height);
}

string CCylinder::GetName() const
{
	return "Cylinder";
}
