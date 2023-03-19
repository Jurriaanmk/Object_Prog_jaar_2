#include <cmath>
#include <iostream>

using namespace std;

class Length {
    int feet;
    float inches;

    int meters;
    float centimeters = 0.0;

public:
    void Invoer();
    void Omrekenen();
    void Afstand(Length length);
    Length largest(Length length);
    int Smallest(int cm);
    int Naar_cm();
    Length operator+(Length l2);
    Length()
        : feet(0)
        , inches(0)
    {
    }
    Length(int f, float i)
        : feet(f)
        , inches(i)
    {
        if (inches >= 12) {
            feet += static_cast<int>(inches / 12);
            inches = inches - static_cast<int>(inches / 12) * 12;
        }
    }
};

Length Length::operator+(Length l2) // van rechts naar links, maar een object van de klasse Length genaamd l2 aan, deze
                                    // wordt in de klasse Length opgehaald
{
    Length resultaat(feet + l2.feet, inches + l2.inches);
    if (resultaat.inches >= 12) {
        resultaat.feet++;
        resultaat.inches -= 12;
    }
    return resultaat;
}

void Length::Invoer()
{
    cout << "Voer Feet en inches in.";
    cin >> feet >> inches;
}

void Length::Omrekenen()
{
    meters = 0;
    centimeters = 0.0;
    centimeters = (feet * 12 + inches) * 2.54;

    while (centimeters > 100) {
        meters++;
        centimeters -= 100;
    }

    cout << "Omgerekend is dit " << meters << " meter en " << round(centimeters) << " centimeter." << endl;
}

void Length::Afstand(Length length)
{
    float this_inches = this->feet * 12 + this->inches;
    float other_inches = length.feet * 12 + length.inches;
    float total_inches = abs(this_inches - other_inches);

    int distance_feet = static_cast<int>(total_inches / 12);
    float distance_inches = total_inches - distance_feet * 12;

    cout << "De afstand tussen de twee lengtes is " << distance_feet << " feet en " << distance_inches << " inches."
         << endl;
}

Length Length::largest(Length length)
{
    float this_inches = this->feet * 12 + this->inches;
    float other_inches = length.feet * 12 + length.inches;
    if (this_inches >= other_inches) {
        return *this;
    } else {
        return length;
    }
}
int Length::Naar_cm()
{
    float Object_cm = ((feet * 12) + inches) * 2.54;
    return round(Object_cm);
}

int Length::Smallest(int cm)
{
    if (Naar_cm() > cm) {
        return cm;
    } else {
        return Naar_cm();
    }
}

class Voorwerp {
    Length lengte;
    int nummer;

public:
    Voorwerp(): lengte() , nummer(-1)
    {
    }
    Voorwerp(const Length& lengte): lengte(lengte) , nummer(-1)
    {
    }
};

int main()
{
    Length length1(5, 6);
    Length length2(2, 7);
    Length largest_length = length1.largest(length2);
    Length smallest_length;
    if (largest_length.Naar_cm() == length1.Naar_cm()) {
        smallest_length = length2;
    } else {
        smallest_length = length1;
    }

    cout << "De grootste lengte is: ";
    largest_length.Omrekenen();

    cout << "De kleinste lengte is: ";
    smallest_length.Omrekenen();

    // Set grootste gelijk aan kleinste
    largest_length = smallest_length;

    cout << "De grootste lengte is nu gelijk aan de kleinste: ";
    largest_length.Omrekenen();

    return 0;
}