#include "funkcijos.h"
#include "studentas.h"
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::fixed;
using std::left;
using std::setw;
using std::setprecision;
using std::ofstream;

int random(int min, int max) {
    return min + rand() % (max - min + 1);
}

float Mediana(const vector<int>& pazymiai) {
    if (pazymiai.empty()) return 0.0f;
    vector<int> kopija = pazymiai;
    std::sort(kopija.begin(), kopija.end());

    size_t n = kopija.size();
    if (n % 2 == 1)
        return kopija[n / 2];
    else
        return (kopija[n / 2 - 1] + kopija[n / 2]) / 2.0f;
}
float Mediana(std::list<int> pazymiai) {
    if (pazymiai.empty()) return 0.0f;

    pazymiai.sort(); // vidinė list rūšiavimo funkcija

    size_t n = pazymiai.size();
    auto it = pazymiai.begin();
    std::advance(it, n / 2);

    if (n % 2 == 1) {
        return *it;
    }
    else {
        auto it2 = it;
        std::advance(it2, -1);
        return (*it + *it2) / 2.0f;
    }
}


float Vidurkis(const vector<int>& pazymiai) {
    if (pazymiai.empty()) return 0.0f;
    int suma = 0;
    for (int paz : pazymiai) {
        suma += paz;
    }
    return static_cast<float>(suma) / pazymiai.size();
}
float Vidurkis(const std::list<int>& pazymiai) {
    if (pazymiai.empty()) return 0.0f;
    int suma = 0;
    for (int paz : pazymiai) {
        suma += paz;
    }
    return static_cast<float>(suma) / pazymiai.size();
}

int ivestiEgzamina() {
    int egz;
    while (true) {
        cout << "Iveskite egzamino pazymi (1-10): ";
        if (!(cin >> egz)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Klaida: iveskite skaiciu nuo 1 iki 10." << endl;
            continue;
        }
        if (egz < 1 || egz > 10) {
            cout << "Egzamino pazymys turi buti tarp 1 ir 10." << endl;
            continue;
        }
        return egz;
    }
}

Studentas ivesk() {
    Studentas Laik;
    int m, pazymiuSkaicius = 0;

    cout << "Iveskite varda (arba 0 jei norite baigti): ";
    cin >> Laik.vard;
    if (Laik.vard == "0") return Laik;

    cout << "Iveskite pavarde: ";
    cin >> Laik.pav;

    char pasirinkimas;
    cout << "Ar norite generuoti atsitiktinius namu darbu pazymius? (t/n): ";
    cin >> pasirinkimas;

    if (pasirinkimas == 't' || pasirinkimas == 'T') {
        cout << "Iveskite kiek namu darbu generuoti: ";
        cin >> pazymiuSkaicius;

        for (int i = 0; i < pazymiuSkaicius; i++) {
            m = random(1, 10);
            cout << "Sugeneruoto namu darbo nr. " << i + 1 << " pazymys: " << m << endl;
            Laik.paz.push_back(m);
        }
    }
    else {
        cout << "Iveskite namu darbu pazymius po viena. Norint baigti, iveskite ne skaiciu (pvz., raide)." << endl;
        while (true) {
            cout << "Iveskite namu darba nr. " << pazymiuSkaicius + 1 << ": ";
            if (!(cin >> m)) {
                cin.clear();
                cin.ignore(1000, '\n');
                break;
            }
            if (m < 1 || m > 10) {
                cout << "Klaida: pazymys turi buti tarp 1 ir 10." << endl;
                continue;
            }
            Laik.paz.push_back(m);
            pazymiuSkaicius++;
        }

        if (pazymiuSkaicius == 0) {
            cout << "Nepavyko ivesti nei vieno pazymio." << endl;
            return Laik;
        }
    }

    char genEgz;
    cout << "Ar norite generuoti egzamino pazymi? (t/n): ";
    cin >> genEgz;

    if (genEgz == 't' || genEgz == 'T') {
        Laik.egzas = random(1, 10);
        cout << "Sugeneruotas egzamino pazymys: " << Laik.egzas << endl;
    }
    else {
        Laik.egzas = ivestiEgzamina();
    }

    float vidurkis = Vidurkis(Laik.paz);
    float mediana = Mediana(Laik.paz);

    Laik.rezVid = Laik.egzas * 0.6f + vidurkis * 0.4f;
    Laik.rezMed = Laik.egzas * 0.6f + mediana * 0.4f;

    return Laik;
}


