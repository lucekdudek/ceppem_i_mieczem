#ifndef CEPEM_I_MIECZEM_CONTROLLER_H
#define CEPEM_I_MIECZEM_CONTROLLER_H

#include <string>
#include <list>
#include "../view/window.h"
#include "../model/model.h"
#include "../model/character.h"
#include "../locations/location.h"

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
	Window* window;
	Model* model;
	View* current_view;
	Character* player;
	Location* location;
	Controller();
	~Controller();
	void startNewGame();
	bool containerEvent(std::string event_name);
	bool containerOpenEvent(std::string event_name);
	bool equipmentEvent(std::string event_name);
	bool exitEvent(std::string event_name);
	bool gameMenuEvent(std::string event_name);
	bool locationEvent(std::string event_name);
	bool mainMenuEvent(std::string event_name);
	bool newGameEvent(std::string event_name);
	bool personEvent(std::string event_name);
	bool personConversationEvent(std::string event_name);
	bool personFightEvent(std::string event_name);
	bool playerCardEvent(std::string event_name);
	bool playerPanelEvent(std::string event_name);
	bool settingsEvent(std::string event_name);
	bool mapEvent(std::string event_name);
	bool lvl_up(std::string event_name);
	void saveGame();
	void loadGame();
	inline void setView(std::string view);
	inline void setView(std::string view, std::string location);
	inline void addView(std::string view, bool deactivation = false);
	inline void addView(std::string view, std::string location, bool deactivation = false);
	inline void delView();
	static inline std::string asText(int number);
	void loadStats(Character *character);
};

#endif //CEPEM_I_MIECZEM_CONTROLLER_H
