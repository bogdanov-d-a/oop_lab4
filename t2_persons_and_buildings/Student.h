#pragma once

#include "Person.h"
#include "University.h"

class CStudent:
	public CPerson
{
public:
	CStudent(Gender gender, unsigned age, std::string const& name, unsigned height,
		unsigned weight, unsigned grade, CUniversity const* university);

	CStudent(std::istream &in,
		std::function<CUniversity const*(std::string const& name)> getUniversityByName);

	void WriteRawData(std::ostream &out) const override;

	unsigned GetGrade() const;
	CUniversity const* GetUniversity() const;

	bool SetGrade(unsigned newGrade);
	void SetUniversity(CUniversity const* newUniversity);

private:
	unsigned m_grade;
	CUniversity const* m_university;

	static void ThrowIfGradeIsIncorrect(unsigned grade);
};
