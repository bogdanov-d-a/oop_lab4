#pragma once

#include "BuildingRelatedPerson.h"
#include "Building.h"

class CPersonsAndBuildings
{
public:
	void PrintUniversityList() const;
	void PrintCompanyList() const;
	void RenameUniversity();
	void RenameCompany();

private:
	typedef std::list<std::shared_ptr<CBuildingRelatedPerson>> Persons;
	typedef std::list<std::shared_ptr<CBuilding>> Buildings;

	Persons m_persons;
	Buildings m_buildings;

	Buildings::const_iterator FindBuildingByName(CBuilding::Type type, std::string name) const;
	Buildings::iterator FindBuildingByName(CBuilding::Type type, std::string name);
	void PrintBuildingList(CBuilding::Type type) const;
	void RenameBuilding(CBuilding::Type type);
	static void ThrowNotFoundException(std::string const& objName);
	static void ThrowAlreadyExistsException(std::string const& objName);
};
