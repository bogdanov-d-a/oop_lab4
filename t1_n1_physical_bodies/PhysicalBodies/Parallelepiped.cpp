#include "stdafx.h"
#include "Parallelepiped.h"

using namespace std;

CParallelepiped::CParallelepiped(double density, double width, double height, double depth)
	:CSolid(density)
	,m_width(width)
	,m_height(height)
	,m_depth(depth)
{
	ThrowOnBadDimension("Width", width);
	ThrowOnBadDimension("Height", height);
	ThrowOnBadDimension("Depth", depth);
}

double CParallelepiped::GetWidth() const
{
	return m_width;
}

double CParallelepiped::GetHeight() const
{
	return m_height;
}

double CParallelepiped::GetDepth() const
{
	return m_depth;
}

double CParallelepiped::GetVolume() const
{
	return (m_width * m_height * m_depth);
}

void CParallelepiped::ThrowOnBadDimension(const std::string &name, double value)
{
	if (value <= 0)
	{
		throw invalid_argument(name + " should be positive");
	}
}
