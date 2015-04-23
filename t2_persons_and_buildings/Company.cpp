#include "stdafx.h"
#include "Company.h"

using namespace std;

CCompany::CCompany(string const& name, string const& webSite)
	:CUniversity(name)
	,m_webSite(webSite)
{}

string CCompany::GetWebSite() const
{
	return m_webSite;
}

void CCompany::SetWebSite(string const& newWebSite)
{
	m_webSite = newWebSite;
}
