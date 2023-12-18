#include "Order.h"
#include <iostream>

Order::~Order()
{
    printReceipt();
}

void Order::add(Item *item)
{
    items.push_back(item->clone());
    std::cout << item->getDescription() << " added to order!" << std::endl;
}

void Order::remove(size_t index)
{
    // Implement remove function
}

std::string Order::calculateTotal() const
{
    // Implement calculateTotal function
}

std::string Order::toString() const
{
    std::string orderstr;
    for (size_t i = 0; i < items.size(); ++i)
    {
        orderstr += "(" + std::to_string(i + 1) + ")" + items[i]->getDescription() + "\n";
    }
    return orderstr;
}

void Order::printReceipt() const
{
    // Implement printReceipt function
}
