#include "stdafx.h"
#include "PersonsAndBuildings.h"
#include "Utils.h"
#include "University.h"
#include "Company.h"
#include "Student.h"

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

void CPersonsAndBuildings::RemoveUniversity()
{
	RemoveBuilding(CBuilding::Type::UNIVERSITY);
}

void CPersonsAndBuildings::RemoveCompany()
{
	RemoveBuilding(CBuilding::Type::COMPANY);
}

void CPersonsAndBuildings::PrintUniversityStudentList() const
{
	PrintBuildingPersons(CBuilding::Type::UNIVERSITY);
}

void CPersonsAndBuildings::PrintCompanyWorkerList() const
{
	PrintBuildingPersons(CBuilding::Type::COMPANY);
}

void CPersonsAndBuildings::AddUniversity()
{
	cout << "Enter name: ";
	string name;
	getline(cin, name);

	if (FindBuildingByName(CBuilding::Type::UNIVERSITY, name) != m_buildings.end())
	{
		ThrowAlreadyExistsException(MakeFirstLetterUppercase(CBuilding::TYPE_TO_NAME.at(CBuilding::Type::UNIVERSITY)));
	}

	m_buildings.push_back(shared_ptr<CBuilding>(new CUniversity(name)));
}

void CPersonsAndBuildings::AddCompany()
{
	cout << "Enter name: ";
	string name;
	getline(cin, name);

	if (FindBuildingByName(CBuilding::Type::COMPANY, name) != m_buildings.end())
	{
		ThrowAlreadyExistsException(MakeFirstLetterUppercase(CBuilding::TYPE_TO_NAME.at(CBuilding::Type::COMPANY)));
	}

	cout << "Enter web site: ";
	string webSite;
	getline(cin, webSite);

	m_buildings.push_back(shared_ptr<CBuilding>(new CCompany(name, webSite)));
}

void CPersonsAndBuildings::PrintStudentList() const
{
	PrintPersonList(CBuildingRelatedPerson::Type::STUDENT);
}

void CPersonsAndBuildings::PrintWorkerList() const
{
	PrintPersonList(CBuildingRelatedPerson::Type::WORKER);
}

void CPersonsAndBuildings::EditStudent()
{
	cout << "Enter ID: ";
	size_t id;
	cin >> id;

	CStudent *student = dynamic_cast<CStudent*>(GetPersonByID(CBuildingRelatedPerson::Type::STUDENT, id)->get());

	cout << "Choose field to edit: " << endl;
	cout << "1. Age" << endl;
	cout << "2. Name" << endl;
	cout << "3. Height" << endl;
	cout << "4. Weight" << endl;
	cout << "5. University" << endl;
	cout << "6. Grade" << endl;

	size_t action;
	cin >> action;

	switch (action)
	{
	case 1:
	{
		cout << "Enter new age: ";
		unsigned age;
		cin >> age;
		student->SetAge(age);
	}

	case 2:
	{
		cout << "Enter new name: ";
		string name;
		getline(cin, name);
		student->SetName(name);
	}

	case 3:
	{
		cout << "Enter new height: ";
		unsigned height;
		cin >> height;
		student->SetHeight(height);
	}

	case 4:
	{
		cout << "Enter new weight: ";
		unsigned weight;
		cin >> weight;
		student->SetWeight(weight);
	}

	case 5:
	{
		cout << "Enter new university name: ";
		string name;
		getline(cin, name);

		auto target = FindBuildingByName(CBuilding::Type::UNIVERSITY, name);
		if (target == m_buildings.end())
		{
			ThrowNotFoundException(MakeFirstLetterUppercase(CBuilding::TYPE_TO_NAME.at(CBuilding::Type::UNIVERSITY)));
		}

		student->SetBuilding(*target);
	}

	case 6:
	{
		cout << "Enter new grade: ";
		unsigned grade;
		cin >> grade;
		student->SetGrade(grade);
	}

	default:
		throw runtime_error("Wrong action");
	}
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

void CPersonsAndBuildings::RemoveBuilding(CBuilding::Type type)
{
	cout << "Enter name: ";
	string name;
	getline(cin, name);

	auto target = FindBuildingByName(type, name);
	if (target == m_buildings.end())
	{
		ThrowNotFoundException(MakeFirstLetterUppercase(CBuilding::TYPE_TO_NAME.at(type)));
	}

	FindBuildingPersons(*target, [this](Persons::iterator it){ m_persons.erase(it); });

	m_buildings.erase(target);
}

void CPersonsAndBuildings::PrintBuildingPersons(CBuilding::Type type) const
{
	cout << "Enter name: ";
	string name;
	getline(cin, name);

	auto target = FindBuildingByName(type, name);
	if (target == m_buildings.end())
	{
		ThrowNotFoundException(MakeFirstLetterUppercase(CBuilding::TYPE_TO_NAME.at(type)));
	}

	FindBuildingPersons(*target, [](Persons::const_iterator it){ cout << (*it)->ToString() << endl; });
}

void CPersonsAndBuildings::ThrowNotFoundException(std::string const& objName)
{
	throw runtime_error(objName + " is not found");
}

void CPersonsAndBuildings::ThrowAlreadyExistsException(std::string const& objName)
{
	throw runtime_error(objName + " already exists");
}

void CPersonsAndBuildings::FindBuildingPersons(std::shared_ptr<CBuilding> const& building,
	std::function<void(Persons::const_iterator)> cb) const
{
	for (auto it = m_persons.cbegin(); it != m_persons.cend(); ++it)
	{
		if ((*it)->GetBuilding().get() == building.get())
		{
			cb(it);
		}
	}
}

void CPersonsAndBuildings::FindBuildingPersons(std::shared_ptr<CBuilding> const& building,
	std::function<void(Persons::iterator)> cb)
{
	for (auto it = m_persons.begin(); it != m_persons.end(); ++it)
	{
		if ((*it)->GetBuilding().get() == building.get())
		{
			cb(it);
		}
	}
}

void CPersonsAndBuildings::PrintPersonList(CBuildingRelatedPerson::Type type) const
{
	size_t id = 0;

	for (auto person : m_persons)
	{
		if (person->GetType() == type)
		{
			cout << "ID = " << id << ", " << person->ToString() << endl;
			++id;
		}
	}
}

CPersonsAndBuildings::Persons::iterator
CPersonsAndBuildings::GetPersonByID(CBuildingRelatedPerson::Type type, size_t id)
{
	size_t curId = 0;

	for (auto person = m_persons.begin(); person != m_persons.end(); ++person)
	{
		if ((*person)->GetType() == type)
		{
			if (id == curId)
			{
				return person;
			}

			++curId;
		}
	}

	throw runtime_error("Index is out of bounds");
}
