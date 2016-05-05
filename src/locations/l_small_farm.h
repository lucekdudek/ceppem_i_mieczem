#include "location.h"

class L_Small_Farm :
	public Location
{
public:
	L_Small_Farm();
	~L_Small_Farm();
	std::string description = "{small_farm_des}";
	std::string actionAdescription = "{small_farm_act_a}";;
	std::string actionBdescription = "{small_farm_act_b}";;
	std::string actionCdescription = "{small_farm_act_c}";;
	std::string actionDdescription = "{small_farm_act_d}";;
	virtual void runActionA();
	virtual void runActionB();
	virtual void runActionC();
	virtual void runActionD();
};

