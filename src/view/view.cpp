#include "view.h"
#include "../controller/controller.h"
#include <iostream>

View::View(std::list<Element*> elements) {
	this->elements = elements;
	this->clickMap.push_back(0);
}

View::~View() {
	for (auto i = this->elements.begin(); i != this->elements.end();) {
		auto tmpElem = *i;
		i = this->elements.erase(i);
		delete tmpElem;
		this->elements.insert(i, tmpElem);
	}
}

std::list<Element*> View::getList() {
	return this->elements;
}

void View::setText(char* name, std::string text) {
	char * t = _strdup(text.c_str());
	for (auto i = this->elements.begin(); i != this->elements.end();) {
		auto tmpElem = *i;
		i = this->elements.erase(i);
		tmpElem->setText(name,t);
		this->elements.insert(i, tmpElem);
	}
	delete t;
}

void View::setFill(char* name, unsigned char fill)
{
	for (auto i = this->elements.begin(); i != this->elements.end();)
	{
		auto tmpElem = *i;
		i = this->elements.erase(i);
		tmpElem->setFill(name, fill);
		this->elements.insert(i, tmpElem);
	}
}

void View::setOnHoverText(char * name, std::string text)
{
	std::cout << "onHover" << std::endl;
	char * t = _strdup(text.c_str());
	for (auto i = this->elements.begin(); i != this->elements.end();)
	{
		auto tmpElem = *i;
		i = this->elements.erase(i);
		tmpElem->setText(name, t);
		this->elements.insert(i, tmpElem);
	}
}

void View::extendView(View* v, bool locked)
{
	views.push_back(this->elements.size());

	if (locked)
	{
		this->clickMap.push_back(this->elements.size());
	}

	for (auto i = v->elements.begin(); i != v->elements.end();)
	{
		auto tmpElem = *i;
		i = v->elements.erase(i);
		
		this->elements.push_back(tmpElem);
	}
}

void View::removeLastView()
{
	if (views.size() > 0) {
		std::list<Element*>::iterator it = this->elements.begin();
		std::advance(it, this->views.back());

		if (this->clickMap.back() == this->views.back())
		{
			this->clickMap.pop_back();
		}

		for (std::list<Element*>::iterator i = it; i != this->elements.end();)
		{
			auto tmpElem = *i;
			delete tmpElem;
			i = this->elements.erase(i);
		}

		views.pop_back();
	}
}

int View::getClickMap()
{
	return this->clickMap.back();
}