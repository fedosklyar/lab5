#include "birthday.h"


class meeting: public Event{
    string person;
    string place_of_meeting;

    public:
    meeting (meeting &obj);
    meeting();
    void display_meeting();
    void set_name(string name);
    void set_place(string place);
};

