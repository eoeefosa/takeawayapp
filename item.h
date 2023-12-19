#pragma once

#include <string>

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

class MainCourse : public Item
{
public:
    MainCourse(const std::string &name, double price, int calories);
    Item *clone() const override;
};

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
