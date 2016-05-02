//
// Created by Jakub Gacek on 17.04.2016.
//

#ifndef MODEL_H_
#define MODEL_H_
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "../rapidxml-1.13/rapidxml.hpp"
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

    View *getXml(std::string file_name);
    std::unordered_map<std::string, std::string> getTextMap(std::string filename);

	const std::string& getLanguage() const {
		return language;
	}

	void setLanguage(const std::string& language = "pl") {
		this->language = language;
	}

private:
    std::string language = "pl";
    void parseXml(rapidxml::xml_document<> &doc, std::string xmlName);

};

#endif //CEPPEM_I_MIECZEM_MODEL_H
