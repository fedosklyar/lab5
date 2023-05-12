#include "funcs.h"

int enter_the_quan(){
    bool check;
    int N;
    do{
        cout<<"Enter the quantity of events (MAX - 7): ";
        cin>>N;
        if(N < 2 || N > 7) cout<<"Wrond quantity of events (must be between 2 and 7)\nPlease, try again:\n";
    }while(N < 2 || N > 7);
    cout<<"\nQuan = "<<N<<endl;

    return N;
}


void create_events(meeting *meetings, int N, birthday &birthday){
    int day, month, year;
    create_date(day, month, year);


    cout<<"=======Meetings======="<<endl;
    for(int i = 0; i < N - 1; i++){
        create_meeting(meetings[i]);
        meetings[i].set_date(day, month, year);
        meetings[i].display_meeting();
    }

    create_birthday(birthday);
    birthday.set_date(day, month, year);
    birthday.display_birthday();

}


void create_meeting(meeting &obj){

    int hours, minutes;

    create_time(hours, minutes);


    
    obj.set_time(hours, minutes);

    string place_of_meeting, meeter_name;

    cout<<"Enter the name of the place of the meeting: ";
    getline(cin, place_of_meeting);
    obj.set_place(place_of_meeting);

    cout<<"Enter the name of the the appointee: ";
    getline(cin, meeter_name);
    obj.set_name(meeter_name);
}



void create_birthday(birthday &obj){
    int day, month, year, hours, minutes;

    cout<<"\n\n=====BIRTHDAY====="<<endl;

    create_time(hours, minutes);

    obj.set_time(hours, minutes);

    string name, place;
    int age;

    cout<<"Enter the name of the birthday person: ";
    getline(cin, name);
    obj.set_name(name);



    cout<<"Enter the place of celebrating the birthday: ";
    getline(cin, place);
    obj.set_place(place);

    do{
        cout<<"Enter the age of the the birthday person(Max 100):";
        cin>>age;
        if(age < 1 || age > 100) cout<<"Wrong number for the age\nPlease, try again:\n";
    }while(age < 1 || age > 100);
    obj.set_age(age);


}




void create_date(int &day, int &month, int &year){
    bool check;


    do{
        cout<<"Enter the date (dd.mm.yyyy): ";
        enter_date(day, month, year);
        check = day_validate(day, month, year);
        if(check == false) cout<<"Wrong date, please, try again: "<<endl;
    }while(!check);


}


void create_time(int &hours, int &minutes){
    bool check;

    do{
        cout<<"Enter the time (hh:mm): ";
        enter_time(hours, minutes);
        check = time_validate(hours, minutes);
        if(check == false) cout<<"Wrong time, please, try again: "<<endl;
    }while(!check);

}






void enter_date(int &day, int &month, int &year){
    string num_line;

        getline(cin, num_line, '.');
        day = stoi(num_line);
        getline(cin, num_line, '.');
        month = stoi(num_line);
        getline(cin, num_line);
        year = stoi(num_line);
        cout<<"\nDay - "<<day<<" Month - "<<month<<" Year - "<<year<<endl;
}


bool day_validate(int day, int month, int year){
    time_t curr_time = time(NULL);
    tm *current_date = localtime(&curr_time);


    if(day > 31 || day < 1 || month > 12 || month < 1 || year < 1970 || year > current_date->tm_year + 1900) {
        return false;
        }
    else if((month == 4 || month == 6 || month == 9 || month == 11 || month == 2) && day == 31 || day >= 30 && month == 2) return false;

    return true;
}


void enter_time(int &hours, int &minutes){
    string time;

    getline(cin, time, ':');
    hours = stoi(time);
    getline(cin, time);
    minutes = stoi(time);
    cout<<"==Time==   "<<hours<<":"<<minutes<<endl;
}




bool time_validate(int hours, int minutes){
    if(hours < 0 || hours > 23 || minutes < 0 || minutes >= 60) return false;

    return true;
}


void timetable(meeting *objs, birthday birt, int N){
    birt.display_date();

    for(int i = 0; i < N; i++){
        objs[i].display_meeting();
    }

    birt.display_birthday();
}


void define_the_substraction(meeting *objs, birthday birt, int N){
    time_t max = 0, curr;
    int index = 0;

    for(int i = 0; i < N - 1; i++){
        curr = objs[i].get_time();
        if(curr > max) {
            max = curr;
            index = i;
        }
    }

    cout<<"\n=====The latest meeting:\n"; objs[index].display_meeting();
    cout<<"\n";


    time_t difference = difftime(birt.get_time(), objs[index].get_time());
    //cout<<"Difference = "<<difference<<endl;


    if(difference < 0) cout<<"The latest meeting takes place later, than the birthday";
    else {
        tm *differ = gmtime(&difference);
        cout<<"\n====The difference -->"<<differ->tm_hour<<" Hours and "<<differ->tm_min<<" Minutes===="<<endl;
    }

}