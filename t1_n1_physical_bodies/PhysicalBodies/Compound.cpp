#include "stdafx.h"
#include "Compound.h"

using namespace std;

void CCompound::AddBody(shared_ptr<CBody> body)
{
	if (this == body.get())
	{
		throw runtime_error("Can't add body to itself");
	}

	try
	{
		CCompound &bodyAsCompound = dynamic_cast<CCompound&>(*body);
		if (bodyAsCompound.HasBodyInside(this))
		{
			throw runtime_error("Circular link detected");
		}
	}
	catch (const bad_cast &e)
	{
		(void)e;
	}

	m_bodies.push_back(body);
}

double CCompound::GetVolume() const
{
	return accumulate(m_bodies.cbegin(), m_bodies.cend(), 0.0,
		[](double sum, shared_ptr<CBody> body){ return sum + body->GetVolume(); });
}

double CCompound::GetMass() const
{
	return accumulate(m_bodies.cbegin(), m_bodies.cend(), 0.0,
		[](double sum, shared_ptr<CBody> body){ return sum + body->GetMass(); });
}

double CCompound::GetDensity() const
{
	if (m_bodies.empty())
	{
		throw runtime_error("Empty compound body doesn't have density");
	}

	return (GetMass() / GetVolume());
}

bool CCompound::HasBodyInside(const CBody *body) const
{
	for (auto curBody : m_bodies)
	{
		if (body == curBody.get())
		{
			return true;
		}

		try
		{
			CCompound &curBodyAsCompound = dynamic_cast<CCompound&>(*curBody);
			if (curBodyAsCompound.HasBodyInside(body))
			{
				return true;
			}
		}
		catch (const bad_cast &e)
		{
			(void)e;
		}
	}

	return false;
}
