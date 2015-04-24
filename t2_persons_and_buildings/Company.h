#pragma once

#include "University.h"

class CCompany:
	public CUniversity
{
public:
	CCompany(std::string const& name, std::string const& webSite);

	CCompany(std::istream &in);
	void WriteRawData(std::ostream &out) const;

	std::string GetWebSite() const;
	void SetWebSite(std::string const& newWebSite);

private:
	std::string m_webSite;
};
