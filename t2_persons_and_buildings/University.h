#pragma once

#include "Building.h"

class CUniversity:
	public CBuilding
{
public:
	CUniversity(std::string const& name);
	CUniversity(std::istream &in);

	Type GetType() const override;
};
