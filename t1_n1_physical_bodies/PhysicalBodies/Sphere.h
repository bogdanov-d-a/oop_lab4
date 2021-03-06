#pragma once

#include "Solid.h"

class CSphere:
	public CSolid
{
public:
	CSphere(double density, double radius);

	double GetRadius() const;
	double GetVolume() const override;
	std::string ToString() const override;

private:
	double m_radius;
	std::string GetName() const override;
};
