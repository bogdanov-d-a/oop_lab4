#pragma once

#include "Person.h"
#include "Building.h"

class CBuildingRelatedPerson:
	public CPerson
{
public:
	CBuildingRelatedPerson(Gender gender, unsigned age, std::string const& name,
		unsigned height, unsigned weight, std::shared_ptr<CBuilding> const& building);

	virtual ~CBuildingRelatedPerson();

	CBuildingRelatedPerson(std::istream &in,
		std::function<std::shared_ptr<CBuilding>(std::string const& name, CBuilding::Type type)> getBuilding);

	void WriteRawData(std::ostream &out) const override;

	std::shared_ptr<CBuilding> GetBuilding() const;
	virtual void SetBuilding(std::shared_ptr<CBuilding> const& newBuilding);

private:
	std::weak_ptr<CBuilding> m_building;
};
