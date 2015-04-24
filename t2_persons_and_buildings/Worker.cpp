#include "stdafx.h"
#include "Worker.h"

using namespace std;

CWorker::CWorker(Gender gender, unsigned age, string const& name, unsigned height,
	unsigned weight, CCompany const* company, string const& specialty)
	:CPerson(gender, age, name, height, weight)
	,m_company(company)
	,m_specialty(specialty)
{}

CCompany const* CWorker::GetCompany() const
{
	return m_company;
}

string CWorker::GetSpecialty() const
{
	return m_specialty;
}

void CWorker::SetCompany(CCompany const* newCompany)
{
	m_company = newCompany;
}

void CWorker::SetSpecialty(string const& newSpecialty)
{
	m_specialty = newSpecialty;
}
