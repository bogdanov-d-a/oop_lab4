#include "stdafx.h"
#include "Student.h"
#include "Utils.h"

using namespace std;

CStudent::CStudent(Gender gender, unsigned age, string const& name, unsigned height,
	unsigned weight, unsigned grade, CUniversity const* university)
	:CPerson(gender, age, name, height, weight)
	,m_grade(grade)
	,m_university(university)
{
	ThrowIfGradeIsIncorrect(grade);
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
