#include <iostream>
#include <cmath>

using namespace std;

class Length
{
    int feet;
    float inches;

    int meters;
    float centimeters = 0.0;

public:
    void Invoer();
    void Omrekenen();
    void Afstand(Length length);
    Length() : feet(0), inches(0) {}
    Length(int f, float i) : feet(f), inches(i)
{
    if (inches >= 12) {
        feet += static_cast<int>(inches / 12);
        inches = inches - static_cast<int>(inches / 12) * 12;
    }
}

};

void Length::Invoer()
{
    cout << "Voer Feet en inches in.";
    cin >> feet >> inches;
}

void Length::Omrekenen()
{
    meters = 0;
    centimeters = 0.0;
    centimeters = (feet * 12 + inches)*2.54;

    while (centimeters > 100)
    {
        meters++;
        centimeters -=100;
    }

    cout << "Omgerekend is dit " << meters << " meter en " << round(centimeters) <<" centimeter."<< endl;

}

void Length::Afstand(Length length)
{
    float this_inches = this->feet * 12 + this->inches;
    float other_inches = length.feet * 12 + length.inches;
    float total_inches = abs(this_inches - other_inches);

    int distance_feet = static_cast<int>(total_inches / 12);
    float distance_inches = total_inches - distance_feet * 12;

    cout << "De afstand tussen de twee lengtes is " << distance_feet << " feet en " << distance_inches << " inches." << endl;
}


int main()
{
    Length Lengte1, Lengte2;
    cout << "Lengte 1: " << endl;
    Lengte1.Invoer();
    Lengte1.Omrekenen();
    cout << "Lengte 2: " << endl;
    Lengte2.Invoer();
    Lengte2.Omrekenen();

    Lengte1.Afstand(Lengte2);
    
}