#pragma once

#include "Person.h"
#include "Company.h"

class CWorker:
	public CPerson
{
public:
	CWorker(Gender gender, unsigned age, std::string const& name, unsigned height,
		unsigned weight, CCompany const* company, std::string const& specialty);

	CCompany const* GetCompany() const;
	std::string GetSpecialty() const;

	void SetCompany(CCompany const* newCompany);
	void SetSpecialty(std::string const& newSpecialty);

private:
	CCompany const* m_company;
	std::string m_specialty;
};
