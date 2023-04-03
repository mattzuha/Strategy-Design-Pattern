#include <iostream>
#include <string>
using namespace std;

class MilkTea
{
public:
    string name;
    string toppings;
    int sweetness_level;

    MilkTea(string s, string t, int sl) : name(s), toppings(t), sweetness_level(sl) {}

    void print()
    {
        cout << "Name: " << name << endl;
        cout << "Toppings: " << toppings << endl;
        cout << "Sweetness level: " << sweetness_level << endl;
    }
};

int main()
{
    // Dynamically allocate memory for a MilkTea object using new operator
    MilkTea *my_milktea = new MilkTea("Classic Milk Tea", "Black boba", 50);

    // Print the details of the MilkTea object
    my_milktea->print();

    // Free the dynamically allocated memory using delete operator
    delete my_milktea;

    MilkTea *more_milktea[] = {new MilkTea("Matcha Milk Tea", "White boba", 75), new MilkTea("Chocolate Milk tea", "Puddings", 100)};
    for (auto mt : more_milktea)
    {
        mt->print();
    }

    for (auto mt : more_milktea)
    {
        delete mt;
    }
    return 0;
}