#pragma once

class CPerson
{
public:
	enum class Gender { MALE, FEMALE };

	static const std::map<std::string, Gender> NAME_TO_GENDER;

	CPerson(Gender gender, unsigned age, std::string const& name, unsigned height, unsigned weight);
	virtual ~CPerson();

	CPerson(std::istream &in);
	virtual void WriteRawData(std::ostream &out) const;

	Gender GetGender() const;
	unsigned GetAge() const;
	std::string GetName() const;
	unsigned GetHeight() const;
	unsigned GetWeight() const;
	virtual std::string ToString() const;

	bool SetAge(unsigned newAge);
	void SetName(std::string const& newName);
	bool SetHeight(unsigned newHeight);
	void SetWeight(unsigned newWeight);

private:
	static const std::map<Gender, char> GENDER_TO_CHAR;
	static const std::map<char, Gender> CHAR_TO_GENDER;
	static const std::map<Gender, std::string> GENDER_TO_NAME;

	Gender m_gender;
	unsigned m_age;
	std::string m_name;
	unsigned m_height;
	unsigned m_weight;
};
