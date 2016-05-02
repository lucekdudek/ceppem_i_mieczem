#include "model.h"

Model::Model() {
}

Model::~Model() {

}

View *Model::getXml(std::string file_name) {
	std::list<Element> elements;
	rapidxml::xml_document<> doc;
	parseXml(doc, file_name + ".xml");

	std::string str = "../data/";
	std::string temp;
	char buffer[256];

	for (rapidxml::xml_node<> *child = doc.first_node("view")->first_node(
			"element"); child; child = child->next_sibling()) {

		//Create Element object
		Element el(atoi(child->first_node("x")->value()),
				atoi(child->first_node("y")->value()),
				atoi(child->first_node("width")->value()),
				atoi(child->first_node("height")->value()));
		if (child->first_node("onclick") != NULL) {
			el.setOnClick(child->first_node("onclick")->value());
		}
		if (child->first_node("onhover") != NULL) {
			rapidxml::xml_node<> *onhover=child->first_node("onhover");
			int x = atoi(onhover->first_attribute("x")->value());
			int y = atoi(onhover->first_attribute("y")->value());
			int width = atoi(onhover->first_attribute("width")->value());
			int height = atoi(onhover->first_attribute("height")->value());
			temp = str + std::string(onhover->value());
			temp.copy(buffer, temp.length(), 0);
			buffer[temp.length()] = '\0';
			el.setOnHover(new Texture(x, y, width, height, buffer));
		}

		//load textures into list
		std::list<Texture> tex = el.getTextures();
		for (rapidxml::xml_node<> *textures =
				child->first_node("textures")->first_node(); textures;
				textures = textures->next_sibling()) {
			if (strcmp(textures->name(), "texture") == 0) {
				temp = str + std::string(textures->value());
				temp.copy(buffer, temp.length(), 0);
				buffer[temp.length()] = '\0';

				int x = atoi(textures->first_attribute("x")->value());
				int y = atoi(textures->first_attribute("y")->value());
				int width = atoi(textures->first_attribute("width")->value());
				int height = atoi(textures->first_attribute("height")->value());
				//load textures into opengl and add it to Element
				el.addTexture(Texture(x, y, width, height, buffer));
			} else if (strcmp(textures->name(), "text") == 0) {
				temp = std::string(textures->value());
				temp.copy(buffer, temp.length(), 0);
				buffer[temp.length()] = '\0';

				int x = atoi(textures->first_attribute("x")->value());
				int y = atoi(textures->first_attribute("y")->value());
				int width = atoi(textures->first_attribute("width")->value());
				int height = atoi(textures->first_attribute("height")->value());
				//load textures into opengl and add it to Element
				el.addTexture(Texture(x, y, width, height, buffer, NULL));
			}
		}

		elements.push_back(el); //add Element to list

	}

	View *view = new View(elements);
	file_name.replace(0,4,"text");

	std::unordered_map<std::string, std::string> map = getTextMap(file_name);
	for (auto& x: map){
		char first[256];
		char second[256];
		strcpy(first,x.first.c_str());
		strcpy(second,x.second.c_str());
		view->setText(first,second);
	}

	return view;
}

void Model::parseXml(rapidxml::xml_document<> &doc, std::string xmlName) {
	std::string input_xml;
	std::string line;

	std::ifstream in("../data/" + xmlName);
	if (!in.good()) { //is opened?
		std::cout << "ERROR xml read" << std::endl;
	}

	// read file into input_xml
	while (getline(in, line))
		input_xml += line;
	std::vector<char> xml_copy(input_xml.begin(), input_xml.end());
	xml_copy.push_back('\0');

	//parse XML
	doc.parse<rapidxml::parse_declaration_node | rapidxml::parse_no_data_nodes>(
			&xml_copy[0]);
}

std::unordered_map<std::string, std::string> Model::getTextMap(
		std::string filename) {
	std::string path = "../data/languages/" + language + "/" + filename + ".txt";
	std::string id;
	std::string text;

	std::ifstream lang_file;
	std::unordered_map<std::string, std::string> textMap;

	lang_file.open(path.c_str());
	lang_file.seekg( 3, std::ios::beg );
	while (std::getline(lang_file, id) && std::getline(lang_file, text)) {
		//textMap={id, text};
		textMap.insert(std::make_pair(id, text));
	}
	lang_file.close();

	return textMap;
}
