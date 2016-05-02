#ifndef CEPEM_I_MIECZEM_CONTROLLER_H
#define CEPEM_I_MIECZEM_CONTROLLER_H

#include <string>
#include "../view/window.h"
#include "../model/model.h"

class Controller
{
public:
    static void event(std::string event_name);
    static void run();
    static inline void setDone();
    static Controller & getController();
private:
    int strenght;
    Controller();
    ~Controller();
    bool running;
    std::string current_view_name;                 //zawiera informację o aktualnie wyświetlanym widoku.
    Window* window;
    Model* model;
    View* current_view;
    void startNewGame();
    void mainMenuEvent(std::string event_name);
    void newGameEvent(std::string event_name);
    void settingsEvent(std::string event_name);
    inline void changeView(std::string view);

};

#endif //CEPEM_I_MIECZEM_CONTROLLER_H
