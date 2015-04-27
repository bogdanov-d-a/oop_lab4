#include "stdafx.h"
#include "Person.h"
#include "Utils.h"
#include "RawDataUtils.h"

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

CPerson::CPerson(istream &in)
	:m_gender(CHAR_TO_GENDER.at(GetCharFromStream(in)))
	,m_age(RawData::ReadUnsigned(in))
	,m_name(RawData::ReadString(in))
	,m_height(RawData::ReadUnsigned(in))
	,m_weight(RawData::ReadUnsigned(in))
{}

void CPerson::WriteRawData(ostream &out) const
{
	out.put(GENDER_TO_CHAR.at(m_gender));
	RawData::WriteUnsigned(m_age, out);
	RawData::WriteString(m_name, out);
	RawData::WriteUnsigned(m_height, out);
	RawData::WriteUnsigned(m_weight, out);
}

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

const map<CPerson::Gender, char> CPerson::GENDER_TO_CHAR = {
	{ Gender::MALE, 'M' },
	{ Gender::FEMALE, 'F' }
};

const map<char, CPerson::Gender> CPerson::CHAR_TO_GENDER = {
	{ 'M', Gender::MALE },
	{ 'F', Gender::FEMALE }
};
