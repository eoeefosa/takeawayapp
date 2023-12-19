#pragma once

#include <vector>
#include <fstream>
#include "Item.h"

class ItemList
{
public:
    virtual ~ItemList();
    virtual std::string toString() const = 0;

protected:
    std::vector<Item *> items;
};

class Menu : public ItemList
{
public:
    Menu(const std::string &filePath);
    std::string toString() const override;
    size_t getItemsCount() const;
    const std::vector<Item *> &getItems() const;

private:
    void loadMenu(const std::string &filePath);
    Appetiser *readAppetiser(std::ifstream &file);
    MainCourse *readMainCourse(std::ifstream &file);
    Beverage *readBeverage(std::ifstream &file);
};
