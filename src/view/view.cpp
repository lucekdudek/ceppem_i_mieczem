#include "view.h"
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
}

void View::extendView(View* v, bool locked)
{
	auto iter = this->elements.end();
	iter--;
	iterators.push_back(iter);

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
	if (iterators.size() > 0) {
		if ((this->clickMap.back() - 1) == (std::distance(this->elements.begin(), iterators.back())))
		{
			this->clickMap.pop_back();
		}

		for (std::list<Element*>::iterator i = ++iterators.back(); i != this->elements.end();)
		{
			auto tmpElem = *i;
			delete tmpElem;
			i = this->elements.erase(i);
		}

		iterators.pop_back();
	}
}

int View::getClickMap()
{
	return this->clickMap.back();
}