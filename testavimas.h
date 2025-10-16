#ifndef TESTAVIMAS_H
#define TESTAVIMAS_H

#include <iostream>
#include <vector>
#include <list>
#include <type_traits>
#include <fstream>
#include "studentas.h"
#include "duomenys.h"
#include "laikmatis.h"

// Testavimo funkcija
template <typename Container>
void testuotiKonteineri(const std::string& failoVardas, const std::string& pavadinimas) {
    std::cout << "\n=== Testuojamas konteineris: " << pavadinimas << " ===\n";

    Laikmatis tViso; // Bendras laikas

    // --- Nuskaitymas ---
    Laikmatis tNuskaitymui;
    Container studentai = nuskaitytiIsFailoTemplate<Container>(failoVardas, false); // nespauzdinti viduje

    // Patikrinam, ar konteineris ne tuščias
    if (studentai.empty()) {
        std::cout << "Failas nerastas arba tuscias. Testavimas nutrauktas.\n";
        return;
    }

    std::cout << "Failas nuskaitytas per " << tNuskaitymui.praejes_laikas() << " s.\n";

    // --- Skirstymas i kietakius / vargsiukus ---
    Laikmatis tSkirstymui;
    Container kietiakiai, vargsiukai;
    for (auto& s : studentai) {
        if (s.rezVid >= 5.0f)
            kietiakiai.push_back(s);
        else
            vargsiukai.push_back(s);
    }
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "Skirstymas truko: " << tSkirstymui.praejes_laikas() << " s.\n";

    // --- Irasymas i failus ---
    Laikmatis tFailams;
    {
        std::ofstream outKiet("kietiakiai.txt");
        if (outKiet) {
            for (auto& s : kietiakiai)
                outKiet << s.vard << " " << s.pav << " " << s.rezVid << "\n";
        }

        std::ofstream outVarg("vargsiukai.txt");
        if (outVarg) {
            for (auto& s : vargsiukai)
                outVarg << s.vard << " " << s.pav << " " << s.rezVid << "\n";
        }
    }
    std::cout << "Irasymas i failus truko: " << tFailams.praejes_laikas() << " s.\n";

    // --- Bendras laikas ---
    std::cout << "Visas testas (" << pavadinimas << ") truko: "
        << tViso.praejes_laikas() << " s.\n";
}

#endif // TESTAVIMAS_H
