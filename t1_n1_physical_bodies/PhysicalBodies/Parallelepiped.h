#pragma once

#include "Solid.h"

class CParallelepiped:
	public CSolid
{
public:
	CParallelepiped(double density, double width, double height, double depth);

	double GetWidth() const;
	double GetHeight() const;
	double GetDepth() const;
	double GetVolume() const override;

private:
	double m_width, m_height, m_depth;
	static void ThrowOnBadDimension(const std::string &name, double value);
};
