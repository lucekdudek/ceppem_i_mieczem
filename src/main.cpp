#include <iostream>
#include <stdlib.h>

#include "view/window.h"

#include <fstream>
#include <vector>
#include "rapidxml-1.13/rapidxml.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    Window w;
    //system("pause");


    string input_xml;
    string line;
    ifstream in("../data/view_mainmenu.xml");
    if (!in.good()){//is opened?
    	cout<<"ERROR"<<endl;
    }

    // read file into input_xml
    while(getline(in,line))
        input_xml += line;
    vector<char> xml_copy(input_xml.begin(), input_xml.end());
    xml_copy.push_back('\0');

    //parse XML
    rapidxml::xml_document<> doc;
    doc.parse<rapidxml::parse_declaration_node | rapidxml::parse_no_data_nodes>(&xml_copy[0]);

    //get width
	cout << "Width: " <<doc.first_node("view")->first_node("element")->first_node("width")->value();

    return 0;
}
