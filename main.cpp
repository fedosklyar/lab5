//#include "event.h"
//#include "meeting.h"
//#include "birthday.h"
#include "funcs.h"


int main(){
    int quan = enter_the_quan();

    meeting *meetings = new meeting[quan - 1];
    birthday birth;
    create_events(meetings, quan, birth);
    timetable(meetings, birth, quan - 1);
    define_the_substraction(meetings, birth, quan);
    
    delete[] meetings;


    return 0;
}