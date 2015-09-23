#include "menu.hpp"

#include <iostream>
#include <sstream>

int getNumberInput()
{
    int input;

    std::string buffer;
    std::getline(std::cin, buffer);

    std::stringstream sstream(buffer);
    sstream >> input;

    return input;
}

Menu::Menu()
{
    end = false;
    eventList = std::vector<Event>();
}

void Menu::promptUser()
{
    int choice;
    do {
        displayOptions();

        choice = getNumberInput();
    } while (!makeChoice(choice));
}

bool Menu::makeChoice(int choice)
{
    switch(choice)
    {
        case 1:
            viewEvents();
            break;
        case 2:
            addEvent();
            break;
        case 3:
            editEvent();
            break;
        case 4:
            removeEvent();
            break;
        case 5:
            end = true;
            break;
        default:
            return false;
    }
    return true;
}

void Menu::displayOptions()
{
    std::cout << "MENU\n";
    std::cout << "---------------------\n";
    std::cout << "1. View Events\n";
    std::cout << "2. Add Event\n";
    std::cout << "3. Edit Event\n";
    std::cout << "4. Remove Event\n";
    std::cout << "5. Exit\n";
}

void Menu::viewEvents()
{
    std::cout << "EVENTS\n";
    std::cout << "------------------\n";

    int number = 1;
    for (Event event : eventList){
        std::cout << number << ". Event at: " << event  << std::endl;
        number++;
    }
}

void Menu::addEvent()
{
    std::cout << "Enter hour for the event : " << std::endl;
    int hour = getNumberInput();

    Event event(hour);
    eventList.push_back(event);
}

void Menu::removeEvent()
{
    std::cout << "Remove event #:\n";
    int index = getNumberInput();
    index--;

    if (index < 0 || index > eventList.size() || eventList.empty()) {
        return;
    }

    eventList.erase(eventList.begin() + index);
}

void Menu::editEvent()
{
    std::cout << "Edit event #\n";

    int index = getNumberInput();
    index--;

    Event event = NULL;
    try {
        event = eventList.at(index);
    }catch(std::out_of_range e){
        std::cout << "Invalid index" << std::endl;
        return;
    }

    std::cout << "Set new hour\n";
    int newHour = getNumberInput();
    if (!event.setHour(newHour)){
        std::cout << "Invalid hour" << std::endl;
    }
}

bool Menu::isEnd()
{
    return end;
}
