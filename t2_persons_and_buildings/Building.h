#pragma once

class CBuilding
{
public:
	enum class Type { UNIVERSITY, COMPANY };

	CBuilding(std::string const& name);
	virtual ~CBuilding();

	CBuilding(std::istream &in);
	virtual void WriteRawData(std::ostream &out) const;

	std::string GetName() const;
	virtual std::string ToString() const;
	virtual Type GetType() const = 0;

	void SetName(std::string const& newName);

private:
	std::string m_name;
};
