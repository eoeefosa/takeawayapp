#include "Menu.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
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
    string menuStr = "";
    for (size_t i = 0; i < items.size(); ++i)
    {
        //  menuStr += "(" + to_string(i + 1) + ") " + items[i]->getDescription() + "\n";

        menuStr += "(" + to_string(i + 1) + ")" + items[i]->getDescription() + "\n";
    }
    return menuStr;
}

void Menu::loadMenu(const string &filePath)
{
    ifstream file(filePath);
    if (!file.is_open())
    {
        throw runtime_error("Error opening menu file: " + filePath);
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

        if (newItem != nullptr)
        {
            items.push_back(newItem);
        }
    }

    file.close();
}

Appetiser *Menu::readAppetiser(std::ifstream &file)
{

    // return appetisers;
    if (!file)
    {
        cerr << "Error reading data from the file." << endl;
        return nullptr;
    }

    string line;
    getline(file, line);

    string itemye;
    string name;
    string tempPrice;
    double price = 0.0;
    string tempCalories;
    int calories = 0;
    string tempShareableChar;
    string temptwoForOnechar;

    stringstream ss(line);

    getline(ss, itemye, ',');

    getline(ss, name, ',');
    getline(ss, tempPrice, ',');
    // price = std::stod(tempPrice);
    try
    {
        price = std::stod(tempPrice);
    }
    catch (const std::invalid_argument &e)
    {
        cerr << "Error converting string to double: " << e.what() << endl;
        // Handle the error as needed (possibly set a default value or terminate the program)
        return nullptr; // or any other appropriate action
    }

    getline(ss, tempCalories, ',');
    calories = atol(tempCalories.c_str());
    getline(ss, tempShareableChar, ',');
    getline(ss, temptwoForOnechar, ',');
    bool shareable = (tempShareableChar == "y" || tempShareableChar == "Y");
    bool twoForOne = (temptwoForOnechar == "y" || temptwoForOnechar == "Y");

    cout << "Name: " << name << endl;
    cout << "Calories: " << calories << ", ";
    cout << "Price: £" << price << ", ";
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
