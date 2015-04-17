#pragma once

#include "Body.h"

class CCompound:
	public CBody
{
public:
	void AddBody(std::shared_ptr<CBody> body);

	double GetVolume() const override;
	double GetMass() const override;
	double GetDensity() const override;
	std::string ToString() const override;

private:
	std::vector<std::shared_ptr<CBody>> m_bodies;

	bool HasBodyInside(const CBody *body) const;
	std::string GetName() const override;
};
