#include "stdafx.h"
#include "PersonsAndBuildings.h"
#include "Utils.h"

using namespace std;

void CPersonsAndBuildings::PrintUniversityList() const
{
	PrintBuildingList(CBuilding::Type::UNIVERSITY);
}

void CPersonsAndBuildings::PrintCompanyList() const
{
	PrintBuildingList(CBuilding::Type::COMPANY);
}

void CPersonsAndBuildings::RenameUniversity()
{
	RenameBuilding(CBuilding::Type::UNIVERSITY);
}

void CPersonsAndBuildings::RenameCompany()
{
	RenameBuilding(CBuilding::Type::COMPANY);
}

CPersonsAndBuildings::Buildings::const_iterator
CPersonsAndBuildings::FindBuildingByName(CBuilding::Type type, string name) const
{
	for (auto it = m_buildings.cbegin(); it != m_buildings.cend(); ++it)
	{
		auto &building = *it;

		if (building->GetType() == type && building->GetName() == name)
		{
			return it;
		}
	}

	return m_buildings.cend();
}

CPersonsAndBuildings::Buildings::iterator
CPersonsAndBuildings::FindBuildingByName(CBuilding::Type type, string name)
{
	for (auto it = m_buildings.begin(); it != m_buildings.end(); ++it)
	{
		auto &building = *it;

		if (building->GetType() == type && building->GetName() == name)
		{
			return it;
		}
	}

	return m_buildings.end();
}

void CPersonsAndBuildings::PrintBuildingList(CBuilding::Type type) const
{
	for (auto building : m_buildings)
	{
		if (building->GetType() == type)
		{
			cout << building->ToString() << endl;
		}
	}
}

void CPersonsAndBuildings::RenameBuilding(CBuilding::Type type)
{
	cout << "Enter old name: ";
	string oldName;
	getline(cin, oldName);

	auto target = FindBuildingByName(type, oldName);
	if (target == m_buildings.end())
	{
		ThrowNotFoundException(MakeFirstLetterUppercase(CBuilding::TYPE_TO_NAME.at(type)));
	}

	cout << "Enter new name: ";
	string newName;
	getline(cin, newName);

	const bool newExists = (FindBuildingByName(type, newName) != m_buildings.end());
	if (newExists)
	{
		ThrowAlreadyExistsException(MakeFirstLetterUppercase(CBuilding::TYPE_TO_NAME.at(type)));
	}

	(*target)->SetName(newName);
}

void CPersonsAndBuildings::ThrowNotFoundException(std::string const& objName)
{
	throw runtime_error(objName + " is not found");
}

void CPersonsAndBuildings::ThrowAlreadyExistsException(std::string const& objName)
{
	throw runtime_error(objName + " already exists");
}
