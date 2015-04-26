#pragma once

#include "Building.h"

class CCompany:
	public CBuilding
{
public:
	CCompany(std::string const& name, std::string const& webSite);

	CCompany(std::istream &in);
	void WriteRawData(std::ostream &out) const override;

	std::string GetWebSite() const;
	std::string ToString() const override;
	Type GetType() const override;

	void SetWebSite(std::string const& newWebSite);

private:
	std::string m_webSite;
};
