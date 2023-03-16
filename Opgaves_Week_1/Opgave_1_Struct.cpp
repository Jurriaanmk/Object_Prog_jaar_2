#include <iostream>
using namespace std;

// Structuur voor het opslaan van een tijd
struct Tijd {
    int uren;
    int minuten;
};

// Functie om het verschil tussen twee tijden te berekenen
Tijd berekenVerschil(Tijd t1, Tijd t2) {
    Tijd verschil;

    if (t2.uren < t1.uren || (t2.uren == t1.uren && t2.minuten < t1.minuten)) {
        // Foutmelding als tweede tijdstip vóór het eerste ligt
        cerr << "Fout: het tweede tijdstip ligt vóór het eerste tijdstip." << endl;
        verschil.uren = 0;
        verschil.minuten = 0;
    } else {
        // Bereken het verschil tussen de tijden
        verschil.uren = t2.uren - t1.uren;
        if (t2.minuten < t1.minuten) {
            verschil.uren--;
            verschil.minuten = t2.minuten + 60 - t1.minuten;
        } else {
            verschil.minuten = t2.minuten - t1.minuten;
        }
    }

    return verschil;
}

int main() {
    Tijd t1, t2;

    // Eerste tijdstip invoeren
    cout << "Voer het eerste tijdstip in (uu:mm): ";
    cin >> t1.uren >> t1.minuten;

    // Tweede tijdstip invoeren
    cout << "Voer het tweede tijdstip in (uu:mm): ";
    cin >> t2.uren >> t2.minuten;

    // Verschil berekenen en weergeven
    Tijd verschil = berekenVerschil(t1, t2);
    cout << "Verschil: " << verschil.uren << " uur en " << verschil.minuten << " minuten." << endl;

    return 0;
}
