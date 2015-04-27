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
	void RemoveUniversity();
	void RemoveCompany();
	void PrintUniversityStudentList() const;
	void PrintCompanyWorkerList() const;
	void AddUniversity();
	void AddCompany();
	void PrintStudentList() const;
	void PrintWorkerList() const;
	void EditStudent();
	void EditWorker();

private:
	typedef std::list<std::shared_ptr<CBuildingRelatedPerson>> Persons;
	typedef std::list<std::shared_ptr<CBuilding>> Buildings;

	Persons m_persons;
	Buildings m_buildings;

	Buildings::const_iterator FindBuildingByName(CBuilding::Type type, std::string name) const;
	Buildings::iterator FindBuildingByName(CBuilding::Type type, std::string name);
	void PrintBuildingList(CBuilding::Type type) const;
	void RenameBuilding(CBuilding::Type type);
	void RemoveBuilding(CBuilding::Type type);
	void PrintBuildingPersons(CBuilding::Type type) const;
	static void ThrowNotFoundException(std::string const& objName);
	static void ThrowAlreadyExistsException(std::string const& objName);

	void FindBuildingPersons(std::shared_ptr<CBuilding> const& building,
		std::function<void(Persons::const_iterator)> cb) const;

	void FindBuildingPersons(std::shared_ptr<CBuilding> const& building,
		std::function<void(Persons::iterator)> cb);

	void PrintPersonList(CBuildingRelatedPerson::Type type) const;
	Persons::iterator GetPersonByID(CBuildingRelatedPerson::Type type, size_t id);
};
