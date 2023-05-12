#include "meeting.h"

void meeting::set_name(string name){
    person = name;
}

void meeting::set_place(string place){
    place_of_meeting = place;
}

meeting::meeting (meeting &obj){
    date = obj.date;
}

meeting::meeting(){}


void meeting::display_meeting(){
    //this->display_date();
    char display[10];
    strftime(display, 10, "%H:%M", &date);
    printf("\nTime - %s\n", display);

    cout<<"The place of the meeting - "<<this->place_of_meeting<<endl;
    cout<<"The name of the appointee - "<<this->person<<endl;
}