#include "Item.h"

// Implementations for Item class

Item::Item(const std::string &name, double price, int calories)
    : name(name), price(price), calories(calories) {}

std::string Item::getDescription() const
{
    return name + " : £" + std::to_string(price) + ", " + std::to_string(calories) + " cal";
}

double Item::getPrice() const
{
    return price;
}

Item *Item::clone() const
{
    return new Item(*this);
}

// Implementations for Appetiser class

Appetiser::Appetiser(const std::string &name, double price, int calories, bool shareable, bool twoForOne)
    : Item(name, price, calories), shareable(shareable), twoForOne(twoForOne) {}

std::string Appetiser::getDescription() const
{
    std::string description = Item::getDescription();
    if (shareable)
    {
        description += " (shareable)";
    }
    if (twoForOne)
    {
        description += " (2-4-1)";
    }
    return description;
}

bool Appetiser::isTwoForOne() const
{
    return twoForOne;
}

Item *Appetiser::clone() const
{
    return new Appetiser(*this);
}

// Implementations for MainCourse class

MainCourse::MainCourse(const std::string &name, double price, int calories)
    : Item(name, price, calories) {}

Item *MainCourse::clone() const
{
    return new MainCourse(*this);
}

// Implementations for Beverage class

Beverage::Beverage(const std::string &name, double price, int calories, int volume, double abv)
    : Item(name, price, calories), volume(volume), abv(abv) {}

std::string Beverage::getDescription() const
{
    return Item::getDescription() + " (" + std::to_string(volume) + "ml, " + std::to_string(abv) + "% abv)";
}

Item *Beverage::clone() const
{
    return new Beverage(*this);
}
