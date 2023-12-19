#include "Menu.h"
#include <iostream>
using namespace std;

ItemList::~ItemList()
{
    for (auto item : items)
    {
        delete item;
    }
}

Menu::Menu(const string &filePath)
{
    loadMenu(filePath);
}

const vector<Item *> &Menu::getItems() const
{
    return items;
}

size_t Menu::getItemsCount() const
{
    return items.size();
}

string Menu::toString() const
{
    string menuStr;
    for (size_t i = 0; i < items.size(); ++i)
    {
        menuStr += "(" + to_string(i + 1) + ") " + items[i]->getDescription() + "\n";
    }
    return menuStr;
}

void Menu::loadMenu(const string &filePath)
{
    ifstream file(filePath);
    if (!file.is_open())
    {
        throw runtime_error("Error opening menu files: " + filePath);
    }

    char type;
    while (file >> type)
    {
        Item *newItem;
        if (type == 'a')
        {
            newItem = readAppetiser(file);
        }
        else if (type == 'm')
        {
            newItem = readMainCourse(file);
        }
        else if (type == 'b')
        {
            newItem = readBeverage(file);
        }
        else
        {
            throw runtime_error("Invalid item type in menu file: " + type);
        }

        items.push_back(newItem);
    }

    file.close();
}

Appetiser *Menu::readAppetiser(std::ifstream &file)
{
    string name;
    double price;
    int calories;
    bool shareable;
    bool twoForOne;
    file >> name >> price >> calories >> shareable >> twoForOne;
    return new Appetiser(name, price, calories, shareable, twoForOne);
}

MainCourse *Menu::readMainCourse(std::ifstream &file)
{
    string name;
    double price;
    int calories;
    file >> name >> price >> calories;
    return new MainCourse(name, price, calories);
}

Beverage *Menu::readBeverage(ifstream &file)
{
    string name;
    double price;
    int calories;
    int volume;
    double abv;
    file >> name >> price >> calories >> volume >> abv;
    return new Beverage(name, price, calories, volume, abv);
}
