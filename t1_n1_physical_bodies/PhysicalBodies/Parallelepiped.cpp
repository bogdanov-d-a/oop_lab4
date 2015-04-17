#include "stdafx.h"
#include "Parallelepiped.h"

using namespace std;

CParallelepiped::CParallelepiped(double density, double width, double height, double depth)
	:CSolid(density)
	,m_width(width)
	,m_height(height)
	,m_depth(depth)
{
	ThrowOnNonPositiveValue("Width", width);
	ThrowOnNonPositiveValue("Height", height);
	ThrowOnNonPositiveValue("Depth", depth);
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

string CParallelepiped::ToString() const
{
	return (
		CSolid::ToString() +
		", width = " + to_string(GetWidth()) +
		", height = " + to_string(GetHeight()) +
		", depth = " + to_string(GetDepth())
	);
}

string CParallelepiped::GetName() const
{
	return "Parallelepiped";
}
