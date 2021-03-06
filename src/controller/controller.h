#ifndef CEPEM_I_MIECZEM_CONTROLLER_H
#define CEPEM_I_MIECZEM_CONTROLLER_H

#include <string>
#include <list>
#include "../view/window.h"
#include "../model/model.h"
#include "../model/character.h"
#include "../model/enemy.h"
#include "../locations/location.h"
#include "../model/items/wearable.h"
#include "../model/items/weapon.h"
#include "../model/items/potion.h"
#include "fpshandler.h"

class Controller
{
public:
	static void event(std::string event_name);
	static void run();
	static inline void setDone();
	static Controller & getController();
private:
	bool running;
	std::list <std::string> current_view_name;                 //zawiera informację o aktualnie wyświetlanych widokach.
	std::string current_location;
	Window* window;
	Model* model;
	View* current_view;
	Character* player;
	Enemy* enemy;
	Location* location;
	FpsHandler clock;
	std::string next_view_name="";
	Controller();
	~Controller();
	void startNewGame();
	bool containerEvent(std::string event_name);
	bool containerOpenEvent(std::string event_name);
	bool conversationEvent(std::string event_name);
	bool equipmentEvent(std::string event_name);
	void equipmentLoadData(int current_element, int active_slot);
	bool exitEvent(std::string event_name);
	bool gameMenuEvent(std::string event_name);
	bool locationEvent(std::string event_name);
	bool mainMenuEvent(std::string event_name);
	bool messageEvent(std::string event_name);
	bool newGameEvent(std::string event_name);
	bool personEvent(std::string event_name);
	bool personFightEvent(std::string event_name);
	bool playerCardEvent(std::string event_name);
	bool playerPanelEvent(std::string event_name);
	bool settingsEvent(std::string event_name);
	bool mapEvent(std::string event_name);
	bool lvl_up(std::string event_name);
	void saveGame();
	void loadGame();
	void travel(std::string destination);
	void fight(std::string next_view, std::string oponent);
	bool playerFightEvent(std::string event_name);
	void setLocation(std::string view);
	void useItem(Itemz *item);
	void throwItem(Itemz *item);
	void wear(Wearable *item);
	void wear(Weapon *item);
	inline void setView(std::string view);
	inline void setView(std::string view, std::string location);
	inline void setView(std::string view, std::string name, std::string image_file);
	inline void addView(std::string view, bool deactivation = false);
	inline void addView(std::string view, std::string location, bool deactivation = false);
	inline void delView();
	void showMessage(std::string message_tag);
	static inline std::string asText(int number);
	void loadStats(Character *character);
	
};

#endif //CEPEM_I_MIECZEM_CONTROLLER_H
