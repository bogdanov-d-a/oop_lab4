#pragma once

#include "Person.h"
#include "Building.h"

class CBuildingRelatedPerson:
	public CPerson
{
public:
	typedef std::function<std::shared_ptr<CBuilding>(std::string const& name, CBuilding::Type type)> GetBuildingFunction;
	enum class Type { STUDENT, WORKER };

	CBuildingRelatedPerson(Gender gender, unsigned age, std::string const& name,
		unsigned height, unsigned weight, std::shared_ptr<CBuilding> const& building);

	virtual ~CBuildingRelatedPerson();

	CBuildingRelatedPerson(std::istream &in, GetBuildingFunction getBuilding);
	static std::unique_ptr<CBuildingRelatedPerson> CreateFromRawData(std::istream &in, GetBuildingFunction getBuilding);
	virtual void WriteRawData(std::ostream &out) const override;

	std::shared_ptr<CBuilding> GetBuilding() const;
	virtual std::string ToString() const override;
	virtual Type GetType() const = 0;

	void SetBuilding(std::shared_ptr<CBuilding> const& newBuilding);

private:
	static const std::map<Type, char> TYPE_TO_CHAR;
	static const std::map<char, Type> CHAR_TO_TYPE;

	std::weak_ptr<CBuilding> m_building;
};
