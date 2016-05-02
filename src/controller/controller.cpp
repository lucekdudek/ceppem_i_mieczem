#include <iostream>
#include <iomanip>
#include "controller.h"
#include "fpshandler.h"

#include <stdlib.h>

bool Controller::running = true;
Window Controller::window;
Model Controller::model;
std::string Controller::current_view_name;
int strength=5;
View* Controller::current_view;

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
    if (current_view_name == "mainmenu")
    {
        mainMenuEvent(event_name);
    }
    else if (current_view_name == "new_game")
    {
        newGameEvent(event_name);
    }
    else if (current_view_name == "settings")
    {
        settingsEvent(event_name);
    }
    else
    {
        std::cout << "error, view \"" << current_view_name << "\" is invalid\n";
    }
}

void Controller::mainMenuEvent(std::string event_name)
{
    if (event_name == "NEW_GAME")
    {
        startNewGame();
        char buff[3];
        snprintf(buff, sizeof(buff), "%d", strength);
		current_view->setText("{strength_value}",buff);
    }
    else if (event_name == "SETTINGS")
    {
        changeView("settings");
    }
    else if (event_name == "EXIT_GAME")
    {
        setDone();
    }
    else
    {
        std::cout << "error, unexpected command:" << std::setw(10) << event_name << std::endl;
    }
}

void Controller::newGameEvent(std::string event_name)
{
	char buff[3];
	if (event_name == "NEW_GAME")
	{
		changeView("mainmenu");
	}
	else if (event_name == "DEC_STRENGTH")
	{
		strength--;
		if(strength<1) strength = 1;
		snprintf(buff, sizeof(buff), "%d", strength);
		current_view->setText("{strength_value}",buff);
	}
	else if (event_name == "INC_STRENGTH")
	{
		strength++;
		if(strength>9) strength = 10;
		snprintf(buff, sizeof(buff), "%d", strength);
		current_view->setText("{strength_value}",buff);
	}
	else
    {
        std::cout << "error, unexpected command:" << std::setw(10) << event_name << std::endl;
    }
}

void Controller::settingsEvent(std::string event_name)
{
    if (event_name == "BACK")
    {
        changeView("mainmenu");
    }
    else if (event_name.substr(0, 9) == "LANGUAGE_")
    {
        std::cout << "new language: " << event_name.substr(9) << std::endl;
        model.setLanguage(event_name.substr(9));
        changeView("settings");
    }
    else
    {
        std::cout << "cut: " << event_name.substr(0, 8) << std::endl;
        std::cout << "error, unexpected command:" << std::setw(10) << event_name << std::endl;
    }
}

void Controller::startNewGame()
{
    std::cout << "new game starting\n";
    changeView("new_game");
}

void Controller::changeView(std::string view)
{
    std::cout << "changed view to: " << std::setw(10) << view << std::endl;
    current_view_name = view;
    current_view = model.getXml("view_" + current_view_name);
    window.setView(current_view);
}

void Controller::setDone()
{
    running = false;
}
