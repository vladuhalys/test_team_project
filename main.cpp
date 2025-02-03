#include <iostream>
#include <string>

using namespace std;

class Animal {
private:
    string _name;

public:
    Animal(string name, int age) : _name(name), _age(age) {}

    string getName() const { return _name; }
    int getAge() const { return _age; }

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

    return 0;
}
