/* ------------------------------------------------------
CMP2811 Applied Programming Paradigms
Driver program for "Takeaway" assignment
Autumn 2023

This file is a representative test file.
During marking, we will use the exact same notation
as provided in the brief, so make sure you follow that guideline.
Also make sure that you don't modify the code provided here,
but instead add what you need to complete the tasks.

Good luck!
------------------------------------------------------ */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <iomanip>
#include "Menu.h"
#include "Order.h"
#include "Item.h"

using namespace std;

int main()
{
    string userCommand;
    vector<string> parameters;

    // Create a menu object from a CSV file
    Menu menu = Menu("menu.csv");

    // Create an order object
    Order order = Order();

    while (userCommand != "exit")
    {
        getline(cin, userCommand);
        char *cstr = new char[userCommand.length() + 1];
        strcpy(cstr, userCommand.c_str());

        char *token;
        token = strtok(cstr, " ");

        while (token != NULL)
        {
            parameters.push_back(token);
            token = strtok(NULL, " ");
        }

        string command = parameters[0];

        if (command.compare("menu") == 0)
        {
            cout << menu.toString();
        }
        else if (command.compare("add") == 0)
        { // Check if there is an item index specified
            if (parameters.size() > 1)
            {
                // Loop through the parameters to add multiple items at once
                for (size_t i = 1; i < parameters.size(); ++i)
                {
                    // Convert the parameter to an integer (item index)
                    int itemIndex = stoi(parameters[i]);

                    // Check if the item index is valid
                    // if (itemIndex >= 1 && itemIndex <= menu.items.size())
                    if (itemIndex >= 1 && itemIndex <= menu.getItemsCount())

                    {
                        // Get the selected item from the menu and add it to the order
                        Item *choice = menu.getItems()[itemIndex - 1]->clone();
                        order.add(choice);
                    }
                    else
                    {
                        cerr << "Invalid item index: " << itemIndex << ". Skipping..." << endl;
                    }
                }
            }
            else
            {
                cerr << "Usage: add <item_index> [item_index2 item_index3 ...]" << endl;
            }
        }
        else if (command.compare("remove") == 0)
        {
        }
        else if (command.compare("checkout") == 0)
        {
        }
        else if (command.compare("help") == 0)
        {
        }

        parameters.clear();
    }

    cout << "Press any key to quit...";
    // std::getchar();
}