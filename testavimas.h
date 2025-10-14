#ifndef TESTAVIMAS_H
#define TESTAVIMAS_H

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <type_traits>
#include <fstream>
#include "studentas.h"
#include "duomenys.h"
#include "laikmatis.h"

template <typename Container>
void testuotiKonteineri(const std::string& failoVardas, const std::string& pavadinimas) {
    std::cout << "\n=== Testuojamas konteineris: " << pavadinimas << " ===\n";

    Laikmatis visoLaiko;
    auto studentai = nuskaitytiIsFailoTemplate<Container>(failoVardas);

    // --- Rusiavimas ---
    Laikmatis tRusiavimui;
    if constexpr (std::is_same_v<Container, std::list<Studentas>>) {
        studentai.sort([](const Studentas& a, const Studentas& b) { return a.vard < b.vard; });
    }
    else {
        std::sort(studentai.begin(), studentai.end(), [](const Studentas& a, const Studentas& b) { return a.vard < b.vard; });
    }
    std::cout << "Rusiavimas truko: " << tRusiavimui.praejes_laikas() << " s.\n";

    // --- Skirstymas i kietiakiai / vargsiukai ---
    Laikmatis tSkirstymui;
    Container kietiakiai, vargsiukai;
    for (auto& s : studentai) {
        if (s.rezVid >= 5.0f)
            kietiakiai.push_back(s);
        else
            vargsiukai.push_back(s);
    }
    std::cout << "Skirstymas truko: " << tSkirstymui.praejes_laikas() << " s.\n";

    // --- Irasymas i failus ---
    Laikmatis tFailams;
    {
        std::ofstream outKiet("kietiakiai.txt");
        if (!outKiet) std::cerr << "Klaida: nepavyko sukurti 'kietiakiai.txt'.\n";
        else {
            for (auto& s : kietiakiai)
                outKiet << s.vard << " " << s.pav << " " << s.rezVid << "\n";
            outKiet.close();
        }

        std::ofstream outVarg("vargsiukai.txt");
        if (!outVarg) std::cerr << "Klaida: nepavyko sukurti 'vargsiukai.txt'.\n";
        else {
            for (auto& s : vargsiukai)
                outVarg << s.vard << " " << s.pav << " " << s.rezVid << "\n";
            outVarg.close();
        }
    }
    std::cout << "Irasymas i failus truko: " << tFailams.praejes_laikas() << " s.\n";

    std::cout << "Visas testas (" << pavadinimas << ") truko: "
        << visoLaiko.praejes_laikas() << " s.\n";
}

#endif // TESTAVIMAS_H
