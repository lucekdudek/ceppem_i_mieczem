#include "model.h"

Model::Model() {
    std::cout << "testing ctor" << std::endl;
}

Model::~Model() {

};

list<Element> Model::getXml() {
    std::list<Element> elements;
    rapidxml::xml_document<> doc;
    parseXml(doc, "view_mainmenu.xml");

   /* for (rapidxml::xml_node<> *child = doc.first_node("view")->first_node("element"); child; child = child->next_sibling())
    {
        elements.push_back(Element(atoi(child->first_node("x")->value()),
                                   atoi(child->first_node("y")->value()),
                                   atoi(child->first_node("width")->value()),
                                   atoi(child->first_node("height")->value())));
    }
*/


    return elements;
}

void Model::parseXml(rapidxml::xml_document<> &doc, std::string xmlName) {
    string input_xml;
    string line;

    ifstream in("../data/" + xmlName);
    if (!in.good()) {//is opened?
        cout << "ERROR xml read" << endl;
    }

    // read file into input_xml
    while (getline(in, line))
        input_xml += line;
    vector<char> xml_copy(input_xml.begin(), input_xml.end());
    xml_copy.push_back('\0');

    //parse XML
    doc.parse<rapidxml::parse_declaration_node | rapidxml::parse_no_data_nodes>(&xml_copy[0]);
}

std::unordered_map<std::string, std::string> Model::getTextMap(std::string filename) {
    std::string path = "../data/languages/" + language + "/" + filename;
    std::string id;
    std::string text;
    std::ifstream lang_file;
    std::unordered_map<std::string, std::string> textMap;

    lang_file.open(path.c_str());
    while (std::getline(lang_file, id) && std::getline(lang_file, text)) {
        //textMap={id, text};
        textMap.insert(std::make_pair(id, text));
    }
    lang_file.close();

    return textMap;
}