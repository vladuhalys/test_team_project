#include <iostream>
#include <string>

using namespace std;

class Animal {
private:
    string _name;

public:
    Animal(string name, int age) : _name(name), _age(age) {}

    [[nodiscard]] string getName() const { return _name; }
    [[nodiscard]] int getAge() const { return _age; }

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

int main() {
    Dog dog("Bobic", 3);
    Cat cat("Murka", 2);

    dog.makeSound();
    cat.makeSound();

    return 0;
}
