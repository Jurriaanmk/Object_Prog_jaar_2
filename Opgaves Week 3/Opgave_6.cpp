#include <iostream>
#include <cmath>

class Lengte
{
    int feet;
    float inches;
    int meters;
    float centimeters;

public:
    Lengte() : feet(0), inches(0), meters(0), centimeters(0.0) {}
    Lengte(int f, float i) : feet(f), inches(i), meters(0), centimeters(0.0) { omrekenen(); }
    Lengte(int cm) : feet(0), inches(0), meters(0), centimeters(cm) { omrekenen(); }

    int naar_cm() const { return round((feet*12+inches)*2.54); }
    void omrekenen();
    Lengte operator+(const Lengte& l2) const;
    int smallest(int cm) const;
};

inline void Lengte::omrekenen()
{
    centimeters = feet * 30.48 + inches * 2.54;
    meters = centimeters / 100;
    centimeters -= meters * 100;
}

inline Lengte Lengte::operator+(const Lengte& l2) const
{
    return Lengte(feet + l2.feet, inches + l2.inches);
}

inline int Lengte::smallest(int cm) const
{
    return std::min(naar_cm(), cm);
}

class Voorwerp
{
    Lengte lengte;
    int nummer;

public:
    Voorwerp() : lengte(), nummer(-1) {}
    explicit Voorwerp(const Lengte& lengte) : lengte(lengte), nummer(-1) {}
};

int main()
{
    Lengte lengte1(5, 6);
    Lengte lengte2(2, 7);
    Lengte largest_lengte = (lengte1 + lengte2).smallest(lengte1.naar_cm());

    std::cout << "De grootste lengte is: " << largest_lengte.naar_cm() << " cm" << std::endl;

    Voorwerp voorwerp1; // object van Voorwerp met standaardwaarden
    Lengte lengte3(10); // een Lengte-object met waarde 10
    Voorwerp voorwerp2(lengte3); // object van Voorwerp met Lengte-object als parameter

    return 0;
}
