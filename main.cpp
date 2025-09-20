#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::fixed;
using std::setprecision;
using std::left;
using std::setw;

struct Studentas {
    string vard;
    string pav;
    vector<int> paz;
    int egzas;
    float rezVid;
    float rezMed;
};
float Mediana(vector<int> &pazymiai) {
    sort(pazymiai.begin(), pazymiai.end());  
    size_t n = pazymiai.size();
    if (n == 0) return 0;
    if (n % 2 == 1) {
        return pazymiai[n / 2];
    } else {
        return (pazymiai[n/2 - 1] + pazymiai[n/2]) / 2.0;
    }
}
Studentas ivesk() {
    Studentas Laik;
    int sum = 0, m, pazymiuSkaicius = 0;

    cout << "Iveskite varda (arba 0 jei norite baigti): ";
    cin >> Laik.vard;
    if (Laik.vard == "0") return Laik;

    cout << "Iveskite pavarde: ";
    cin >> Laik.pav;

    cout << "Iveskite namu darbu pazymius po viena. Norint baigti, iveskite ne skaiciu (pvz., raide)." << endl;

    while (true) {
        cout << "Iveskite namu darba nr. " << pazymiuSkaicius + 1 << ": ";
        if (!(cin >> m)) { // Jeigu ivedama ne skaicius, baigiam
            cin.clear(); // istrinam klaidos busena
            string neSkaicius;
            cin >> neSkaicius; // nuskaityti tai, kas ivesta (pvz raide)
            break;
        }
        if (m < 0 || m > 10) {
            cout << "Klaida: pazymys turi buti tarp 0 ir 10." << endl;
            continue;
        }
        Laik.paz.push_back(m);
        sum += m;
        pazymiuSkaicius++;
    }

    if (pazymiuSkaicius == 0) {
        cout << "Nepavyko ivesti nei vieno pazymio." << endl;
        return Laik;
    }
    cout << "Iveskite egzamina: ";
    cin >> Laik.egzas;
    float vidurkis = (float)sum / pazymiuSkaicius;
    float mediana = Mediana(Laik.paz);

    Laik.rezVid = Laik.egzas * 0.6 + vidurkis * 0.4;
    Laik.rezMed = Laik.egzas * 0.6 + mediana * 0.4;
    return Laik;
}

int main() {
    vector<Studentas> Grupe;

    while (true) {
        Studentas s = ivesk();
        if (s.vard == "0") break;
        // Jeigu pazymiu skaicius buvo 0, s.paz bus tuscias, o vardas ne "0",
        // tad reiktu patikrinti ir toki atveja, kad neprideti klaidingu duomenu
        if (s.paz.size() == 0) {
            cout << "Studentas neivestas del netinkamu pazymiu." << endl;
            continue;
        }
        Grupe.push_back(s);
    }

    if (Grupe.empty()) {
        cout << "Studentu sarasas tuscias." << endl;
        return 0;
    }

    int pasirinkimas;
    
    
    cout << "\nPasirinkite galutinio balo skaiciavimo metoda:" << endl;
    cout << "1 - Vidurkis" << endl;
    cout << "2 - Mediana" << endl;
    cout << "3 - Abu" << endl;

    cin>>pasirinkimas;


    cout << endl << left << setw(15) << "Pavarde"
         << setw(15) << "Vardas";

    if (pasirinkimas == 1) {
        cout << "Galutinis (Vid.)" << endl;
        cout << "----------------------------------------------" << endl;
        for (int i = 0; i < Grupe.size(); i++) {
        cout << left << setw(15) << Grupe[i].pav
             << setw(15) << Grupe[i].vard
             << left << setw(20) << fixed << setprecision(2) << Grupe[i].rezVid << endl;
        }
    } else if (pasirinkimas == 2) {
        cout << "Galutinis (Med.)" << endl;
        cout << "----------------------------------------------" << endl;
        for (int i = 0; i < Grupe.size(); i++){
         cout << left << setw(15) << Grupe[i].pav
             << setw(15) << Grupe[i].vard
             << left << setw(20) << fixed << setprecision(2) << Grupe[i].rezMed << endl;
        }

    } else if (pasirinkimas == 3) {
        cout << "Galutinis (Vid.) / Galutinis (Med.)" << endl;
        cout << "---------------------------------------------------------" << endl;
        for (int i = 0; i < Grupe.size(); i++){
         cout << left << setw(15) << Grupe[i].pav
             << setw(15) << Grupe[i].vard
             << left << setw(20) << fixed << setprecision(2) << Grupe[i].rezVid
             << left << setw(20) << fixed << setprecision(2) << Grupe[i].rezMed << endl;
        }

    } else {
        cout << "Klaida: pasirinktas netinkamas simbolis. Iveskite 1, 2 arba 3." << endl;
    }

    return 0;
}


