#pragma once

#include "BuildingRelatedPerson.h"

class CStudent:
	public CBuildingRelatedPerson
{
public:
	CStudent(Gender gender, unsigned age, std::string const& name, unsigned height,
		unsigned weight, std::shared_ptr<CBuilding> const& building, unsigned grade);

	CStudent(std::istream &in, GetBuildingFunction getBuilding);
	void WriteRawData(std::ostream &out) const override;

	unsigned GetGrade() const;
	Type GetType() const override;

	bool SetGrade(unsigned newGrade);

private:
	unsigned m_grade;
	static void ThrowIfGradeIsIncorrect(unsigned grade);
};
