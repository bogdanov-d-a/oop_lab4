#pragma once

#include "Solid.h"

class CCylinder:
	public CSolid
{
public:
	CCylinder(double density, double baseRadius, double height);

	double GetBaseRadius() const;
	double GetHeight() const;
	double GetVolume() const override;

private:
	double m_baseRadius, m_height;
};
