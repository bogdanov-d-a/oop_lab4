#include "stdafx.h"
#include "Building.h"
#include "RawDataUtils.h"

using namespace std;

CBuilding::CBuilding(string const& name)
	:m_name(name)
{}

CBuilding::~CBuilding()
{}

CBuilding::CBuilding(istream &in)
	:m_name(RawData::ReadString(in))
{}

void CBuilding::WriteRawData(ostream &out) const
{
	RawData::WriteString(m_name, out);
}

string CBuilding::GetName() const
{
	return m_name;
}

string CBuilding::ToString() const
{
	return ("Name = " + m_name);
}

void CBuilding::SetName(string const& newName)
{
	m_name = newName;
}
