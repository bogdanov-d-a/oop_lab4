#pragma once

#include "BuildingRelatedPerson.h"

class CWorker:
	public CBuildingRelatedPerson
{
public:
	CWorker(Gender gender, unsigned age, std::string const& name, unsigned height,
		unsigned weight, std::shared_ptr<CBuilding> const& building, std::string const& specialty);

	CWorker(std::istream &in, GetBuildingFunction getBuilding);
	void WriteRawData(std::ostream &out) const override;

	std::string GetSpecialty() const;
	Type GetType() const override;

	void SetSpecialty(std::string const& newSpecialty);

private:
	std::string m_specialty;
};
