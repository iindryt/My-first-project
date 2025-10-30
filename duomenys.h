#ifndef DUOMENYS_H
#define DUOMENYS_H

#include <string>
#include <vector>
#include <list>
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>
#include "studentas.h"
#include "laikmatis.h"
#include "funkcijos.h"


// Failo generavimas
void generuotiFaila(int kiekis, const std::string& failoVardas, int ndKiekis = 5);

// Paprasta funkcija su std::vector
std::vector<Studentas> nuskaitytiIsFailo(const std::string& failoVardas);

// ?ablonin? funkcija konteineriams (vector arba list)
template <typename Container>
Container nuskaitytiIsFailoTemplate(const std::string& failoVardas, bool spausdinti = true) {
    Laikmatis tNuskaitymui;
    Container studentai;

    std::ifstream in(failoVardas);
    if (!in) {
        std::cerr << "Nepavyko atidaryti failo: " << failoVardas << "\n";
        return studentai;
    }

    std::string eilute;
    std::getline(in, eilute); // praleid?iame antra?t?

    while (std::getline(in, eilute)) {
        if (eilute.empty()) continue;

        std::istringstream iss(eilute);
        Studentas s;
        iss >> s.vard >> s.pav;

        std::vector<int> laikiniPaz;
        int paz;

        while (iss >> paz) {
            if (paz < 1) paz = 1;
            if (paz > 10) paz = 10;
            laikiniPaz.push_back(paz);
        }

        if (!laikiniPaz.empty()) {
            s.egzas = laikiniPaz.back();
            laikiniPaz.pop_back();
        }
        else s.egzas = 1;

        s.paz = laikiniPaz;

        // Galutiniai balai
        float vid = Vidurkis(s.paz);
        float med = Mediana(s.paz);
        s.rezVid = 0.4f * vid + 0.6f * s.egzas;
        s.rezMed = 0.4f * med + 0.6f * s.egzas;

        studentai.push_back(s);
    }

    if (spausdinti) {
        std::cout << "Failas nuskaitytas per " << tNuskaitymui.praejes_laikas() << " s.\n";
    }

    return studentai;
}

#endif // DUOMENYS_H

#pragma once
