#include "stdafx.h"
#include "University.h"
#include "RawDataUtils.h"

using namespace std;

CUniversity::CUniversity(string const& name)
	:m_name(name)
{}

CUniversity::~CUniversity()
{}

CUniversity::CUniversity(istream &in)
	:m_name(RawData::ReadString(in))
{}

void CUniversity::WriteRawData(ostream &out) const
{
	RawData::WriteString(m_name, out);
}

string CUniversity::GetName() const
{
	return m_name;
}

string CUniversity::ToString() const
{
	return ("Name = " + m_name);
}

void CUniversity::SetName(string const& newName)
{
	m_name = newName;
}
