//
// Created by Ansh Pahwa on 01-04-2023.

//

#include <iostream>
#include <string>

using namespace std;

class Animal {
    public:
    int age;
   string name;

   void eat(){
    cout<<"eating"<<endl;
   }
   void sleep(){
    cout<<"sleeping"<<endl;
   }
};

int main() {
 
    Animal *Ansh =new Animal;
    (*Ansh).age=16;
    (*Ansh).name="Pahwa";
    cout<<(*Ansh).age<<endl;
    cout<<(*Ansh).name<<endl;
    cout<<Ansh->age<<endl;
    cout<<Ansh->name;
    Ansh->eat();
    delete Ansh;
    return 0;
}

