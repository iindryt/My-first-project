#include "duomenys.h"
#include "funkcijos.h"
#include <fstream>
#include <sstream>
#include <iostream>

std::vector<Studentas> nuskaitytiIsFailo(const std::string& failoVardas) {
    std::vector<Studentas> studentai;
    std::ifstream in(failoVardas);

    if (!in) {
        std::cerr << "Klaida: nepavyko atidaryti failo: " << failoVardas << std::endl;
        return studentai;
    }

    std::string eilute;
    getline(in, eilute); // praleidžiame antraštę

    while (getline(in, eilute)) {
        if (eilute.empty()) continue;

        std::istringstream ss(eilute);
        std::string vard, pav;
        ss >> vard >> pav;

        Studentas s;
        s.vard = vard;
        s.pav = pav;

        std::vector<int> laikPaz;
        int paz;

        while (ss >> paz) {
            laikPaz.push_back(paz);
        }

        if (laikPaz.size() < 2) {
            std::cerr << "Klaida: per mazai pazymiu eiluteje: " << eilute << std::endl;
            continue;
        }

        s.egzas = laikPaz.back();
        laikPaz.pop_back();
        s.paz = laikPaz;

        s.rezVid = s.egzas * 0.6f + Vidurkis(s.paz) * 0.4f;
        s.rezMed = s.egzas * 0.6f + Mediana(s.paz) * 0.4f;

        studentai.push_back(s);
    }

    return studentai;
}

void generuotiFaila(int kiekis, const std::string& failoVardas, int ndKiekis) {
    std::ofstream out(failoVardas);
    if (!out) {
        std::cerr << "Nepavyko sukurti failo: " << failoVardas << std::endl;
        return;
    }

    out << "Vardas Pavarde";
    for (int i = 1; i <= ndKiekis; i++) {
        out << " ND" << i;
    }
    out << " Egzaminas\n";

    for (int i = 1; i <= kiekis; ++i) {
        out << "Vardas" << i << " Pavarde" << i;
        for (int j = 0; j < ndKiekis; ++j) {
            out << " " << random(1, 10);
        }
        out << " " << random(1, 10) << "\n";
    }
    out.close();
    std::cout << "Failas '" << failoVardas << "' sukurtas su " << kiekis << " irasu." << std::endl;
}
