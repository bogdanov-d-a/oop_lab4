#include "stdafx.h"
#include "Student.h"
#include "Utils.h"
#include "RawDataUtils.h"

using namespace std;

CStudent::CStudent(Gender gender, unsigned age, std::string const& name, unsigned height,
	unsigned weight, std::shared_ptr<CBuilding> const& building, unsigned grade)
	:CBuildingRelatedPerson(gender, age, name, height, weight, building)
	,m_grade(grade)
{
	ThrowIfGradeIsIncorrect(grade);
}

CStudent::CStudent(std::istream &in, GetBuildingFunction getBuilding)
	:CBuildingRelatedPerson(in, getBuilding)
	,m_grade(RawData::ReadUnsigned(in))
{}

void CStudent::WriteRawData(std::ostream &out) const
{
	CBuildingRelatedPerson::WriteRawData(out);
	RawData::WriteUnsigned(m_grade, out);
}

unsigned CStudent::GetGrade() const
{
	return m_grade;
}

string CStudent::ToString() const
{
	return (
		CBuildingRelatedPerson::ToString() +
		", grade = " + to_string(m_grade)
	);
}

CStudent::Type CStudent::GetType() const
{
	return Type::STUDENT;
}

bool CStudent::SetGrade(unsigned newGrade)
{
	ThrowIfGradeIsIncorrect(newGrade);
	return AssignIfGreater(m_grade, newGrade);
}

void CStudent::ThrowIfGradeIsIncorrect(unsigned grade)
{
	if (grade < 1 || grade > 5)
	{
		throw runtime_error("Grade is out of range");
	}
}
