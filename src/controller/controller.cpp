#include <iostream>
#include "controller.h"
#include "fpshandler.h"
//#include "../view/window.h"

bool Controller::running=true;
Window Controller::window;

Controller :: Controller()
{
}

Controller :: ~Controller()
{
}

void Controller :: run()
{
    FpsHandler clock;
    while(running)
    {
        clock.start();
        window.eventLoop();
        window.renderFrame();
        clock.delay();
    }
}

void Controller :: setDone()
{
    running = false;
    std::cout<<running;
}