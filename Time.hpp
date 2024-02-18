//
//  Time.hpp
//  Lab1 - Manage User Accounts
//
//  Created by Eden Meseret on 2/11/24.
//

#ifndef Time_hpp
#define Time_hpp
#include <string>
#include <sstream>
#include <ctime>


using namespace std;

class Time{
    
public:
    
    
    Time();
    Time(int hour, int minute, int second);
    ~Time();
    void setHour(int hour);
    void setMinute(int minute);
    void setSecond(int second);
    
    
    int getHour();
    int getMinute();
    int getSecond();
    

    

private:
    int hour, minute, second;
    
    
    
    
};

#endif /* Time_hpp */
