#include "event.h"

class birthday: public Event{
    string name;
    int age;
    string place;

public:
    void set_name(string n);
    void set_place(string pl);
    void set_age(int a);
    //birthday(birthday &obj);
    birthday();
    void display_birthday();
};
