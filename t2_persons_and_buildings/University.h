#pragma once

class CUniversity
{
public:
	CUniversity(std::string const& name);
	virtual ~CUniversity();

	CUniversity(std::istream &in);
	virtual void WriteRawData(std::ostream &out) const;

	std::string GetName() const;
	virtual std::string ToString() const;

	void SetName(std::string const& newName);

private:
	std::string m_name;
};
