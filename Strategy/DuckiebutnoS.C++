#include <iostream>

using namespace std;

class Duck
{
public:
    virtual void fly() = 0;
    virtual void quack() = 0;
    virtual void display() = 0;

    void swim()
    {
        cout << "All ducks float, even decoys!" << endl;
    }
};

class MallardDuck : public Duck
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

class RubberDuck : public Duck
{
public:
    void fly() override
    {
        cout << "I can't fly." << endl;
    }

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
    void fly() override
    {
        cout << "I can't fly." << endl;
    }

    void quack() override
    {
        cout << "<< Silence ... >>" << endl;
    }

    void display() override
    {
        cout << "I'm a fake duckie" << endl;
    }
};

int main()
{
    Duck *mallard = new MallardDuck();
    mallard->display();
    mallard->swim();
    mallard->fly();
    mallard->quack();

    cout << "-----------------------" << endl;

    Duck *rubber = new RubberDuck();
    rubber->display();
    rubber->swim();
    rubber->fly();
    rubber->quack();

    cout << "-----------------------" << endl;

    Duck *decoy = new DecoyDuck();
    decoy->display();
    decoy->swim();
    decoy->fly();
    decoy->quack();

    delete mallard;
    delete rubber;
    delete decoy;

    return 0;
}