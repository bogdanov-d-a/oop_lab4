#pragma once

#include "Body.h"

class CSolid:
	public CBody
{
public:
	CSolid(double density);
	virtual ~CSolid();

	double GetDensity() const override;
	double GetMass() const override;

private:
	double m_density;

protected:
	static void ThrowOnNonPositiveValue(const std::string &name, double value);
};
