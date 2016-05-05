#include "model.h"

Model::Model()
{
}

Model::~Model()
{

}

View *Model::getXml(std::string file_name)
{
	std::list<Element*> elements;

	TiXmlDocument doc(("../data/" + file_name + ".xml").c_str());
	doc.LoadFile();

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

		if (pParm->FirstChildElement("onclick") != nullptr)
		{
			el->setOnClick(pParm->FirstChildElement("onclick")->FirstChild()->ToText()->Value());
		}

		if (pParm->FirstChildElement("onhover") != nullptr)
		{
			TiXmlElement* onHover = pParm->FirstChildElement("onhover");
			int x = atoi(onHover->Attribute("x"));
			int y = atoi(onHover->Attribute("y"));
			int width = atoi(onHover->Attribute("width"));
			int height = atoi(onHover->Attribute("height"));
			std::string temp = onHover->FirstChild()->ToText()->Value();
			temp = "../data/" + temp;
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
			if ((strcmp(name, "texture") == 0) || (strcmp(name, "text") == 0))
			{
				int x = atoi(pParm2->Attribute("x"));
				int y = atoi(pParm2->Attribute("y"));
				int width = atoi(pParm2->Attribute("width"));
				int height = atoi(pParm2->Attribute("height"));

				std::string temp = pParm2->FirstChild()->ToText()->Value();
				if (strcmp(name, "texture") == 0)
				{
					temp = "../data/" + temp;
					text = _strdup(temp.c_str());
					//load textures into opengl and add it to Element
					el->addTexture(new Texture(x, y, width, height, text));
				}
				else
				{
					text = _strdup(temp.c_str());
					if (pParm2->Attribute("display") != nullptr)
					{
						el->addTexture(new Text(x, y, width, height, text, NULL, true));
					}
					else
					{
						el->addTexture(new Text(x, y, width, height, text, NULL));
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
