#pragma once

#include <string>
/// Definition of Item class storing  the general information
/// (name, calories, price) about the food and drink items available to purchase
class Item
{
public:
    Item(const std::string &name, double price, int calories);
    virtual ~Item() = default;

    virtual std::string getDescription() const;
    double getPrice() const;
    virtual Item *clone() const;

protected:
    std::string name;
    double price;
    int calories;
};

/// @brief Definition of appetiser class containing two attributes; shareable and twoForOne.
class Appetiser : public Item
{
public:
    Appetiser(const std::string &name, double price, int calories, bool shareable, bool twoForOne);
    std::string getDescription() const override;
    bool isTwoForOne() const;
    Item *clone() const override;

private:
    bool shareable;
    bool twoForOne;
};

/// @brief Definition of MainCourse class with no additional attributes
class MainCourse : public Item
{
public:
    MainCourse(const std::string &name, double price, int calories);
    Item *clone() const override;
};

/// @brief  Definition of Beverage class containing two attribute abv and volume.
class Beverage : public Item
{
public:
    Beverage(const std::string &name, double price, int calories, int volume, double abv);
    std::string getDescription() const override;
    Item *clone() const override;

private:
    int volume;
    double abv;
};
