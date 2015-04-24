#include "stdafx.h"
#include "Worker.h"
#include "RawDataUtils.h"

using namespace std;

CWorker::CWorker(Gender gender, unsigned age, string const& name, unsigned height,
	unsigned weight, CCompany const* company, string const& specialty)
	:CPerson(gender, age, name, height, weight)
	,m_company(company)
	,m_specialty(specialty)
{}

CWorker::CWorker(istream &in,
	function<CCompany const*(string const& name)> getCompanyByName)
	:CPerson(in)
	,m_company(getCompanyByName(RawData::ReadString(in)))
	,m_specialty(RawData::ReadString(in))
{}

void CWorker::WriteRawData(std::ostream &out) const
{
	CPerson::WriteRawData(out);
	RawData::WriteString(m_company->GetName(), out);
	RawData::WriteString(m_specialty, out);
}

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
