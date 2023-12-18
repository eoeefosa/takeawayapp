#pragma once

#include <fstream>
#include "Menu.h"

class Order : public ItemList
{
public:
    ~Order();
    void add(Item *item);
    void remove(size_t index);
    std::string calculateTotal() const;
    std::string toString() const override;
    void printReceipt() const;
};
