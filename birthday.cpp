#include "birthday.h"



birthday::birthday(){}

void birthday:: set_name(string n){
    name = n;
}


void birthday::set_place(string pl){
    place = pl;

}
void birthday::set_age(int a){
    age = a;
}

void birthday::display_birthday(){
    //this->display_date();
    char display[10];
    strftime(display, 10, "%H:%M", &date);
    printf("\nTime - %s", display);

    cout<<"\nThe name of birthday person - "<<name<<endl;
    cout<<"The age - "<<age<<endl;
    cout<<"The place of celebrating the birthday - "<<place<<endl;
}