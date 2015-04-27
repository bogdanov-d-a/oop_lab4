#include "stdafx.h"
#include "BuildingRelatedPerson.h"
#include "RawDataUtils.h"
#include "Utils.h"
#include "Student.h"
#include "Worker.h"

using namespace std;

CBuildingRelatedPerson::CBuildingRelatedPerson(Gender gender, unsigned age,
	string const& name, unsigned height, unsigned weight, shared_ptr<CBuilding> const& building)
	:CPerson(gender, age, name, height, weight)
	,m_building(building)
{}

CBuildingRelatedPerson::~CBuildingRelatedPerson()
{}

CBuildingRelatedPerson::CBuildingRelatedPerson(istream &in, GetBuildingFunction getBuilding)
	:CPerson(in)
{
	const CBuilding::Type type = CBuilding::CHAR_TO_TYPE.at(GetCharFromStream(in));
	const string name = RawData::ReadString(in);
	m_building = getBuilding(name, type);
}

unique_ptr<CBuildingRelatedPerson>
CBuildingRelatedPerson::CreateFromRawData(istream &in, GetBuildingFunction getBuilding)
{
	const Type type = CHAR_TO_TYPE.at(GetCharFromStream(in));

	switch (type)
	{
	case Type::STUDENT:
		return unique_ptr<CBuildingRelatedPerson>(new CStudent(in, getBuilding));
	case Type::WORKER:
		return unique_ptr<CBuildingRelatedPerson>(new CWorker(in, getBuilding));
	default:
		throw runtime_error("Incorrect building related person type");
	}
}

void CBuildingRelatedPerson::WriteRawData(ostream &out) const
{
	out.put(TYPE_TO_CHAR.at(GetType()));
	CPerson::WriteRawData(out);
	out.put(CBuilding::TYPE_TO_CHAR.at(GetBuilding()->GetType()));
	RawData::WriteString(GetBuilding()->GetName(), out);
}

shared_ptr<CBuilding> CBuildingRelatedPerson::GetBuilding() const
{
	if (auto sharedPtr = m_building.lock())
	{
		return sharedPtr;
	}
	else
	{
		throw runtime_error("Building doesn't exist");
	}
}

void CBuildingRelatedPerson::SetBuilding(shared_ptr<CBuilding> const& newBuilding)
{
	m_building = newBuilding;
}

const map<CBuildingRelatedPerson::Type, char> CBuildingRelatedPerson::TYPE_TO_CHAR = {
	{ Type::STUDENT, 'S' },
	{ Type::WORKER, 'W' }
};

const map<char, CBuildingRelatedPerson::Type> CBuildingRelatedPerson::CHAR_TO_TYPE = {
	{ 'S', Type::STUDENT },
	{ 'W', Type::WORKER }
};
