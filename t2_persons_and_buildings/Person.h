#pragma once

class CPerson
{
public:
	enum class Gender { MALE, FEMALE };

	CPerson(Gender gender, unsigned age, std::string name, unsigned height, unsigned weight);
	virtual ~CPerson();

	Gender GetGender() const;
	unsigned GetAge() const;
	std::string GetName() const;
	unsigned GetHeight() const;
	unsigned GetWeight() const;

	bool SetAge(unsigned newAge);
	void SetName(std::string const& newName);
	bool SetHeight(unsigned newHeight);
	void SetWeight(unsigned newWeight);

private:
	Gender m_gender;
	unsigned m_age;
	std::string m_name;
	unsigned m_height;
	unsigned m_weight;
};
