#pragma once

#include "Building.h"

class CUniversity:
	public CBuilding
{
public:
	CUniversity(std::string const& name);
	Type GetType() const override;
};
