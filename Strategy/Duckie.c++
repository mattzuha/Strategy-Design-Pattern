#include <iostream>

using namespace std;

// 4.1
// Interface
class FlyBehavior
{
public:
    virtual void fly() = 0;
};

class FlyWithWings : public FlyBehavior
{
public:
    void fly() override
    {
        cout << "I'm flying with wings!" << endl;
    }
};

class FlyGunPowder : public FlyBehavior
{
public:
    void fly() override
    {
        cout << "I'm flying with a rocket!" << endl;
    }
};

class FlyNoWay : public FlyBehavior
{
public:
    void fly() override
    {
        cout << "I can't fly." << endl;
    }
};

// Interface
class QuackBehavior
{
public:
    virtual void quack() = 0;
};

class Quack : public QuackBehavior
{
public:
    void quack() override
    {
        cout << "Quack!" << endl;
    }
};

class Squeak : public QuackBehavior
{
public:
    void quack() override
    {
        cout << "Squeak!" << endl;
    }
};

class MuteQuack : public QuackBehavior
{
public:
    void quack() override
    {
        cout << "<< Silence ... >>" << endl;
    }
};

// 4.2
class Duck
{
protected:
    FlyBehavior *flyBehavior;
    QuackBehavior *quackBehavior;

public:
    Duck(FlyBehavior *flyBehavior, QuackBehavior *quackBehavior) : flyBehavior(flyBehavior), quackBehavior(quackBehavior) {}

    virtual void display() = 0;

    void swim()
    {
        cout << "All ducks float, even decoys!" << endl;
    }

    void performFly()
    {
        flyBehavior->fly();
    }

    void performQuack()
    {
        quackBehavior->quack();
    }

//4.4
    void setFlyBehavior(FlyBehavior *fb)
    {
        this->flyBehavior = fb;
    }

    void setQuackBehavior(QuackBehavior *qb)
    {
        this->quackBehavior = qb;
    }
};

//4.3
class MallardDuck : public Duck
{
public:
    MallardDuck() : Duck(new FlyWithWings(), new Quack()) {}

    void display() override
    {
        cout << "I'm a real Mallard duck" << endl;
    }
};

//4.3
class RubberDuck : public Duck
{
public:
    RubberDuck() : Duck(new FlyNoWay(), new Squeak())
    {
    }

    void display() override
    {
        cout << "I'm a rubber duckie" << endl;
    }
};

//4.3
class DecoyDuck : public Duck
{
public:
    DecoyDuck() : Duck(new FlyNoWay(), new MuteQuack) {}

    void display() override
    {
        cout << "Ich bin keine Ente (Duck)" << endl;
    }
};

int main()
{
    Duck *mallard = new MallardDuck();
    mallard->display();
    mallard->swim();
    mallard->performFly();
    mallard->performQuack();

    cout << "-----------------------" << endl;

    Duck *rubber = new RubberDuck();
    rubber->display();
    rubber->swim();
    rubber->performFly();
    rubber->performQuack();
    rubber->setFlyBehavior(new FlyGunPowder());
    rubber->performFly();

    cout << "-----------------------" << endl;

    Duck *decoy = new DecoyDuck();
    decoy->display();
    decoy->swim();
    decoy->performFly();
    decoy->performQuack();
    decoy->setQuackBehavior(new Quack());
    decoy->performQuack();

    delete mallard;
    delete rubber;
    delete decoy;

    return 0;
}
