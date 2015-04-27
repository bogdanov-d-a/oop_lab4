#include "stdafx.h"
#include "Worker.h"
#include "RawDataUtils.h"

using namespace std;

CWorker::CWorker(Gender gender, unsigned age, std::string const& name, unsigned height,
	unsigned weight, std::shared_ptr<CBuilding> const& building, std::string const& specialty)
	:CBuildingRelatedPerson(gender, age, name, height, weight, building)
	,m_specialty(specialty)
{}

CWorker::CWorker(std::istream &in, GetBuildingFunction getBuilding)
	:CBuildingRelatedPerson(in, getBuilding)
	,m_specialty(RawData::ReadString(in))
{}

void CWorker::WriteRawData(std::ostream &out) const
{
	CBuildingRelatedPerson::WriteRawData(out);
	RawData::WriteString(m_specialty, out);
}

string CWorker::GetSpecialty() const
{
	return m_specialty;
}

CWorker::Type CWorker::GetType() const
{
	return Type::WORKER;
}

void CWorker::SetSpecialty(string const& newSpecialty)
{
	m_specialty = newSpecialty;
}
