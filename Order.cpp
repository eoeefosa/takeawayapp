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
    if (index >= 1 && index <= items.size())
    {
        std::cout << items[index - 1]->getDescription() << " removed from order!" << std::endl;
        delete items[index - 1];
        items.erase(items.begin() + index - 1);
    }
    else
    {
        std::cerr << "Invalid index for removal." << std::endl;
    }
}

std::string Order::calculateTotal() const
{
    double total = 0.0;
    double savings = 0.0;

    for (const auto &item : items)
    {
        total += item->getPrice();
        // Check for 2-4-1 discount
        if (auto appetiser = dynamic_cast<const Appetiser *>(item))
        {
            if (appetiser->isTwoForOne())
            {
                savings += appetiser->getPrice();
            }
        }
    }

    // Apply discount
    total -= savings;

    return "2-4-1 discount applied! Savings: £" + std::to_string(savings) + "\n" +
           "Total: £" + std::to_string(total) + "\n";
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
    std::ofstream receiptFile("receipt.txt");
    if (!receiptFile.is_open())
    {
        std::cerr << "Error opening receipt file for writing." << std::endl;
        return;
    }

    receiptFile << toString() << std::endl;
    std::cout << calculateTotal() << toString() << std::endl;

    receiptFile.close();
    std::cout << "Receipt printed to receipt.txt" << std::endl;
}
