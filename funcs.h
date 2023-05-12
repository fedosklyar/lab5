//#include "event.h"
//#pragma once
#include "meeting.h"
//#include "birthday.h"


int enter_the_quan();
void create_events(meeting *meetings, int N, birthday &birthday);
void create_date(int &day, int &month, int &year);
void create_time(int &hours, int &minutes);
void create_meeting(meeting &obj);
void create_birthday(birthday &obj);
void enter_date(int &day, int &month, int &year);
bool day_validate(int day, int month, int year);
void enter_time(int &hours, int &minutes);
bool time_validate(int hours, int minutes);
void timetable(meeting *objs, birthday birt, int N);
void define_the_substraction(meeting *objs, birthday birt, int N);