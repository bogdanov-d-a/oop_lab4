#include "stdafx.h"
#include "BuildingRelatedPerson.h"
#include "RawDataUtils.h"
#include "Utils.h"

using namespace std;

CBuildingRelatedPerson::CBuildingRelatedPerson(Gender gender, unsigned age,
	string const& name, unsigned height, unsigned weight, shared_ptr<CBuilding> const& building)
	:CPerson(gender, age, name, height, weight)
	,m_building(building)
{}

CBuildingRelatedPerson::~CBuildingRelatedPerson()
{}

CBuildingRelatedPerson::CBuildingRelatedPerson(istream &in,
	function<shared_ptr<CBuilding>(string const& name, CBuilding::Type type)> getBuilding)
	:CPerson(in)
{
	const CBuilding::Type type = CBuilding::CHAR_TO_TYPE.at(GetCharFromStream(in));
	const string name = RawData::ReadString(in);
	m_building = getBuilding(name, type);
}

void CBuildingRelatedPerson::WriteRawData(ostream &out) const
{
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
