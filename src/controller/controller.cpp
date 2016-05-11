#include <iostream>
#include <iomanip>
#include <algorithm>
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
	std::cout << "event occured: " << event_name << std::endl;
	Controller &controller = getController();
	for(std::list<std::string>::iterator it = controller.current_view_name.begin(); it != controller.current_view_name.end(); it++)
	{
		if(*it == "equipment")
		{
			controller.current_view->setFill("player", controller.player->getHealth());
			if(controller.equipmentEvent(event_name))
				break;
		}
		else if(*it == "location")
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
		else if(*it == "map")
		{
			if(controller.mapEvent(event_name))
				break;
		}
		else if(*it == "game_menu")
		{
			if(controller.gameMenuEvent(event_name))
				break;
		}
		else if(*it == "fight_card")
		{
			if(controller.playerCardEvent(event_name))
				break;
		}
		else if(*it == "fight")
		{
			if (controller.playerFightEvent(event_name))
				break;
		}
	}
}

bool Controller::playerFightEvent(std::string event_name)
{
	if (event_name == "WEAPONA")
	{
		std::cout << "use weapon A" << std::endl;
		enemy->decHealth(player->getStrength() * 2);
	}
	else if (event_name == "WEAPONB")
	{
		std::cout << "use weapon B" << std::endl;
		enemy->decHealth(player->getStrength());
	}

	player->decHealth(enemy->getStrength() * (rand() % 2 + 1));

	current_view->setFill("player", player->getHealth());
	current_view->setFill("oponent", enemy->getHealth());
	if (player->getHealth() == 0)
	{
		std::cout << "game over" << std::endl;
		player->incHealth(10);
		travel(next_view_name);
		delete enemy;
		enemy = nullptr;
	}
	else if (enemy->getHealth() == 0)
	{
		std::cout << "you won -> open container" << std::endl;
		travel(next_view_name);
		delete enemy;
		enemy = nullptr;
	}
	return true;
}

bool Controller::containerEvent(std::string event_name)
{
	if(event_name.substr(0, 5) == "OPEN_")
	{
		return containerOpenEvent(event_name.substr(5));
	}
	else if(event_name.substr(0, 12) == "INVESTIGATE_")
	{
		return conversationEvent(event_name.substr(12) + "_DESCRIPTION");
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

bool Controller::conversationEvent(std::string event_name)
{
	int i;
	for(i = 0; i < event_name.length(); i++)
	{
		if(event_name[i] == '_')
			break;
	}
	std::string person = event_name.substr(0, i);
	std::string topic = event_name.substr(i + 1);
	std::transform(person.begin(), person.end(), person.begin(), ::tolower);
	std::transform(topic.begin(), topic.end(), topic.begin(), ::tolower);
	std::string text=model->getTextMap("conversations/" + person)["{" + topic + "}"];
	if (text == "")
	{
		text = "-";
	}
	std::cout << person << ": " << topic << std::endl;
	current_view->setText("{console}", text);
	return true;
}

bool Controller::equipmentEvent(std::string event_name)
{
	static int current_element = 0;
	static int active_slot = 0;
	if(event_name == "LOAD_DATA")
	{
		equipmentLoadData(current_element, active_slot);
	}
	else if(event_name == "BACK")
	{
		player->clearAttributes();
		delView();
	}
	else if(event_name == "PREVIOUS")
	{
		if(current_element > 0)
			current_element--;
		equipmentLoadData(current_element, active_slot);
	}
	else if(event_name == "NEXT")
	{
		if(current_element < player->getInventorySize()-6)
			current_element++;
		equipmentLoadData(current_element, active_slot);
	}
	else if(event_name.substr(0, 4) == "ITEM")
	{
		active_slot = current_element + int(event_name[4]) - int('0');
		equipmentLoadData(current_element, active_slot);
	}
	else if(event_name == "USE")
	{
		Itemz* item = player->getInventoryItem(active_slot);
		useItem(item);
		equipmentLoadData(current_element, active_slot);
	}
	else if(event_name == "THROW")
	{
		equipmentLoadData(current_element, active_slot);
	}
	else
	{
		return false;
	}
	return true;
}

void Controller::equipmentLoadData(int current_element, int active_slot)
{
	std::cout << player->getInventoryItemName(current_element) << std::endl;
	current_view->setText("{item0}", player->getInventoryItemName(current_element));
	current_view->setText("{item1}", player->getInventoryItemName(current_element + 1));
	current_view->setText("{item2}", player->getInventoryItemName(current_element + 2));
	current_view->setText("{item3}", player->getInventoryItemName(current_element + 3));
	current_view->setText("{item4}", player->getInventoryItemName(current_element + 4));
	current_view->setText("{item5}", player->getInventoryItemName(current_element + 5));
	Itemz* item = player->getInventoryItem(active_slot);
	current_view->setText("{item_description}", item->getName() + " \n \n " + item->getDescription());
	current_view->setText("{equipment}", model->translateText(player->eqToString(), "text_equipment"));
	current_view->setText("{gold_value}", asText(player->getGold()));
}

bool Controller::exitEvent(std::string event_name)
{
	if(event_name == "MENU")
	{
		setView("mainmenu");
	}
	else if(event_name == "DESKTOP")
	{
		setDone();
	}
	else
	{
		return false;
	}
	return true;
}

bool Controller::gameMenuEvent(std::string event_name)
{
	if(event_name == "BACK")
	{
		delView();
	}
	else if(event_name == "SAVE")
	{
		saveGame();
	}
	else if(event_name == "LOAD")
	{
		loadGame();
	}
	else if(event_name.substr(0, 5) == "EXIT_")
	{
		return exitEvent(event_name.substr(5));
	}
	else
	{
		return false;
	}
	return true;
}

bool Controller::mapEvent(std::string event_name)
{
	if(event_name == "BACK")
	{
		delView();
	}
	else if(event_name.substr(0, 5) == "GOTO_")
	{
		srand(time(NULL));
		if(rand() % 2)
		{
			fight(event_name.substr(5), "Pikachu");
		}
		else
		{
			travel(event_name.substr(5));
		}
	}
	else
	{
		return false;
	}
	return true;
}

void Controller::fight(std::string next_view, std::string oponent)
{
	enemy = new Enemy(oponent);
	next_view_name = next_view;
	std::transform(oponent.begin(), oponent.end(), oponent.begin(), ::tolower);
	char* oponent_name = _strdup(oponent.c_str());
	char* oponent_file_name = _strdup((oponent + ".png").c_str());
	//open fight view
	setView("fight", oponent_name, oponent_file_name);
	addView("fight_card", false);
	current_view->setFill("player", player->getHealth());
	current_view->setFill("oponent", enemy->getHealth());
	std::string weapon_name = player->getWeaponName();
	std::unordered_map<std::string, std::string> map = model->getTextMap("fists");
	if (map["{fists}"] != "" && weapon_name=="{fists}")
	{
		weapon_name = map["{fists}"];
	}
	current_view->setText("{weapon_name}", weapon_name);
}

bool Controller::locationEvent(std::string event_name)
{
	if(event_name.substr(0, 7) == "PERSON_")
	{
		return personEvent(event_name.substr(7));
	}
	else if(event_name.substr(0, 10) == "CONTAINER_")
	{
		return containerEvent(event_name.substr(10));
	}
	else if(event_name.substr(0, 5) == "GOTO_")
	{
		travel(event_name.substr(5));
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
	else if(event_name == "LOAD_GAME")
	{
		loadGame();
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
		player->addItem(model->loadItem("armor"));
		player->addItem(model->loadItem("boots"));
		player->addItem(model->loadItem("cepp"));
		player->addItem(model->loadItem("hands"));
		player->addItem(model->loadItem("helm"));
		player->addItem(model->loadItem("legs"));
		player->addItem(model->loadItem("potion_hp"));
		setLocation("smallfarm");
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
		return conversationEvent(event_name.substr(13));
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

bool Controller::personFightEvent(std::string event_name)
{
	std::cout << "fighting with " << event_name << std::endl;
	fight(current_location, event_name);
	return true;
}

bool Controller::playerCardEvent(std::string event_name)
{
	if(event_name == "EQUIPMENT")
	{
		addView("equipment", true);
		equipmentEvent("LOAD_DATA");
	}
	else if(event_name == "MAP")
	{
		addView("map", current_location, true);
	}
	else if(event_name == "PROFILE")
	{
		addView("player_panel", true);
		loadStats(player);
	}
	else if(event_name == "MENU")
	{
		addView("game_menu", true);
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

void Controller::saveGame()
{
	std::cout << "game saved\n";
}

void Controller::loadGame()
{
	std::cout << "game loaded\n";
}

void Controller::travel(std::string destination)
{
	std::transform(destination.begin(), destination.end(), destination.begin(), ::tolower);
	setLocation(destination);

}

void Controller::startNewGame()
{
	setView("new_game");
}

void Controller::setLocation(std::string location)
{
	current_location = location;
	setView("location", location);
	addView("player_card", false);
}

void Controller::useItem(Itemz * item)
{
	std::string type = item->getType();
	if(type == "wearable")
	{
		wear((Wearable*)item);
	}
	if(type == "weapon")
	{
		wear((Weapon*)item);
	}
	else if(type == "potion")
	{
		player->incHealth(((Potion*)item)->use());
	}
}

void Controller::wear(Wearable *item)
{
	//1 helm
	//2 armor
	//3 legs
	//4 boots
	//5 hands
	int slot = item->getSlot();
	if(slot == 1)
	{
		player->wearHead(item);
	}
	else if(slot == 2)
	{
		player->wearChest(item);
	}
	else if(slot == 3)
	{
		player->wearLegs(item);
	}
	else if(slot == 4)
	{
		player->wearFeet(item);
	}
	else if(slot == 5)
	{
		player->wearHands(item);
	}
}

void Controller::wear(Weapon *item)
{
	player->wearWeapon(item);
}

void Controller::setView(std::string view)
{
	current_view_name.clear();
	current_view_name.push_front(view);
	current_view = model->getXml("view_" + view);
	window->setView(current_view);
}

void Controller::setView(std::string view, std::string location)
{
	current_view_name.clear();
	current_view_name.push_front(view);
	current_view = model->getXml("view_" + view, "location_" + location);
	window->setView(current_view);
}

void Controller::setView(std::string view, std::string name, std::string image_file)
{
	current_view_name.clear();
	current_view_name.push_front(view);
	current_view = model->getFightView("view_" + view, name, image_file);
	window->setView(current_view);
}

void Controller::addView(std::string view, bool deactivation)
{
	View* v = model->getXml("view_" + view);
	current_view_name.push_front(view);
	current_view->extendView(v, deactivation);
	window->updateClickmap();
}

void Controller::addView(std::string view, std::string location, bool deactivation)
{
	View* v;
	if(view == "map")
	{
		v = model->getMap("view_" + view, "location_" + location);
	}
	else
	{
		v = model->getXml("view_" + view, "location_" + location);
	}
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
	char buff[15];
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
