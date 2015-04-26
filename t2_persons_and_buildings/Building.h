#pragma once

class CBuilding
{
public:
	CBuilding(std::string const& name);
	virtual ~CBuilding();

	CBuilding(std::istream &in);
	virtual void WriteRawData(std::ostream &out) const;

	std::string GetName() const;
	virtual std::string ToString() const;

	void SetName(std::string const& newName);

private:
	std::string m_name;
};
