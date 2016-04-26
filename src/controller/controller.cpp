#include <iostream>
#include <iomanip>
#include "controller.h"
#include "fpshandler.h"

bool Controller::running = true;
Window Controller::window;
Model Controller::model;
std::string Controller::current_view;

Controller::Controller()
{

}

Controller::~Controller()
{

}

void Controller::run()
{
    changeView("mainmenu");
    FpsHandler clock;
    while (running)
    {
        clock.start();
        window.eventLoop();
        window.renderFrame();
        clock.delay();
    }
}

void Controller::event(std::string event_name)
{
    if(current_view == "mainmenu")
    {
        mainMenuEvent(event_name);
    }
    else if(current_view =="new_game")
    {
        newGameEvent(event_name);
    }
    else
    {
        std::cout<<"error, view \""<<current_view<<"\" is invalid\n";
    }
}

void Controller::mainMenuEvent(std::string event_name)
{
    if(event_name == "NEW_GAME")
    {
        startNewGame();
    }
    else if(event_name == "EXIT_GAME")
    {
        setDone();
    }
    else
    {
        std::cout<<"error, unexpected command:"<<std::setw(10)<<event_name<<std::endl;
    }
}

void Controller::newGameEvent(std::string event_name)
{
    if(event_name == "NEW_GAME")
    {
        changeView("mainmenu");
    }
    else
    {
        std::cout<<"error, unexpected command:"<<std::setw(10)<<event_name<<std::endl;
    }
}

void Controller::startNewGame()
{
    std::cout<<"new game starting\n";
    changeView("new_game");
}

void Controller::changeView(std::string view)
{
    std::cout<<"changed view to: "<<std::setw(10)<<view<<std::endl;
    current_view = view;
    window.setView(model.getXml("view_" + current_view));
}

inline void Controller::setDone()
{
    running = false;
}
