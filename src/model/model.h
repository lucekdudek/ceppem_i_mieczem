//
// Created by Jakub Gacek on 17.04.2016.
//

#ifndef MODEL_H_
#define MODEL_H_
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "../tinyxml/tinyxml.h"
#include "element.h"
#include <unordered_map>
#include <list>
#include "../view/view.h"
#include "../view/Window.h"

class Model
{
public:
    Model();
    ~Model();

    View *getXml(std::string file_name, std::string location_name="");
	View *getMap(std::string file_name, std::string location_name);
    std::unordered_map<std::string, std::string> getTextMap(std::string filename);

	const std::string& getLanguage() const {
		return language;
	}

	void setLanguage(const std::string& language = "pl") {
		this->language = language;
	}

private:
    std::string language = "pl";
};

#endif //CEPPEM_I_MIECZEM_MODEL_H
