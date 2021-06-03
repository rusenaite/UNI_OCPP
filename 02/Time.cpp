#include "Time.hpp"

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <stdexcept>

//---------------------------------------------------------------------

Time::Time()
{
    setHours(12);
    setMinutes(0);
    setSeconds(0);
}

Time::Time(int hours, int minutes, int seconds)
{
    setHours(hours);
    setMinutes(minutes);
    setSeconds(seconds);
}

Time::~Time()
{
    std::cout << "Class deleted" << std::endl;
}

//---------------------------------------------------------------------

void Time::setHours(int h_value)
{
    if(0 <= h_value && h_value < 24) {
        hours = h_value;
    } else{
        throw std::invalid_argument("Entered invalid 'hours' value.");
    }
}

void Time::setMinutes(int m_value)
{
    if(0 <= m_value && m_value < 60) {
        minutes = m_value;
    } else{
        throw std::invalid_argument("Entered invalid 'minutes' value.");
    }
}

void Time::setSeconds(int s_value)
{
    if(0 <= s_value && s_value < 60) {
        seconds = s_value;
    } else{
        throw std::invalid_argument("Entered invalid 'seconds' value.");
    }
}

int Time::getHours()
{
    return hours;
}

int Time::getMinutes()
{
    return minutes;
}

int Time::getSeconds()
{
    return seconds;
}

void Time::addHour()
{
    setHours(++hours);
    if(hours > 23){
        hours = 0;
    }
}

void Time::addMin()
{
    setMinutes(++minutes);
    if(minutes > 59){
        addHour();
        minutes = 0;
    }
}

void Time::addSec()
{
    setSeconds(++seconds);
    if(seconds > 59){
        addMin();
        seconds = 0;
    }
}

//---------------------------------------------------------------------

//printing US time
std::string Time::showTimeUS()
{
    std::stringstream ss;
    bool am = false;
    if(hours <= 12){
        am = true;
    }
    if(hours > 13){
        hours -= 12;
    }
    ss << std::setfill('0');
    ss << "US Time: " << std::setw(2) << hours << ":"
       << std::setw(2) << minutes << ":"
       << std::setw(2) << seconds;
    if(am == true){
        ss << " AM";
    } else{
        ss << " PM";
    }
    return ss.str();
}


//printing LT time
std::string Time::showTimeLT()
{
    std::stringstream ss;
    ss << std::setfill('0');
    ss << "LT Time: " << std::setw(2) << hours << ":"
       << std::setw(2) << minutes << ":"
       << std::setw(2) << seconds;
    return ss.str();
}
