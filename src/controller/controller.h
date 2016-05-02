#ifndef CEPEM_I_MIECZEM_CONTROLLER_H
#define CEPEM_I_MIECZEM_CONTROLLER_H

#include <string>
#include "../view/window.h"
#include "../model/model.h"

class Controller
{
public:
    Controller();
    ~Controller();
    static void event(std::string event_name);
    static void run();
    inline static void setDone();
private:
    static bool running;
    static Window window;
    static Model model;
    static std::string current_view_name;                 //zawiera informację o aktualnie wyświetlanym widoku.
    static View* current_view;
    static void startNewGame();
    static void mainMenuEvent(std::string event_name);
    static void newGameEvent(std::string event_name);
    static void settingsEvent(std::string event_name);
    inline static void changeView(std::string view);

};

#endif //CEPEM_I_MIECZEM_CONTROLLER_H
