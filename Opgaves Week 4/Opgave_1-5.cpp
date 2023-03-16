#include <cmath>
#include <iostream>

using namespace std;

class ClassRechthoek {
private:
    int lengte_;
    int breedte_;

public:
    ClassRechthoek()
        : lengte_(0)
        , breedte_(0)
    {
    }

    ClassRechthoek(int lengte, int breedte)
        : lengte_(lengte)
        , breedte_(breedte)
    {
        if (lengte > breedte) {
            lengte_ = lengte;
            breedte_ = breedte;
        } else {
            lengte_ = breedte;
            breedte_ = lengte;
        }
    }

    int get_lengte() const { return lengte_; }

    void set_lengte(int lengte) { lengte_ = lengte; }

    int get_breedte() const { return breedte_; }

    void set_breedte(int breedte) { breedte_ = breedte; }

    int oppervlakte() const { return lengte_ * breedte_; }

    void viervoud()
    {
        breedte_ *= 2;
        lengte_ *= 2;
    }

    ClassRechthoek omvattend(const ClassRechthoek& andere_rechthoek) const
    {
        int min_lengte = std::min(lengte_, andere_rechthoek.lengte_);
        int min_breedte = std::min(breedte_, andere_rechthoek.breedte_);
        int nieuwe_lengte = lengte_ + andere_rechthoek.lengte_ - min_lengte;
        int nieuwe_breedte = breedte_ + andere_rechthoek.breedte_ - min_breedte;

        return ClassRechthoek(nieuwe_lengte, nieuwe_breedte);
    }
};

int main()
{
    // Maak een object aan met lengte 5 en breedte 3
    ClassRechthoek rechthoek(5, 3);

    // Test de getter- en setter-methoden
    cout << "Lengte: " << rechthoek.get_lengte() << endl;
    cout << "Breedte: " << rechthoek.get_breedte() << endl;
    rechthoek.set_lengte(8);
    rechthoek.set_breedte(4);
    cout << "Lengte: " << rechthoek.get_lengte() << endl;
    cout << "Breedte: " << rechthoek.get_breedte() << endl;

    // Test de oppervlakte-methode
    cout << "Oppervlakte: " << rechthoek.oppervlakte() << endl;

    // Test de viervoud-methode
    rechthoek.viervoud();
    cout << "Lengte na viervoud: " << rechthoek.get_lengte() << endl;
    cout << "Breedte na viervoud: " << rechthoek.get_breedte() << endl;

    // Maak een tweede object aan met lengte 4 en breedte 6
    ClassRechthoek andere_rechthoek(4, 6);

    // Test de omvattend-methode
    ClassRechthoek omvattend_rechthoek = rechthoek.omvattend(andere_rechthoek);
    cout << "Lengte omvattend: " << omvattend_rechthoek.get_lengte() << endl;
    cout << "Breedte omvattend: " << omvattend_rechthoek.get_breedte() << endl;

    return 0;
}
