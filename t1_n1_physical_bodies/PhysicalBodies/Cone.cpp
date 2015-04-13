#include "stdafx.h"
#include "Cone.h"

CCone::CCone(double density, double baseRadius, double height)
	:CSolid(density)
	,m_baseRadius(baseRadius)
	,m_height(height)
{
	ThrowOnNonPositiveValue("Base radius", baseRadius);
	ThrowOnNonPositiveValue("Height", height);
}

double CCone::GetBaseRadius() const
{
	return m_baseRadius;
}

double CCone::GetHeight() const
{
	return m_height;
}

double CCone::GetVolume() const
{
	return ((1.0 / 3) * (M_PI * pow(m_baseRadius, 2)) * m_height);
}
