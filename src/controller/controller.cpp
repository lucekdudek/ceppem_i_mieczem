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
	if(player != nullptr)
	{
		delete player;
		player = nullptr;
	}
}

void Controller::run()
{
	Controller &controller = getController();
	controller.setView("mainmenu");
	FpsHandler clock;
	while(controller.running)
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
	for(std::list<std::string>::iterator it = controller.current_view_name.begin(); it != controller.current_view_name.end(); it++)
	{
		if(*it == "location")
		{
			if(controller.locationEvent(event_name))
				break;
		}
		
		else if(*it == "mainmenu")
		{
			if(controller.mainMenuEvent(event_name))
				break;
		}
		else if(*it == "new_game")
		{
			if(controller.newGameEvent(event_name))
				break;
		}
		else if(*it == "player_card")
		{
			if(controller.playerCardEvent(event_name))
				break;
		}
		else if(*it == "player_panel")
		{
			if(controller.playerPanelEvent(event_name))
				break;
		}
		else if(*it == "settings")
		{
			if(controller.settingsEvent(event_name))
				break;
		}
	}
}

bool Controller::containerEvent(std::string event_name)
{
	std::cout << "container:" << event_name << std::endl;
	if(event_name.substr(0, 5) == "OPEN_")
	{
		return containerOpenEvent(event_name.substr(5));
	}
	else
	{
		return false;
	}
	return true;
}

bool Controller::containerOpenEvent(std::string event_name)
{
	std::cout << event_name << " opened\n";
	return true;
}

bool Controller::locationEvent(std::string event_name)
{
	std::cout << "loc:" << event_name << std::endl;
	if(event_name.substr(0, 7) == "PERSON_")
	{
		return personEvent(event_name.substr(7));
	}
	else if(event_name.substr(0, 10) == "CONTAINER_")
	{
		return containerEvent(event_name.substr(10));
	}
	else
	{
		return false;
	}
	return true;
}

bool Controller::mainMenuEvent(std::string event_name)
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
		return false;
	}
	return true;
}

bool Controller::newGameEvent(std::string event_name)
{
	if(event_name == "BACK")
	{
		delete player;
		player = nullptr;
		setView("mainmenu");
	}
	else if(event_name == "START_GAME")
	{
		player->saveAttributes();
		setView("location");
		addView("player_card", false);
		std::string t = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Phasellus porta nisi id orci rutrum lobortis eget et diam. Curabitur lectus erat, sagittis a tellus sed, imperdiet consectetur metus. Nulla nibh nunc, sodales condimentum iaculis ut, faucibus ac ex. Nunc volutpat metus a dui eleifend consectetur. Fusce sed nunc fermentum, accumsan neque ac, interdum odio.";
		current_view->setText("{log_console}", t);
	}
	else if(event_name.substr(0, 4) == "INC_" || event_name.substr(0, 4) == "DEC_")
	{
		return lvl_up(event_name);
	}
	else
	{
		return false;
	}
	return true;
}

bool Controller::personEvent(std::string event_name)
{
	
	if(event_name.substr(0, 13) == "CONVERSATION_")
	{
		return personConversationEvent(event_name.substr(13));
	}
	else if(event_name.substr(0, 7) == "ATTACK_")
	{
		return personFightEvent(event_name.substr(7));
	}
	else
	{
		return false;
	}
	return true;
}

bool Controller::personConversationEvent(std::string event_name)
{
	std::cout << "conversation with " << event_name << std::endl;
	return true;
}

bool Controller::personFightEvent(std::string event_name)
{
	std::cout << "fighting with " << event_name << std::endl;
	return true;
}

bool Controller::playerCardEvent(std::string event_name)
{
	if(event_name == "EQUIPMENT")
	{
		;
	}
	else if(event_name == "MAP")
	{
		;
	}
	else if(event_name == "PROFILE")
	{
		addView("player_panel", true);
		loadStats(player);
	}
	else if(event_name == "MENU")
	{
		setView("mainmenu");
	}
	else
	{
		return false;
	}
	return true;
}

bool Controller::playerPanelEvent(std::string event_name)
{
	if(event_name == "BACK")
	{
		player->clearAttributes();
		delView();
	}
	else if(event_name == "SAVE")
	{
		player->saveAttributes();
		delView();
	}
	else if(event_name.substr(0, 4) == "INC_" || event_name.substr(0, 4) == "DEC_")
	{
		return lvl_up(event_name);
	}
	else
	{
		return false;
	}
	return true;
}

bool Controller::settingsEvent(std::string event_name)
{
	if(event_name == "BACK")
	{
		setView("mainmenu");
	}
	else if(event_name.substr(0, 9) == "LANGUAGE_")
	{
		std::cout << "new language: " << event_name.substr(9) << std::endl;
		model->setLanguage(event_name.substr(9));
		setView("settings");
	}
	else
	{
		return false;
	}
	return true;
}

bool Controller::lvl_up(std::string event_name)
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
		return false;
	}
	return true;
}

void Controller::startNewGame()
{
	std::cout << "new game starting\n";
	setView("new_game");
}

void Controller::setView(std::string view)
{
	std::cout << "changed view to: " << std::setw(10) << view << std::endl;
	current_view_name.clear();
	current_view_name.push_front(view);
	current_view = model->getXml("view_" + view);
	window->setView(current_view);
}

void Controller::addView(std::string view, bool deactivation)
{
	View* v = model->getXml("view_" + view);
	current_view_name.push_front(view);
	current_view->extendView(v, deactivation);
	window->updateClickmap();
}

void Controller::delView()
{
	current_view_name.pop_front();
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
