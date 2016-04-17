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
class Model
{
public:
    std::string language = "pl";

    Model();
    ~Model();
    void getXmlFile(rapidxml::xml_document<> &doc, std::string xmlName);
    std::vector < std::string > getLanguageFile(std::string filename);
    Element getMainMenu();
};

#endif //CEPPEM_I_MIECZEM_MODEL_H