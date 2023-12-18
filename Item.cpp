#include "Item.h"

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

// Implement Appetiser, MainCourse, and Beverage member functions here
