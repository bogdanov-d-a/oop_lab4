#include "stdafx.h"
#include "Building.h"
#include "RawDataUtils.h"
#include "University.h"
#include "Company.h"
#include "Utils.h"

using namespace std;

CBuilding::CBuilding(string const& name)
	:m_name(name)
{}

CBuilding::~CBuilding()
{}

CBuilding::CBuilding(istream &in)
	:m_name(RawData::ReadString(in))
{}

unique_ptr<CBuilding> CBuilding::CreateFromRawData(std::istream &in)
{
	const Type type = CHAR_TO_TYPE.at(GetCharFromStream(in));

	switch (type)
	{
	case Type::UNIVERSITY:
		return unique_ptr<CBuilding>(new CUniversity(in));
	case Type::COMPANY:
		return unique_ptr<CBuilding>(new CCompany(in));
	default:
		throw runtime_error("Incorrect building type");
	}
}

void CBuilding::WriteRawData(ostream &out) const
{
	out.put(TYPE_TO_CHAR.at(GetType()));
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

const std::map<CBuilding::Type, char> CBuilding::TYPE_TO_CHAR = {
	{ Type::UNIVERSITY, 'U' },
	{ Type::COMPANY, 'C' }
};

const std::map<char, CBuilding::Type> CBuilding::CHAR_TO_TYPE = {
	{ 'U', Type::UNIVERSITY },
	{ 'C', Type::COMPANY }
};
