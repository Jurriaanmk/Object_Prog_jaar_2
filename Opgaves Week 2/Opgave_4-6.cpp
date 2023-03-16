#include <iostream>

using namespace std;

class Tijd {
private:
    int Uren;
    int Minuten;

public:
    // constructors
    Tijd();
    Tijd(int uren, int minuten);
    Tijd(int minuten);

    // methoden
    void InvoerTijd();
    void Drukaf();
    void Berekenen(Tijd tijd_1);
    void verhoog(int minuten); // nieuwe methode om tijd te verhogen
};

Tijd::Tijd() {
    Uren = 0;
    Minuten = 0;
}

Tijd::Tijd(int uren, int minuten) {
    Uren = uren;
    Minuten = minuten;
}

Tijd::Tijd(int minuten) {
    Uren = minuten / 60;
    Minuten = minuten % 60;
}

void Tijd::InvoerTijd() {
    cout << "\r\nVoer de tijd in, eerst uren daarna minuten: ";
    cin >> Uren >> Minuten;
}

void Tijd::Drukaf() {
    cout << "\r\nTotale tijd gewerkt is: " << Uren << " uren en " << Minuten << " minuten." << endl;
}

void Tijd::Berekenen(Tijd tijd_1) {
    if (tijd_1.Uren < Uren) {
        cout << "\r\nInvoer van tijden ongeldig, de tweede tijd uren liggen voor de eerste tijd." << endl;
        return;
    }

    if ((tijd_1.Uren == Uren) && (tijd_1.Minuten < Minuten)) {
        cout << "\r\nInvoer van tijden ongeldig, de tweede tijd minuten liggen voor de eerste tijd." << endl;
        return;
    }

    if (Minuten > tijd_1.Minuten) {
        tijd_1.Uren -= 1;
        tijd_1.Minuten -= 60;
    }

    int VerschilMinuten = tijd_1.Minuten - Minuten;
    int VerschilUren = tijd_1.Uren - Uren;

    Drukaf();
}

void Tijd::verhoog(int minuten) { // klasse argument maken
    Minuten += minuten;
    Uren += Minuten / 60;
    Minuten = Minuten % 60;
}

int main() {
    // test de nieuwe methode verhoog()
    Tijd TijdStip_1{4,50};
    Tijd TijdStip_2{120};
    TijdStip_1.verhoog(90); // verhoog TijdStip_1 met 90 minuten
    TijdStip_1.Drukaf(); // druk de nieuwe tijd af
    TijdStip_2.Drukaf();

    return 0;
}
