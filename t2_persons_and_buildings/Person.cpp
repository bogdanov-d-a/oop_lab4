#include "stdafx.h"
#include "Person.h"
#include "Utils.h"

using namespace std;

CPerson::CPerson(Gender gender, unsigned age, string const& name, unsigned height, unsigned weight)
	:m_gender(gender)
	,m_age(age)
	,m_name(name)
	,m_height(height)
	,m_weight(weight)
{}

CPerson::~CPerson()
{}

CPerson::Gender CPerson::GetGender() const
{
	return m_gender;
}

unsigned CPerson::GetAge() const
{
	return m_age;
}

string CPerson::GetName() const
{
	return m_name;
}

unsigned CPerson::GetHeight() const
{
	return m_height;
}

unsigned CPerson::GetWeight() const
{
	return m_weight;
}

bool CPerson::SetAge(unsigned newAge)
{
	return AssignIfGreater(m_age, newAge);
}

void CPerson::SetName(string const& newName)
{
	m_name = newName;
}

bool CPerson::SetHeight(unsigned newHeight)
{
	return AssignIfGreater(m_height, newHeight);
}

void CPerson::SetWeight(unsigned newWeight)
{
	m_weight = newWeight;
}
