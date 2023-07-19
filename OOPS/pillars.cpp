//
// Created by Ansh Pahwa on 01-04-2023.

//

#include <iostream>
#include <string>

using namespace std;

class Animal
{
private:
    int age;
    int weight;

public:
    void eat()
    {
        cout << "eating" << endl;
    }
    void setAge(int age)
    {
        this->age = age;     
    }
    int getAge()
    {
        return age;
    }
};

int main()
{

    return 0;
}
