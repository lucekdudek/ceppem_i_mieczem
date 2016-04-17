#include "model.h"
Model::Model()
{
    std::cout << "testing ctor" << std::endl;
}

Model::~Model()
{

};

Element Model::getMainMenu()
{
    Element e(10,10,20,20);
    rapidxml::xml_document<> doc;
    getXmlFile(doc, "view_mainmenu.xml");
    std::vector < std::string > language_vector = Model::getLanguageFile("main_menu.txt");
    language_vector[0];

    return e;
}

void Model::getXmlFile(rapidxml::xml_document<> &doc ,std::string xmlName)
{
    string input_xml;
    string line;

    ifstream in("../data/"+xmlName);
    if (!in.good()){//is opened?
        cout<<"ERROR xml read"<<endl;
    }

    // read file into input_xml
    while(getline(in,line))
        input_xml += line;
    vector<char> xml_copy(input_xml.begin(), input_xml.end());
    xml_copy.push_back('\0');

    //parse XML
    doc.parse<rapidxml::parse_declaration_node | rapidxml::parse_no_data_nodes>(&xml_copy[0]);
}

std::vector < std::string > Model::getLanguageFile(std::string filename)
{
    std::string path="../data/languages/"+language+"/"+filename;
    std::string line;
    std::vector < std::string > language_strings;
    std::ifstream lang_file;

    int i = 0;

    lang_file.open(path.c_str());
    while (std::getline(lang_file, line))
    {
        language_strings.push_back(line);
        cout<<language_strings[i];
        i++;
    }
    lang_file.close();

    return language_strings;
}