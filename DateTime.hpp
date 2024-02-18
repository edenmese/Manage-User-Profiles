//
//  DateTime.hpp
//  Lab1 - Manage User Accounts
//
//  Created by Eden Meseret on 2/9/24.
//

#ifndef DateTime_hpp
#define DateTime_hpp
#include <string>
#include "Time.hpp"


class DateTime:public Time {
public:
    DateTime();
    DateTime(int month, int day, int year);
//    DateTime(int mon, int day, int yr):Time(month, day,year);
    DateTime(string dt);
    ~DateTime();
    
    void setDay(int day);
    void setMonth(int month);
    void setYear(int year);
//    void getCurrentTime();
    static string now();
    string toString();
    
    string format();

    int getDay();
    int getMonth();
    int getYear();
    
    
    
    
    
    
    
private:
    int month, day, year;


};


#endif /* DateTime_hpp */
