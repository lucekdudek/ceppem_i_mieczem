#pragma once
#include <string>
class Location
{
public:
	Location();
	~Location();
	std::string description;
	std::string actionAdescription;
	std::string actionBdescription;
	std::string actionCdescription;
	std::string actionDdescription;
	std::string getDescription() const{
		return description;
	}
	std::string getActionAdescription() const {
		return actionAdescription;
	}
	std::string getActionBdescription() const {
		return actionBdescription;
	}
	std::string getActionCdescription() const {
		return actionCdescription;
	}
	std::string getActionDdescription() const {
		return actionDdescription;
	}
	virtual void runActionA() = 0;
	virtual void runActionB() = 0;
	virtual void runActionC() = 0;
	virtual void runActionD() = 0;
};
