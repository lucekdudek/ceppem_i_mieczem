#ifndef CEPEM_I_MIECZEM_CONTROLLER_H
#define CEPEM_I_MIECZEM_CONTROLLER_H

#include <string>
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
	std::string current_view_name;                 //zawiera informację o aktualnie wyświetlanym widoku.
	Window* window;
	Model* model;
	View* current_view;
	Character* player;
	Location* location;
	Controller();
	~Controller();
	void startNewGame();
	void mainMenuEvent(std::string event_name);
	void newGameEvent(std::string event_name);
	void settingsEvent(std::string event_name);
	void playerPanelEvent(std::string event_name);
	void playerCardEvent(std::string event_name);
	void locationEvent(std::string event_name);
	void lvl_up(std::string event_name);
	inline void setView(std::string view);
	inline void addView(std::string view, bool deactivation = false);
	inline void delView();
	static inline std::string asText(int number);
	void loadStats(Character *character);
};

#endif //CEPEM_I_MIECZEM_CONTROLLER_H
