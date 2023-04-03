#include <iostream>

using namespace std;

class WeaponBehavior
{
public:
    virtual void useWeapon() {}
};

class SwordBehavior : public WeaponBehavior
{
public:
    void useWeapon() override
    {
        cout << "I'm swinging with a sword" << endl;
    };
};

class BowAndArrowBehavior : public WeaponBehavior
{
public:
    void useWeapon() override
    {
        cout << "I'm shooting with a bow and arrows" << endl;
    };
};

class KnifeBehavior : public WeaponBehavior
{
public:
    void useWeapon() override
    {
        cout << "I'm cutting with a knife" << endl;
    };
};

class AxeBehavior : public WeaponBehavior
{
public:
    void useWeapon() override
    {
        cout << "I'm chopping with a sword" << endl;
    };
};

class HandBehavior : public WeaponBehavior
{
public:
    void useWeapon() override
    {
        cout << "I'm punching with my hand" << endl;
    };
};

class Character
{
public:
    Character(WeaponBehavior *weapon) : weapon(weapon) {}

    virtual void display(){};

    void fight()
    {
        cout << "All character can fight!" << endl;
    }

    void performWeapon()
    {
        weapon->useWeapon();
    }

    void setWeapon(WeaponBehavior *w)
    {
        this->weapon = w;
    }

protected:
    WeaponBehavior *weapon;
};

class King : public Character
{
public:
    King() : Character(new SwordBehavior()) {}

    void display() override
    {
        cout << "I'm a King" << endl;
    }
};

class Queen : public Character
{
public:
    Queen() : Character(new BowAndArrowBehavior()) {}

    void display() override
    {
        cout << "I'm a Queen" << endl;
    }
};

int
main()
{
    Character *king = new King();
    king->display();
    king->performWeapon();
    king->setWeapon(new KnifeBehavior());
    king->performWeapon();

    cout << "-----------------------" << endl;

    Character *queen = new Queen();
    queen->display();
    queen->performWeapon();

    cout << "-----------------------" << endl;

    delete king;
}