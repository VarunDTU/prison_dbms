#include<iostream>
#include <conio.h>          //for getch() function
#include<fstream>           //for file handling
#include<stdlib.h>          //for system("CLS")
using namespace std;

string password="0000";

//gets password for session

void pass(){

        fstream pass_file;

        pass_file.open("password.text",ios::in);
        while (!pass_file.eof()){
        pass_file>>password;
        }

        pass_file.close();
}

//encrypts a string with return

string encrpt(string x){

    int key=26;
    for(int i=0;i<x.size();i++){
        x[i]+=26;
    }
    x="RWEWRwqe21WEEda"+x+"213wqweq";
    return x;

}

// changes password and stores new value(encrypted) in file


void password_change(string s){
        s=encrpt(s);

        fstream file;

       file.open("password.text",ios::app|ios::out);

       file<<s<<" ";

       file.close();



}

// class for prison had add(),show(),find() function

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
       file>>serial>>age>>time>>name>>crime;
       cout<<" serial: "<<serial<<endl<<" age: "<<age<<endl<<" time: "<<time<<endl<<" Name: "<<name<<endl<<" crime: "<<crime<<endl;
       cout<<endl<<endl;
          }
       file.close();
       getch();

    }


    void find(){


        int id_input,x=0;
        char ch;
        fstream file;
        cout<<"enter id number: ";
        cin>>id_input;

        file.open("prison.text",ios::in);
        while (!file.eof()){

                    file>>serial>>age>>time>>name>>crime;
                    if(serial==id_input){
                        cout<<" serial: "<<serial<<endl<<" age: "<<age<<endl<<" time: "<<time<<endl<<" Name: "<<name<<endl<<" crime: "<<crime<<endl;
       cout<<endl<<endl;
       x++;
                    }


        }
        if(x==0){
                cout<<"nothing found :( "<<endl;
                cout<<serial;
        }
        file.close();
        getch();

    }
};

// check the entered password against stored password

bool auth(){
     pass();
    cout<<"enter password"<<endl;
    string s;
    cin>>s;
    s=encrpt(s);
    if(s==password){
        return true;
    }

    return false;

}

//main function

int main(){

    int x;
    start:
    cout<<"hello to prison management system"<<endl<<"press enter to continue"<<endl;
    getch();

    if(!auth()){
            cout<<"Wrong password exiting.......";
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
    cout<<"3.show all prisoners value"<<endl;
    cout<<"4.change password"<<endl;
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
    s.show();
    getch();
    goto menu;
    break;

  case 4:{
    string newpass;
    cout<<"enter new password";
    cin>>newpass;
    password_change(newpass);

    goto start;
    break;
  }



  case 5:
      cout<<"enter valid input ";
      exit(0);
      goto menu;
  default:
    cout<<"wrong input :(";
    goto menu;


}

    return 0;
}
