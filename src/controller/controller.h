#ifndef CEPEM_I_MIECZEM_CONTROLLER_H
#define CEPEM_I_MIECZEM_CONTROLLER_H

#include <string>
#include "../view/window.h"
#include "../model/model.h"
#include "../model/char.h"

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
    Char* player;
    Controller();
    ~Controller();
    void startNewGame();
    void mainMenuEvent(std::string event_name);
    void newGameEvent(std::string event_name);
    void settingsEvent(std::string event_name);
    inline void changeView(std::string view);
    static inline std::string asText(int number);
    void loadStats(Char *character);

};

#endif //CEPEM_I_MIECZEM_CONTROLLER_H
