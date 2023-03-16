#include <iostream>

using namespace std;

class Breuk
{
private:
    int teller;
    int noemer;
public:
    void lees_in()
    {
        cout << "Geef de teller: ";
        cin >> teller;
        cout << "Geef de noemer: ";
        cin >> noemer;
    }
    void drukaf()
    {
        cout << teller << "/" << noemer << endl;
    }
    void verhoog_met(Breuk breuk)
    {
        teller = teller * breuk.noemer + breuk.teller * noemer;
        noemer = noemer * breuk.noemer;
    }
    void vereenvoudig()
    {
        int g = gcd(teller, noemer);
        teller /= g;
        noemer /= g;
    }
    int gcd(int a, int b)
    {
        if (b == 0)
        {
            return a;
        }
        return gcd(b, a % b);
    }
};
struct Tijd_Struct{
int uren = 0;
int minuten = 0;

};

int main()
{



    Breuk b1, b2;
    b1.lees_in();
    b2.lees_in();
    b1.verhoog_met(b2);
    b1.vereenvoudig();
    b1.drukaf();
    return 0;

}
