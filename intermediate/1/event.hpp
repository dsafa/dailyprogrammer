#ifndef EVENT_H
#define EVENT_H

#include <iostream>

class Event
{
public:
    Event(int hour);
    int getHour();
    bool setHour(int newHour);
    friend std::ostream& operator<<(std::ostream& ostream, const Event &event);
private:
    int hour;
};

#endif
