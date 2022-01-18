#include<iostream>
#include <conio.h>
#include<fstream>
#include<stdlib.h>
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
          while (!file.eof()){
       file>>ch>>serial>>ch>>age>>ch>>time>>ch>>name>>ch>>crime;
       cout<<" serial: "<<serial<<endl<<" age: "<<age<<endl<<" time: "<<time<<endl<<" Name: "<<name<<endl<<" crime: "<<crime<<endl;
       cout<<endl<<endl;
          }
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
        return true;
    }

    return false;

}

int main(){
    int x;
    cout<<"hello to prison management system"<<endl<<"press enter to continue"<<endl;
    getch();

    if(!auth()){
            cout<<"lul";
            getch();
            exit(0);
    }
    cout<<"correct password"<<endl;

    prison s;

    menu:
    system("CLS");
    cout<<"Enter choices:"<<endl;
    cout<<"1.Add prison information:"<<endl;
    cout<<"2.Find prisoner: "<<endl;
    cout<<"3.Remove prisoner"<<endl;
    cout<<"4.show all prisoners value"<<endl;
    cout<<"5.exit"<<endl;
    cin>>x;
    switch(x) {
  case 1:
    s.add();
    goto menu;
    break;
  case 2:
    s.find();
    goto menu;
    break;
  case 3:
    s.remove();
    goto menu;
    break;
  case 4:
    s.show();
    getch();
    goto menu;
    break;
  case 5:
    exit(0);

  default:
      cout<<"enter valid input ";
      exit(0);
      goto menu;

    // code block
}

    return 0;
}
