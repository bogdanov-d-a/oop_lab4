#include "stdafx.h"
#include "University.h"

using namespace std;

CUniversity::CUniversity(string const& name)
	:m_name(name)
{}

CUniversity::~CUniversity()
{}

string CUniversity::GetName() const
{
	return m_name;
}

void CUniversity::SetName(string const& newName)
{
	m_name = newName;
}
