#ifndef TIME_HPP
#define TIME_HPP

#include <string>

class Time
{
    public:
        Time();
        Time(int, int, int);
        ~Time();

        void setHours(int);
        void setMinutes(int);
        void setSeconds(int);

        int getHours();
        int getMinutes();
        int getSeconds();

        void addHour();
        void addMin();
        void addSec();
        std::string showTimeUS();
        std::string showTimeLT();

    private:
        int hours;
        int minutes;
        int seconds;
};

#endif // TIME_HPP
