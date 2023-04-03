#include <iostream>

using namespace std;

class Flyable
{
public:
    virtual void fly() = 0;
};

class Quackable
{
public:
    virtual void quack() = 0;
};

class Duck
{
public:
    virtual void display() = 0;
    virtual void swim()
    {
        cout << "All ducks float, even decoys!" << endl;
    }
};

class MallardDuck : public Duck, public Flyable, public Quackable
{
public:
    void fly() override
    {
        cout << "I'm flying with wings!" << endl;
    }

    void quack() override
    {
        cout << "Quack!" << endl;
    }

    void display() override
    {
        cout << "I'm a real Mallard duck" << endl;
    }
};

class RubberDuck : public Duck, public Quackable
{
public:
    void quack() override
    {
        cout << "Squeak!" << endl;
    }

    void display() override
    {
        cout << "I'm a rubber duckie" << endl;
    }
};

class DecoyDuck : public Duck
{
public:
    void display() override
    {
        cout << "I'm a fake duckie" << endl;
    }
};

int main()
{
    MallardDuck *mallard = new MallardDuck();
    mallard->display();
    mallard->swim();
    mallard->fly();
    mallard->quack();

    cout << "-----------------------" << endl;

    RubberDuck *rubber = new RubberDuck();
    rubber->display();
    rubber->swim();
    rubber->quack();

    cout << "-----------------------" << endl;

    DecoyDuck *decoy = new DecoyDuck();
    decoy->display();
    decoy->swim();

    delete mallard;
    delete rubber;
    delete decoy;

    return 0;
}
