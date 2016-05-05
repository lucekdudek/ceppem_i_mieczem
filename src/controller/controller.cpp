#include <iostream>
#include <iomanip>
#include "controller.h"
#include "fpshandler.h"
#include "../locations/l_small_farm.h"

#include <stdlib.h>


Controller::Controller()
{
    running = true;
    window = new Window();
    model = new Model;
	location = new L_Small_Farm();
}

Controller::~Controller()
{
    delete window;
    delete model;
    delete current_view;
	if (player != nullptr)
	{
		delete player;
		player=nullptr;
	}
}

void Controller::run()
{
    Controller &controller = getController();
    controller.setView("mainmenu");
    FpsHandler clock;
    while (controller.running)
    {
        clock.start();
        controller.window->eventLoop();
        controller.window->renderFrame();
        clock.delay();
    }
}

void Controller::event(std::string event_name)
{
    Controller &controller = getController();
    if (controller.current_view_name == "mainmenu")
    {
        controller.mainMenuEvent(event_name);
    }
    else if (controller.current_view_name == "new_game")
    {
        controller.newGameEvent(event_name);
    }
    else if (controller.current_view_name == "settings")
    {
        controller.settingsEvent(event_name);
    }
	else if(controller.current_view_name == "location")
	{
		controller.locationEvent(event_name);
	}
    else
    {
        std::cout << "error, view \"" << controller.current_view_name << "\" is invalid\n";
    }
}

void Controller::newGameEvent(std::string event_name)
{
	if (event_name == "BACK")
	{
        delete player;
		player = nullptr;
		setView("mainmenu");
	}
	else if (event_name == "START_GAME")
	{
		setView("location");
		addView("player_card", false);
	}
	else if(event_name.substr(0, 4) == "INC_" || event_name.substr(0, 4) == "DEC_")
	{
		lvl_up(event_name);
	}
	else
    {
        std::cout << "error, unexpected command:" << std::setw(10) << event_name << std::endl;
    }
}

void Controller::lvl_up(std::string event_name)
{
	if(event_name == "DEC_STRENGTH")
	{
		player->decStrength();
		current_view->setText("{points_value}", asText(player->getPoints()));
		current_view->setText("{strength_value}", asText(player->getStrength()));
	}
	else if(event_name == "INC_STRENGTH")
	{
		player->incStrength();
		current_view->setText("{points_value}", asText(player->getPoints()));
		current_view->setText("{strength_value}", asText(player->getStrength()));
	}
	else if(event_name == "DEC_DEXTERITY")
	{
		player->decDexterity();
		current_view->setText("{points_value}", asText(player->getPoints()));
		current_view->setText("{dexterity_value}", asText(player->getDexterity()));
	}
	else if(event_name == "INC_DEXTERITY")
	{
		player->incDexterity();
		current_view->setText("{points_value}", asText(player->getPoints()));
		current_view->setText("{dexterity_value}", asText(player->getDexterity()));
	}
	else if(event_name == "DEC_AGILITY")
	{
		player->decAgility();
		current_view->setText("{points_value}", asText(player->getPoints()));
		current_view->setText("{agility_value}", asText(player->getAgility()));
	}
	else if(event_name == "INC_AGILITY")
	{
		player->incAgility();
		current_view->setText("{points_value}", asText(player->getPoints()));
		current_view->setText("{agility_value}", asText(player->getAgility()));
	}
	else if(event_name == "DEC_WISDOM")
	{
		player->decWisdom();
		current_view->setText("{points_value}", asText(player->getPoints()));
		current_view->setText("{wisdom_value}", asText(player->getWisdom()));
	}
	else if(event_name == "INC_WISDOM")
	{
		player->incWisdom();
		current_view->setText("{points_value}", asText(player->getPoints()));
		current_view->setText("{wisdom_value}", asText(player->getWisdom()));
	}
	else if(event_name == "DEC_INTELIGENCE")
	{
		player->decInteligence();
		current_view->setText("{points_value}", asText(player->getPoints()));
		current_view->setText("{inteligence_value}", asText(player->getInteligence()));
	}
	else if(event_name == "INC_INTELIGENCE")
	{
		player->incInteligence();
		current_view->setText("{points_value}", asText(player->getPoints()));
		current_view->setText("{inteligence_value}", asText(player->getInteligence()));
	}
	else if(event_name == "DEC_CHARISMA")
	{
		player->decCharisma();
		current_view->setText("{points_value}", asText(player->getPoints()));
		current_view->setText("{charisma_value}", asText(player->getCharisma()));
	}
	else if(event_name == "INC_CHARISMA")
	{
		player->incCharisma();
		current_view->setText("{points_value}", asText(player->getPoints()));
		current_view->setText("{charisma_value}", asText(player->getCharisma()));
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
        setView("mainmenu");
    }
    else if (event_name.substr(0, 9) == "LANGUAGE_")
    {
        std::cout << "new language: " << event_name.substr(9) << std::endl;
        model->setLanguage(event_name.substr(9));
        setView("settings");
    }
    else
    {
        std::cout << "cut: " << event_name.substr(0, 8) << std::endl;
        std::cout << "error, unexpected command:" << std::setw(10) << event_name << std::endl;
    }
}

void Controller::playerPanelEvent(std::string event_name)
{
	if(event_name == "BACK")
	{
		delView();
	}
	else if(event_name.substr(0, 4) == "INC_" || event_name.substr(0, 4) == "DEC_")
	{
		lvl_up(event_name);
	}
	else
	{
		std::cout << "error, unexpected command in panel:" << std::setw(10) << event_name << std::endl;
	}
}

void Controller::playerCardEvent(std::string event_name)
{
	if(event_name == "EQUIPMENT")
	{
		;
	}
	else if(event_name == "PROFILE")
	{
		addView("player_panel");
		loadStats(player);
	}
	else if (event_name == "MAP")
	{
		;
	}
	else if (event_name == "MENU")
	{
		setView("mainmenu");
	}
	else
	{
		std::cout << "error, unexpected command in card:" << std::setw(10) << event_name << std::endl;
	}
}

void Controller::locationEvent(std::string event_name)
{
	if(event_name == "ACTIONA")
	{
		location->runActionA();
	}
	else if(event_name == "ACTIONB")
	{
		location->runActionB();
	}
	else if(event_name == "ACTIONC")
	{
		location->runActionC();
	}
	else if(event_name == "ACTIOND")
	{
		location->runActionD();
	}
	else if(event_name.substr(0, 6) == "PCARD_")
	{
		playerCardEvent(event_name.substr(6));
	}
	else if(event_name.substr(0, 6) == "PANEL_")
	{
		playerPanelEvent(event_name.substr(6));
	}
	else
	{
		std::cout << "error, unexpected command in card:" << std::setw(10) << event_name << std::endl;
	}
}

void Controller::startNewGame()
{
    std::cout << "new game starting\n";
    setView("new_game");
}

void Controller::mainMenuEvent(std::string event_name)
{
	if(event_name == "NEW_GAME")
	{
		startNewGame();
		player = new Character();
		loadStats(player);
	}
	else if(event_name == "SETTINGS")
	{
		setView("settings");
	}
	else if(event_name == "EXIT_GAME")
	{
		setDone();
	}
	else
	{
		std::cout << "error, unexpected command:" << std::setw(10) << event_name << std::endl;
	}
}

void Controller::setView(std::string view)
{
    std::cout << "changed view to: " << std::setw(10) << view << std::endl;
    current_view_name = view;
    current_view = model->getXml("view_" + view);
    window->setView(current_view);
}

void Controller::addView(std::string view, bool deactivation)
{
	View* v;
	if (deactivation)
	{
		v = model->getXml("view_blockade");
		current_view->extendView(v);
	}
	v = model->getXml("view_" + view);
	current_view->extendView(v);
	window->updateClickmap();
}

void Controller::delView()
{
	current_view->removeLastView();
	window->updateClickmap();
}

void Controller::setDone()
{
    getController().running = false;
}

Controller &Controller::getController()
{
    static Controller controller;
    return controller;
}

std::string Controller::asText(int number)
{
    char buff[3];
    snprintf(buff, sizeof(buff), "%d", number);
    return buff;
}

void Controller::loadStats(Character *character)
{
	current_view->setText("{points_value}", asText(character->getPoints()));
    current_view->setText("{strength_value}", asText(character->getStrength()));
    current_view->setText("{dexterity_value}", asText(character->getDexterity()));
    current_view->setText("{agility_value}", asText(character->getAgility()));
    current_view->setText("{wisdom_value}", asText(character->getWisdom()));
    current_view->setText("{inteligence_value}", asText(character->getInteligence()));
    current_view->setText("{charisma_value}", asText(character->getCharisma()));
}




