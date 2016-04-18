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
    std::string language = "pl";

    Model();
    ~Model();

    View *getXml();
    std::unordered_map<std::string, std::string> getTextMap(std::string filename);
    int loadGLTexture(string fileName);

private:
    void parseXml(rapidxml::xml_document<> &doc, std::string xmlName);

};

#endif //CEPPEM_I_MIECZEM_MODEL_H
