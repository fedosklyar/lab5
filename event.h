#pragma once
#include<iostream>
#include<ctime>
#include<string>
#include<iomanip>


using namespace std;


class Event{
    protected:
    tm date {0};

public:
    void set_date(int day, int mon, int year);
    void set_time(int hou, int min);
    void display_date();
    time_t get_time();
};