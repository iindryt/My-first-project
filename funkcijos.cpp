#include "funkcijos.h"
#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

// ==========================================================
// Random skaicius
// ==========================================================
int random(int min, int max) {
    return min + rand() % (max - min + 1);
}

// ==========================================================
// Mediana
// ==========================================================
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

    pazymiai.sort(); // vidin? list r??iavimo funkcija

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


// ==========================================================
// Vidurkis
// ==========================================================
float Vidurkis(const vector<int>& pazymiai) {
    if (pazymiai.empty()) return 0.0f;
    int suma = 0;
    for (int paz : pazymiai) {
        suma += paz;
    }
    return static_cast<float>(suma) / pazymiai.size();
}
// Vidurkis su std::list<int>
float Vidurkis(const std::list<int>& pazymiai) {
    if (pazymiai.empty()) return 0.0f;
    int suma = 0;
    for (int paz : pazymiai) {
        suma += paz;
    }
    return static_cast<float>(suma) / pazymiai.size();
}


// ==========================================================
// Ivesti egzamina
// ==========================================================
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

// ==========================================================
// Ivesti student?
// ==========================================================
Studentas ivesk() {
    Studentas Laik;
    int m, pazymiuSkaicius = 0;

    std::cout << "Iveskite varda (arba 0 jei norite baigti): ";
    std::cin >> Laik.vard;
    if (Laik.vard == "0") return Laik;

    std::cout << "Iveskite pavarde: ";
    std::cin >> Laik.pav;

    char pasirinkimas;
    // ?vesties validacija nam? darb? generavimui
    do {
        std::cout << "Ar norite generuoti atsitiktinius namu darbu pazymius? (t/n): ";
        std::cin >> pasirinkimas;
        if (pasirinkimas != 't' && pasirinkimas != 'T' &&
            pasirinkimas != 'n' && pasirinkimas != 'N') {
            std::cout << "Klaida: netinkamas pasirinkimas. Bandykite dar karta (iveskite 't' arba 'n')." << std::endl;
        }
    } while (pasirinkimas != 't' && pasirinkimas != 'T' &&
        pasirinkimas != 'n' && pasirinkimas != 'N');

    if (pasirinkimas == 't' || pasirinkimas == 'T') {
        while (true) {
            std::cout << "Iveskite kiek namu darbu generuoti (1-20): ";
            if (!(std::cin >> pazymiuSkaicius)) {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                std::cout << "Klaida: iveskite skaiciu nuo 1 iki 20." << std::endl;
                continue;
            }
            if (pazymiuSkaicius < 1 || pazymiuSkaicius > 20) {
                std::cout << "Klaida: iveskite skaiciu nuo 1 iki 20." << std::endl;
                continue;
            }
            break; // tinkamas skaicius
        }

        for (int i = 0; i < pazymiuSkaicius; i++) {
            m = random(1, 10);
            std::cout << "Sugeneruoto namu darbo nr. " << i + 1 << " pazymys: " << m << std::endl;
            Laik.paz.push_back(m);
        }
    }
    else { // vartotojas ives namu darbus rankiniu budu
        std::cout << "Iveskite namu darbu pazymius po viena. Norint baigti, iveskite ne skaiciu (pvz., raide)." << std::endl;
        while (true) {
            std::cout << "Iveskite namu darba nr. " << pazymiuSkaicius + 1 << ": ";
            if (!(std::cin >> m)) {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                break;
            }
            if (m < 1 || m > 10) {
                std::cout << "Klaida: pazymys turi buti tarp 1 ir 10." << std::endl;
                continue;
            }
            Laik.paz.push_back(m);
            pazymiuSkaicius++;
        }

        if (pazymiuSkaicius == 0) {
            std::cout << "Nepavyko ivesti nei vieno pazymio." << std::endl;
            return Laik;
        }
    }

    char genEgz;
    // ?vesties validacija egzamino generavimui
    do {
        std::cout << "Ar norite generuoti egzamino pazymi? (t/n): ";
        std::cin >> genEgz;
        if (genEgz != 't' && genEgz != 'T' && genEgz != 'n' && genEgz != 'N') {
            std::cout << "Klaida: netinkamas pasirinkimas. Bandykite dar karta (iveskite 't' arba 'n')." << std::endl;
        }
    } while (genEgz != 't' && genEgz != 'T' && genEgz != 'n' && genEgz != 'N');

    if (genEgz == 't' || genEgz == 'T') {
        Laik.egzas = random(1, 10);
        std::cout << "Sugeneruotas egzamino pazymys: " << Laik.egzas << std::endl;
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
