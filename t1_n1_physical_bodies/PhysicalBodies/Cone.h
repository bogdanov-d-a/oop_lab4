#pragma once

#include "Solid.h"

class CCone:
	public CSolid
{
public:
	CCone(double density, double baseRadius, double height);

	double GetBaseRadius() const;
	double GetHeight() const;
	double GetVolume() const override;

private:
	double m_baseRadius, m_height;
	std::string GetName() const override;
};
