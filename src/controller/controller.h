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
    static void setDone();
private:
    static bool running;
    static Window window;
    static Model model;
};

#endif //CEPEM_I_MIECZEM_CONTROLLER_H
