#include <iostream>
#include "controller.h"
#include "fpshandler.h"

bool Controller::running = true;
Window Controller::window;
Model Controller::model;

Controller::Controller()
{

}

Controller::~Controller()
{

}

void Controller::event(std::string event_name)
{

}

void Controller::run()
{
    FpsHandler clock;
    while (running)
    {
        clock.start();
        window.eventLoop();
        window.renderFrame();
        clock.delay();
    }
}

void Controller::setDone()
{
    running = false;
    std::cout << running;
}