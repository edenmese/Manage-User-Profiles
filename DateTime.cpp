//
//  DateTime.cpp
//  Lab1 - Manage User Accounts
//
//  Created by Eden Meseret on 2/9/24.
//

#include "DateTime.hpp"


DateTime::DateTime(){
    month = day = year = 0;
};

DateTime::DateTime(int month, int day, int year){
    this ->month = month;
    this->day = day;
    this->year = year;
}
DateTime::DateTime(string dt){
    
    istringstream iss(dt);
    string month, day, year, hour, minute, second;
    
    getline(iss, month,'/');
    getline(iss, day,'/');
    getline(iss, year,' ');
    getline(iss, hour,':');
    getline(iss, minute,':');
    getline(iss, second,',');
    

    
    setMonth(stoi(month));
    setDay(stoi(day));
    setYear(stoi(year));
    setHour(stoi(hour));
    setMinute(stoi(minute));
    setSecond(stoi(second));
}

string DateTime::now() {
    time_t t = time(0);
    tm* now = localtime(&t);
    
    return to_string(now -> tm_mon + 1) + "/" + to_string(now -> tm_mday) + "/" + to_string(now -> tm_year+1900) + " " + to_string(now -> tm_hour) + ":" + to_string(now -> tm_min) + ":" + to_string(now ->tm_sec);
    
}


string DateTime::toString(){
    return to_string(month) + "/" + to_string(day) + "/" + to_string(year) + " " + to_string(getHour()) + ":" + to_string(getMinute()) + ":" + to_string(getSecond());
}

string DateTime::format(){
    std::tm time_in = {getSecond(), getMinute(), getHour(), getDay() - 1, getMonth() - 1, getYear()};


    time_t t = std::mktime(&time_in);
    std::tm* time_out = std::localtime(&t);

    //out << time_out->tm_wday << endl;

    string weekday[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

    return weekday[time_out->tm_wday] + " " + to_string(month) + "/" + to_string(day) + "/" + to_string(year) + " " + to_string(getHour()) + ":" + to_string(getMinute()) + ":" + to_string(getSecond());
}

DateTime::~DateTime(){}



void DateTime::setDay(int day){
    this -> day = day;
}
void DateTime::setMonth(int month){
    this -> month = month;
}
void DateTime::setYear(int year){
    this -> year = year;
}


int DateTime::getDay(){
    return this->day;
}
int DateTime::getMonth(){
    return this->month;
}
int DateTime::getYear(){
    return this->year;
}
