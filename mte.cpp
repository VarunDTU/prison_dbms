#include<iostream>
#include <conio.h>
#include<fstream>
using namespace std;

string password="1234";

class prison{
private:
    int serial,age,time;
    string name,crime;

public:
    void add(){
        fstream file;
       cout<<"enter id:  ";
       cin>>serial;
       cout<<"enter age:  ";
       cin>>age;
       cout<<"enter time to serve  :";
       cin>>time;
       cout<<"enter name:  ";
       cin>>name;
       cout<<"enter crime:  ";
       cin>>crime;


       file.open("prison.text",ios::app|ios::out);
       file<<" "<<serial<<" "<<age<<" "<<time<<" "<<name<<" "<<crime;
       file.close();

    }
    void show(){
        char ch;
        fstream file;
        file.open("prison.text",ios::in);
       file>>ch>>serial>>ch>>age>>ch>>time>>ch>>name>>ch>>crime;
       cout<<" serial: "<<serial<<endl<<" age: "<<age<<endl<<" time: "<<time<<endl<<" Name"<<name<<endl<<" crime"<<crime<<endl;
       file.close();

    }
    void remove(){
         char ch;
        fstream file;
        file.open("prison.text",ios::in);
       file>>ch>>serial>>ch>>age>>ch>>time>>ch>>name>>ch>>crime;

    }

    void find(){


    }
};

bool auth(){
    cout<<"enter password"<<endl;
    string s;
    cin>>s;
    if(s==password){
            cout<<"true";
        return true;
    }

    return false;

}

int main(){
    cout<<"hello to prison management system"<<endl<<"press enter to continue"<<endl;
    getch();

    if(!auth()){
            cout<<"lul";
            getch();
            exit(0);
    }
    cout<<"correct password"<<endl;

    prison s;
    s.show();
    //s.add();

    return 0;
}
