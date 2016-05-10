#include "model.h"

Model::Model()
{
}

Model::~Model()
{

}

View *Model::getXml(std::string file_name, std::string location_name)
{
	std::list<Element*> elements;

	TiXmlDocument doc(("../data/views/" + file_name + ".xml").c_str());
	doc.LoadFile();

	TiXmlDocument doc2(("../data/locations/" + location_name + ".xml").c_str());
	TiXmlElement *pRoot2, *pEvent;
	pRoot2 = NULL;
	if (location_name.length() > 0)
	{
		doc2.LoadFile();
		pRoot2 = doc2.FirstChildElement("location");


		Element* bgElement = new Element(0, 0, 1280, 720);
		std::string tmp = "../data/images/" + std::string(pRoot2->FirstChildElement("background")->FirstChild()->ToText()->Value());
		char* background = _strdup(tmp.c_str());
		bgElement->addTexture(new Texture(0, 0, 1280, 720, background));
		elements.push_back(bgElement);
	}

	TiXmlElement *pRoot, *pParm, *pParm2;
	pRoot = doc.FirstChildElement("view");

	pParm = pRoot->FirstChildElement("element");
	while (pParm)
	{
		Element* el = new Element(
			atoi(pParm->FirstChildElement("x")->FirstChild()->ToText()->Value()),
			atoi(pParm->FirstChildElement("y")->FirstChild()->ToText()->Value()),
			atoi(pParm->FirstChildElement("width")->FirstChild()->ToText()->Value()),
			atoi(pParm->FirstChildElement("height")->FirstChild()->ToText()->Value())
			);

		std::string eventName = "";
		if (pParm->FirstChildElement("onclick") != nullptr)
		{
			if (location_name.length() > 0)
			{
				eventName = pParm->FirstChildElement("onclick")->FirstChild()->ToText()->Value();

				pEvent = pRoot2->FirstChildElement("event");
				while (pEvent)
				{
					if (eventName == pEvent->Attribute("place"))
					{
						el->setOnClick(pEvent->FirstChildElement("onclick")->FirstChild()->ToText()->Value());
					}
					pEvent = pEvent->NextSiblingElement("event");
				}
			}
			else
			{
				el->setOnClick(pParm->FirstChildElement("onclick")->FirstChild()->ToText()->Value());
			}
		}

		if (pParm->FirstChildElement("onhover") != nullptr)
		{
			TiXmlElement* onHover = pParm->FirstChildElement("onhover");
			int x = atoi(onHover->Attribute("x"));
			int y = atoi(onHover->Attribute("y"));
			int width = atoi(onHover->Attribute("width"));
			int height = atoi(onHover->Attribute("height"));
			std::string temp = onHover->FirstChild()->ToText()->Value();
			temp = "../data/images/" + temp;
			char * text = _strdup(temp.c_str());
			el->setOnHover(new Texture(x, y, width, height, text));
		}

		//load textures into list
		std::list<Texture*> tex = el->getTextures();

		pParm2 = pParm->FirstChildElement("textures")->FirstChildElement();
		while (pParm2)
		{
			const char *name = pParm2->Value();
			char * text;
			if ((strcmp(name, "texture") == 0) || (strcmp(name, "text") == 0) || (strcmp(name, "progress") == 0))
			{
				int x = atoi(pParm2->Attribute("x"));
				int y = atoi(pParm2->Attribute("y"));
				int width = atoi(pParm2->Attribute("width"));
				int height = atoi(pParm2->Attribute("height"));

				std::string temp = pParm2->FirstChild()->ToText()->Value();
				if (strcmp(name, "texture") == 0)
				{
					temp = "../data/images/" + temp;
					text = _strdup(temp.c_str());
					//load textures into opengl and add it to Element
					el->addTexture(new Texture(x, y, width, height, text));
				}
				else if (strcmp(name, "progress") == 0)
				{
					temp = "../data/images/" + temp;
					text = _strdup(temp.c_str());
					//load textures into opengl and add it to Element
					el->addTexture(new Progress(x, y, width, height, _strdup(pParm2->Attribute("name")), text));
				}
				else
				{
					text = _strdup(temp.c_str());
					if (pParm2->Attribute("display") != nullptr)
					{
						if (location_name.length() > 0)
						{
							pEvent = pRoot2->FirstChildElement("console");
							text = _strdup(pEvent->FirstChild()->ToText()->Value());
						}
						int fontSize = 0;
						if (pParm2->Attribute("size") != nullptr)
						{
							std::string fontSizeAttribute = pParm2->Attribute("size");
							fontSize = strtol(fontSizeAttribute.c_str(), NULL, 10);
						}
						Text * t = new Text(x, y, width, height, text, fontSize, true);
						if (pParm2->Attribute("color") != nullptr)
						{
							std::string color = pParm2->Attribute("color");
							int f1 = color.find(',');
							int f2 = color.find(',', f1 + 1);
							unsigned char r = strtol(color.substr(0, f1).c_str(), NULL, 10);
							unsigned char g = strtol(color.substr(f1 + 1, f2 - f1 - 1).c_str(), NULL, 10);
							unsigned char b = strtol(color.substr(f2 + 1, color.length() - f2 - 1).c_str(), NULL, 10);
							t->setColor(r, g, b);
						}
						el->addTexture(t);
					}
					else
					{
						if (location_name.length() > 0)
						{
							pEvent = pRoot2->FirstChildElement("event");
							while (pEvent)
							{
								if (eventName == pEvent->Attribute("place"))
								{
									text = _strdup(pEvent->FirstChildElement("text")->FirstChild()->ToText()->Value());
								}
								pEvent = pEvent->NextSiblingElement("event");
							}
						}

						int fontSize = 0;
						if (pParm2->Attribute("size") != nullptr)
						{
							std::string fontSizeAttribute = pParm2->Attribute("size");
							fontSize = strtol(fontSizeAttribute.c_str(), NULL, 10);
						}

						Text * t = new Text(x, y, width, height, text, fontSize);
						if (pParm2->Attribute("color") != nullptr)
						{
							std::string color = pParm2->Attribute("color");
							int f1 = color.find(',');
							int f2 = color.find(',', f1 + 1);
							unsigned char r = strtol(color.substr(0, f1).c_str(), NULL, 10);
							unsigned char g = strtol(color.substr(f1 + 1, f2 - f1 - 1).c_str(), NULL, 10);
							unsigned char b = strtol(color.substr(f2 + 1, color.length() - f2 - 1).c_str(), NULL, 10);
							t->setColor(r, g, b);
						}
						el->addTexture(t);
					}
				}
			}
			pParm2 = pParm2->NextSiblingElement();
		}
		elements.push_back(el);

		pParm = pParm->NextSiblingElement("element");
	}

	View *view = new View(elements);

	//load text
	file_name.replace(0, 4, "text");
	std::unordered_map<std::string, std::string> map = getTextMap(file_name);
	for (auto& x : map)
	{
		char first[256];
		char second[256];
		strcpy(first, x.first.c_str());
		strcpy(second, x.second.c_str());
		view->setText(first, second);
	}

	location_name.replace(0, 8, "locations/text");
	if (location_name.length() > 0)
	{
		map = getTextMap(location_name);
		for (auto& x : map)
		{
			char first[256];
			char second[256];
			strcpy(first, x.first.c_str());
			strcpy(second, x.second.c_str());
			view->setText(first, second);
		}
	}
	return view;
}

std::unordered_map<std::string, std::string> Model::getTextMap(
	std::string filename)
{
	std::string path = "../data/languages/" + language + "/" + filename + ".txt";
	std::string id;
	std::string text;

	std::ifstream lang_file;
	std::unordered_map<std::string, std::string> textMap;

	lang_file.open(path.c_str());
	lang_file.seekg(3, std::ios::beg);
	while (std::getline(lang_file, id) && std::getline(lang_file, text))
	{
		//textMap={id, text};
		textMap.insert(std::make_pair(id, text));
	}
	lang_file.close();

	return textMap;
}

void rotatePoint(int &x, int &y, float angle)
{//angle in degrees
	double rad = angle * M_PI / 180.0;//deg to rad
	double c = cos(rad);
	double s = sin(rad);

	int tx = x*c - y*s;
	int ty = x*s + y*c;
	x = tx;
	y = ty;
}

View* Model::getMap(std::string file_name, std::string location_name)
{
	std::list<Element*> elements;

	//load text
	std::string langFile = location_name;
	langFile.replace(0, 8, "locations/text");
	std::unordered_map<std::string, std::string> map = getTextMap(langFile);

	Element* el = new Element(630, 350, 20, 20);
	el->addTexture(new Texture(0, 0, 20, 20, "../data/images/point.png"));

	char * loc_name = _strdup(map["{locationName}"].c_str());
	if (strlen(loc_name) > 0)
	{
		el->addTexture(new Text(-90, -50, 200, 50, loc_name, 0));
	}
	else
	{
		el->addTexture(new Text(-90, -50, 200, 50, "?", 0));
	}
	elements.push_back(el);

	TiXmlDocument doc(("../data/locations/" + location_name + ".xml").c_str());
	doc.LoadFile();
	TiXmlElement *pRoot, *pRoad;
	pRoot = doc.FirstChildElement("location");

	pRoad = pRoot->FirstChildElement("road")->FirstChildElement("place");
	int points = 0;
	while (pRoad)
	{
		points++;
		pRoad = pRoad->NextSiblingElement("place");
	}

	int i = 0;
	pRoad = pRoot->FirstChildElement("road")->FirstChildElement("place");

	int seed = 0;
	for (int i = 0; i < location_name.length(); i++)
	{
		seed += location_name.at(i);
	}
	srand(seed);

	while (pRoad){
		int x = 0, y = -150 + (std::rand() % 50) - 25;
		rotatePoint(x, y, 360.0 / points*i + (std::rand() % 50) - 25);
		Element* el = new Element(630+x, 350+y, 20, 20);
		el->addTexture(new Texture(0, 0, 20, 20, "../data/images/point.png"));


		char * text = _strdup(pRoad->Attribute("onclick"));
		el->setOnClick(text);
		text = _strdup(pRoad->FirstChild()->ToText()->Value());
		char * temp_text = _strdup(map[text].c_str());
		if (strlen(temp_text) > 0)
		{
			text = temp_text;
		}

		el->setOnHover(new Text(-90, -50, 200, 50, text, 0));
		elements.push_back(el);

		i++;
		pRoad = pRoad->NextSiblingElement("place");
	}

	View* temp = new View(elements);

	View* v = getXml(file_name);
	v->extendView(temp);
	delete temp;
	return v;
}

View* Model::getFightView(std::string file_name, std::string name, std::string image_file)
{
	std::list<Element*> elements;

	Element* el = new Element(0, 0, 1280, 720);
	el->addTexture(new Texture(0, 0, 1280, 720, "../data/images/fight.jpg"));
	image_file = "../data/images/" + image_file;
	char* image_file_path = _strdup(image_file.c_str());
	el->addTexture(new Texture(750, 180, 235, 235, image_file_path));
	elements.push_back(el);

	View* temp = getXml(file_name);
	temp->setText("{oponent}", name.c_str());

	View* v = new View(elements);
	v->extendView(temp);
	delete temp;
	return v;
}