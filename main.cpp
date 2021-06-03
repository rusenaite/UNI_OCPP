#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include "Time.hpp"
#include "Time.cpp"


int main(){
    int n = 3;
    std::vector<int> v;
    int hours = 0, minutes = 0, seconds = 0;
    Time time;

    std::cout << "Enter hours, minutes and seconds values in the same order: " << std::endl;
    for(int i = 0; i < n;){
        try{
            std::cin >> hours;
            std::cin >> minutes;
            std::cin >> seconds;
            time.setHours(hours);
            time.setMinutes(minutes);
            time.setSeconds(seconds);
            v.push_back(hours);
            v.push_back(minutes);
            v.push_back(seconds);
            std::cout << "Printing Time: " << std::endl;
            std::cout << time.showTimeLT() << std::endl;
            std::cout << time.showTimeUS() << std::endl;
            ++i;
        }
        catch(std::invalid_argument &error){
            std::cerr << "Error value: " << error.what() << std::endl;
            std::cout << "Re-enter hours, minutes and seconds." << std::endl;
        }
        catch(...){
            std::cout << "Default exception" << std::endl;
        }
    }

    Time time1;
    int hr = 3, m = 33, sec = 33;
    try{
        time1.setHours(hr);
        time1.setMinutes(m);
        time1.setSeconds(sec);
        time1.addHour();
        time1.addMin();
        time1.addSec();
        std::cout << "\nPrinting Time1: " << std::endl;
        std::cout << time1.showTimeLT() << std::endl;
        std::cout << time1.showTimeUS() << std::endl;

    }
    catch(std::invalid_argument &error){
        std::cerr << "\nError value: " << error.what() << std::endl;
    }
    catch(...){
        std::cout << "\nDefault exception" << std::endl;
    }

    return 0;
}
