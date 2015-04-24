#include "stdafx.h"
#include "Student.h"
#include "Utils.h"
#include "RawDataUtils.h"

using namespace std;

CStudent::CStudent(Gender gender, unsigned age, string const& name, unsigned height,
	unsigned weight, unsigned grade, CUniversity const* university)
	:CPerson(gender, age, name, height, weight)
	,m_grade(grade)
	,m_university(university)
{
	ThrowIfGradeIsIncorrect(grade);
}

CStudent::CStudent(istream &in,
	function<CUniversity const*(string const& name)> getUniversityByName)
	:CPerson(in)
	,m_grade(RawData::ReadUnsigned(in))
	,m_university(getUniversityByName(RawData::ReadString(in)))
{}

void CStudent::WriteRawData(std::ostream &out) const
{
	CPerson::WriteRawData(out);
	RawData::WriteUnsigned(m_grade, out);
	RawData::WriteString(m_university->GetName(), out);
}

unsigned CStudent::GetGrade() const
{
	return m_grade;
}

CUniversity const* CStudent::GetUniversity() const
{
	return m_university;
}

bool CStudent::SetGrade(unsigned newGrade)
{
	ThrowIfGradeIsIncorrect(newGrade);
	return AssignIfGreater(m_grade, newGrade);
}

void CStudent::SetUniversity(CUniversity const* newUniversity)
{
	m_university = newUniversity;
}

void CStudent::ThrowIfGradeIsIncorrect(unsigned grade)
{
	if (grade < 1 || grade > 5)
	{
		throw runtime_error("Grade is out of range");
	}
}
