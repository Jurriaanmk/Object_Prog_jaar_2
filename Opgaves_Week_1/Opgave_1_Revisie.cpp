#include <iostream>

using namespace std;

class Breuk
{
private: 
    int teller;
    int noemer;
    void vereenvoudig();

public:
    Breuk();
    Breuk(int t, int n);
    void lees_in();
    void drukaf();
    void verhoog_met(Breuk breuk);


};

void Breuk::vereenvoudig()
{
    if (teller < 2){ return;}

    int hoogtstewaarde = 0;
    for(int i = 2; i <= teller; i++)
    {
        if ((teller%i) ==0 && (noemer%i) ==0)
            hoogtstewaarde = i;
    }

    teller = teller / hoogtstewaarde;
    noemer = noemer / hoogtstewaarde;

}

void Breuk::lees_in()
{
    cout << "Voer een Teller en noemer in, gescheiden met een spatie: ";
    cin >> teller >> noemer;
    vereenvoudig();

}

void Breuk::drukaf()
{
    cout << teller << "/" << noemer;


}
void Breuk::verhoog_met(Breuk breuk)
{
    teller = teller * breuk.noemer + breuk.teller * noemer;
    noemer = noemer * breuk.noemer;
    vereenvoudig();

}

Breuk::Breuk(int t, int n)
{
    teller = t;
    noemer = n;
    vereenvoudig();
}

Breuk::Breuk()
{
    teller = 0;
    noemer = 1;
}

int main()
{
    int i = 0;
    Breuk a{1000, 300};
    //Breuk b{3,6};
    //a.verhoog_met(b);
    //a.lees_in();
    a.drukaf();
    cout << "\r\n Succesvol klaar";
    




}