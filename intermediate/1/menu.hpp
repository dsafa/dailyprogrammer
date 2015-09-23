#ifndef MENU_H
#define MENU_H

#include "event.hpp"

#include <string>
#include <vector>

class Menu
{
public:
    Menu();
    void promptUser();
    bool isEnd();

private:
    void displayOptions();
    bool makeChoice(int choice);
    void viewEvents();
    void addEvent();
    void removeEvent();
    void editEvent();

    std::vector<Event> eventList;
    bool end;
};

#endif
