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
	std::string ToString() const override;

private:
	double m_width, m_height, m_depth;
	std::string GetName() const override;
};
