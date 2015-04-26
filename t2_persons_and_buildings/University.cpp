#include "stdafx.h"
#include "University.h"

using namespace std;

CUniversity::CUniversity(string const& name)
	:CBuilding(name)
{}

CUniversity::Type CUniversity::GetType() const
{
	return Type::UNIVERSITY;
}
