#include "event.h"

void Event::set_date(int day, int mon, int year){
    date.tm_mday = day;
    date.tm_mon = mon;
    date.tm_year = year;
}

void Event::set_time(int hou, int min){
    date.tm_hour = hou;
    date.tm_min = min;
}

void Event::display_date(){
    Event obj;
    obj.date = this->date;
    obj.date.tm_year -=  1900;
    obj.date.tm_mon -= 1;

    char display[20];
    strftime(display, 20, "%d %B %Y", &obj.date);
    printf("\n====DATE====\n%s\n\n", display);
}


time_t Event::get_time(){
    tm temp = date;
    temp.tm_year -= 1900;
    temp.tm_mon -= 1;

    //cout<<"Time - "<<mktime(&temp)<<endl;
    return mktime(&temp);
}