#include <iostream>
#include <cmath>

using namespace std;

class Lengte
{
    int feet;
    float inches;
    int meters;
    float centimeters = 0.0;

public:
    void Invoer();
    void Omrekenen();
    void Afstand(Lengte Lengte);
    Lengte largest(Lengte Lengte);
    int Smallest(int cm);
    int Naar_cm();

    Lengte() : feet(0), inches(0) {}
    Lengte(int f) :feet(f), inches(0.0){}
    Lengte(int f, float i) : feet(f), inches(i)
    {
        if (inches >= 12) {
            feet += static_cast<int>(inches / 12);
            inches = inches - static_cast<int>(inches / 12) * 12;
        }
    }

    Lengte operator+(Lengte l2);
};

Lengte Lengte::operator+(Lengte l2)
{
    inches = inches + l2.inches;
    if (inches > 11) {
        feet++;
        inches-=12;
    }
    feet = feet + l2.feet;
}

void Lengte::Invoer()
{
    cout << "Voer Feet en inches in.";
    cin >> feet >> inches;
}

void Lengte::Omrekenen()
{
    meters = 0;
    centimeters = 0.0;
    centimeters = (feet * 12 + inches) * 2.54;

    while (centimeters > 100)
    {
        meters++;
        centimeters -= 100;
    }

    cout << "Omgerekend is dit " << meters << " meter en " << round(centimeters) <<" centimeter." << endl;
}

void Lengte::Afstand(Lengte Lengte)
{
    float this_inches = this->feet * 12 + this->inches;
    float other_inches = Lengte.feet * 12 + Lengte.inches;
    float total_inches = abs(this_inches - other_inches);

    int distance_feet = static_cast<int>(total_inches / 12);
    float distance_inches = total_inches - distance_feet * 12;

    cout << "De afstand tussen de twee lengtes is " << distance_feet << " feet en " << distance_inches << " inches." << endl;
}

Lengte Lengte::largest(Lengte Lengte)
{
    float this_inches = this->feet * 12 + this->inches;
    float other_inches = Lengte.feet * 12 + Lengte.inches;
    if (this_inches >= other_inches) {
        return *this;
    } else {
        return Lengte;
    }
}

int Lengte::Naar_cm()
{
    float Object_cm = ((feet*12)+inches) * 2.54;
    return round(Object_cm);
}

int Lengte::Smallest(int cm)
{
    if ( Naar_cm() > cm) {
        return cm;
    } else {
        return Naar_cm();
    }
}

class Voorwerp
{
    Lengte lengte;
    int nummer;

public:
    Voorwerp() : lengte(), nummer(-1) {}
    Voorwerp(Lengte lengte) : lengte(lengte), nummer(-1) {}
};

int main()
{
    Lengte Lengte1(5, 6);
    Lengte Lengte2(2, 7);
    Lengte largest_Lengte = Lengte1.largest(Lengte2);
    Lengte smallest_Lengte;  
    if (largest_Lengte.Naar_cm() == Lengte1.Naar_cm()) {
        smallest_Lengte = Lengte2;
    } else {
        smallest_Lengte = Lengte1;
    }

    cout << "De grootste lengte is: ";
    largest_Lengte.Omrekenen();

    cout << "De kleinste lengte is: ";
    smallest_Lengte.Omrekenen();

    // Set grootste gelijk aan kleinste
    largest_Lengte = smallest_Lengte;

    cout << "De grootste lengte is nu gelijk aan de kleinste: ";
    largest_Lengte.Omrekenen();

    Voorwerp voorwerp1; // object van Voorwerp met standaardwaarden
    Lengte lengte1(10); // een Lengte-object met waarde 10
    Voorwerp voorwerp2(lengte1); // object van Voorwerp met Lengte-object als parameter

    return 0;
}
