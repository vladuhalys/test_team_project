#include <iostream>
#include <string>

#include "data/file_work/file_work.h"

using namespace std;

class Animal {
private:
    string _name;

public:
    Animal(string name, int age) : _name(name) {}

    string getName() const { return _name; }

    virtual void makeSound() const {
        cout << _name << " издаёт неопределённый звук!" << endl;
    }

    virtual ~Animal() = default;
};

class Dog : public Animal
        {
public:
    Dog(string name, int age) : Animal(name, age) {}

    void makeSound() const override
    {
        cout << getName() << " Woof: gav-gav!" << endl;
    }
};

class Cat : public Animal {
public:
    Cat(string name, int age) : Animal(name, age) {}

    void makeSound() const override
    {
        cout << getName() << " meow: meow-meow!" << endl;
    }
};

int main()
{
    FileWork<Animal> file_work("animal.bin");
    Dog dog("Dog", 5);
    file_work.save_class(dog);
    return 0;
}
