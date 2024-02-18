//
//  Time.cpp
//  Lab1 - Manage User Accounts
//
//  Created by Eden Meseret on 2/11/24.
//

#include "Time.hpp"


Time::Time(){}
Time::Time(int hour, int minute, int second){}
Time::~Time(){}

void Time::setHour(int hour){
    this->hour = hour;
}
void Time::setMinute(int minute){
    this->minute = minute;

}
void Time::setSecond(int second){
    this->second = second;

}


int Time::getHour(){
    return this->hour;
}
int Time::getMinute(){
    return this->minute;
}
int Time::getSecond(){
    return this->second;
}
