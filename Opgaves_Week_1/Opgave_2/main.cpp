#include <iostream>

using namespace std;

// struct{
//     int Uren = 0;
//     int Minuten = 0;
// void InvoerTijd();
// void Drukaf();
// void Berekenen();
// };

class Tijd
{
private:
int Uren;
int Minuten;
int VerschilUren;
int VerschilMinuten;

public:
void InvoerTijd();
void Drukaf();
void Berekenen(Tijd tijd_1);


};

void Tijd::InvoerTijd()
{
    cout <<"\r\n Voer de tijd in, eerst uren daarna minuten. "<< endl;
    cin >> Uren >> Minuten;
}

void Tijd::Drukaf()
{
    cout <<"\r\n Totale tijd gewerkt is: " << Uren << " uren en " << Minuten << " minuten."<<endl;
}

void Tijd::Berekenen(Tijd tijd_1)
{
    if(tijd_1.Uren < Uren)
    {
        cout <<"\r\nInvoer van tijden ongeldig, de tweede tijd uren liggen voor de eerste tijd."<<endl;
        return;
    }

    if((tijd_1.Uren == Uren) && (tijd_1.Minuten < Minuten))
    {
        cout <<"\r\nInvoer van tijden ongeldig, de tweede tijd minuten liggen voor de eerste tijd."<<endl;
        return;
    }

    if(Minuten>tijd_1.Minuten)
    {
        tijd_1.Uren -= 1;
        tijd_1.Minuten -=60;
    }

    VerschilMinuten = tijd_1.Minuten - Minuten;
    VerschilUren = tijd_1.Uren - Uren;

    Drukaf();
}

int main()
{
    Tijd TijdStip_1, TijdStip_2;
    TijdStip_1.InvoerTijd();
    TijdStip_2.InvoerTijd();
    TijdStip_1.Berekenen(TijdStip_2);

}