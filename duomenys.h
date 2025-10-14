#ifndef DUOMENYS_H
#define DUOMENYS_H

#include <string>
#include <vector>
#include "studentas.h"

std::vector<Studentas> nuskaitytiIsFailo(const std::string& failoVardas);
void generuotiFaila(int kiekis, const std::string& failoVardas, int ndKiekis = 5);

//Sablonine funkcija
template <typename Container>
Container nuskaitytiIsFailoTemplate(const std::string& failoVardas) {
    Laikmatis laikmatis;
    Container studentai;
    std::ifstream in(failoVardas);
    if (!in) {
        std::cerr << "Klaida: nepavyko atidaryti failo.\n";
        return studentai;
    }

    std::string eilute;
    getline(in, eilute); // antra?t?

    while (getline(in, eilute)) {
        if (eilute.empty()) continue;
        std::istringstream ss(eilute);

        Studentas s;
        ss >> s.vard >> s.pav;
        int paz;
        while (ss >> paz) s.paz.push_back(paz);

        if (s.paz.size() < 2) continue;
        s.egzas = s.paz.back();
        s.paz.pop_back();
        s.rezVid = s.egzas * 0.6 + Vidurkis(s.paz) * 0.4;
        s.rezMed = s.egzas * 0.6 + Mediana(s.paz) * 0.4;
        studentai.push_back(s);
    }

    std::cout << "Failas nuskaitytas per " << laikmatis.praejes_laikas() << " s.\n";
    return studentai;
}

#endif // DUOMENYS_H



