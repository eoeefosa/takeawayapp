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

void displayInstructions() {
    cout << "Welcome to the Takeaway App!" << endl;
    cout << "Available commands:" << endl;
    cout << " - menu: Display the menu" << endl;
    cout << " - add <item_index> [item_index2 item_index3 ...]: Add item(s) to the order" << endl;
    cout << " - remove <item_index>: Remove item from the order" << endl;
    cout << " - checkout: Process the order and print receipt" << endl;
    cout << " - help: Display this help message" << endl;
    cout << " - exit: Exit the application" << endl;
}


void displayHelp() {
    std::cout << "Available commands:" << std::endl;
    std::cout << "menu - display the menu to the user" << std::endl;
    std::cout << "add [INDEX] - add an item to the order by numeric index in the menu (starting at 1)" << std::endl;
    std::cout << "remove [INDEX] - remove item from order by numeric index in the order (starting at 1)" << std::endl;
    std::cout << "checkout - display the items in the user’s order, the price, and discount savings" << std::endl;
    std::cout << "help - display a help menu for the user with the available options" << std::endl;
    std::cout << "exit - terminate the program gracefully" << std::endl;
}


int main()
{
    string userCommand;
    vector<string> parameters;
    try {
    // Create a menu object from a CSV file
    Menu menu = Menu("menu.csv");
    displayInstructions();
    // Create an order object
    Order order = Order();

    while (userCommand != "exit")
    {
        getline(cin, userCommand);
        char* cstr = new char[userCommand.length() + 1];
        strcpy(cstr, userCommand.c_str());

        char* token;
        token = strtok(cstr, " ");

        while (token != NULL)
        {
            parameters.push_back(token);
            token = strtok(NULL, " ");
        }

        string command = parameters[0];
        try {
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
                        Item* choice = menu.getItems()[itemIndex - 1]->clone();
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
            if (parameters.size() > 1) {
                size_t index = std::stoi(parameters[1]);
                order.remove(index);
            }
            else {
                std::cerr << "Missing index for removal." << std::endl;
            }

        }
        else if (command.compare("checkout") == 0)
        {
            std::cout << "===== Checkout =====" << std::endl;
            std::cout << order.toString();
            order.calculateTotal();

            char choice;
            std::cout << "Do you want to place your order? Type 'y' to confirm, or 'n' to go back and modify it." << std::endl;
            std::cin >> choice;

            if (choice == 'y') {
                break;  // Exit the loop and end the program
            }
        }
        else if (command.compare("help") == 0)
        {
            displayHelp();
        }
        else if (command.compare("exit") == 0) {
            // Implement any necessary cleanup before exiting
            break;
        }
        else {
            std::cerr << "Invalid command. Type 'help' for available options." << std::endl;
        }

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    parameters.clear();
    delete[] cstr;
}
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    cout << "Press any key to quit...";
   
    std::getchar();

    return 0;
}