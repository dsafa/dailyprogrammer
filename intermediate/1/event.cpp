#include "event.hpp"

Event::Event(int hour)
{
    if(!setHour(hour)) {
        setHour(0);
    }
}


int Event::getHour()
{
    return hour;
}

bool Event::setHour(int newHour)
{
    if (newHour < 0 || newHour > 24){
        return false;
    }else{
        hour = newHour;
        return true;
    }
}

std::ostream& operator<<(std::ostream& ostream, const Event &event)
{
    ostream << event.hour;
    return ostream;
}
