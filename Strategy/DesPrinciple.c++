#include <iostream>

using namespace std;

class Shape
{
public:
    virtual double computeArea() = 0;
};

class Rectangle : public Shape
{
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double computeArea() 
    {
        return width * height;
    }
};

class Circle : public Shape
{
private:
    double radius;

public:
    Circle(double r) : radius(r) {}
    double computeArea() 
    {
        return 3.14 * radius * radius;
    }
};

int main()
{
    // Shape *shapes[] = {new Rectangle(4, 5), new Circle(3)};
    // for (auto shape : shapes)
    // {
    //     cout << "Area: " << shape->computeArea() << endl;
    // }

    Shape *s = {new Circle(3)};                 // Program to an interface
    cout << "Area: " << s->computeArea() << endl;

    Rectangle *r = {new Rectangle(4, 5)};       // Program to an implementation
    cout << "Area: " << r->computeArea() << endl;

    return 0;
}