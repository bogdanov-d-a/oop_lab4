#include "stdafx.h"
#include "Company.h"
#include "RawDataUtils.h"

using namespace std;

CCompany::CCompany(string const& name, string const& webSite)
	:CBuilding(name)
	,m_webSite(webSite)
{}

CCompany::CCompany(istream &in)
	:CBuilding(in)
	,m_webSite(RawData::ReadString(in))
{}

void CCompany::WriteRawData(ostream &out) const
{
	CBuilding::WriteRawData(out);
	RawData::WriteString(m_webSite, out);
}

string CCompany::GetWebSite() const
{
	return m_webSite;
}

string CCompany::ToString() const
{
	return (
		CBuilding::ToString() +
		", web site = " + m_webSite
	);
}

void CCompany::SetWebSite(string const& newWebSite)
{
	m_webSite = newWebSite;
}
