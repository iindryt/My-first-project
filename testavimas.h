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
    std::cout << "Failas nuskaitytas per " << tNuskaitymui.praejes_laikas() << " s.\n";

    // Patikrinam, ar konteineris ne tuščias
    if (studentai.empty()) {
        std::cout << "Failas nerastas arba tuscias. Testavimas nutrauktas.\n";
        return;
    }
    //pasirenkame strategija
    int strategija;
    std::cout << "Pasirinkite skirstymo strategija:\n";
    std::cout << "1 - dvi kopijos (kietiakiai + vargsiukai)\n";
    std::cout << "2 - viena kopija su trynimu (vargsiukai, studentai = kietiakiai)\n";
    std::cout << "3 - automatinis grei?iausios strategijos pasirinkimas\n";
    std::cout << "Jusu pasirinkimas: ";
    std::cin >> strategija;

       // --- Automatinis pasirinkimas ---
   if (strategija == 3) {
       if constexpr (std::is_same_v<Container, std::vector<Studentas>>) {
           std::cout << "Pasirinkta strategija 1 (dvi kopijos) - vektoriui efektyviau.\n";
           strategija = 1;
       }
       else {
           std::cout << "Pasirinkta strategija 2 (viena kopija + trynimas) - listui efektyviau.\n";
           strategija = 2;
       }
   }


      // --- Skirstymas i kietiakius / varg?iukus ---
    Laikmatis tSkirstymui;
    Container kietiakiai, vargsiukai;

    if (strategija == 1) {
        // --- 1 strategija: dvi kopijos ---
        if constexpr (std::is_same_v<Container, std::vector<Studentas>>) {
            kietiakiai.reserve(studentai.size());
            vargsiukai.reserve(studentai.size());
        }
        for (const auto& s : studentai) {
            if (s.rezVid >= 5.0f) kietiakiai.push_back(s);
            else vargsiukai.push_back(s);
        }
    }
    else if (strategija == 2) {
        // --- 2 strategija: viena kopija su trynimu ---
        Container tmpVargsiukai;
        for (auto it = studentai.begin(); it != studentai.end(); ) {
            if (it->rezVid < 5.0f) {
                tmpVargsiukai.push_back(*it);
                it = studentai.erase(it);
            }
            else ++it;
        }
        kietiakiai = studentai;
        vargsiukai = tmpVargsiukai;
    }
    else {
        std::cout << "Neteisinga strategija. Naudojama 1 strategija.\n";
        if constexpr (std::is_same_v<Container, std::vector<Studentas>>) {
            kietiakiai.reserve(studentai.size());
            vargsiukai.reserve(studentai.size());
        }
        for (const auto& s : studentai) {
            if (s.rezVid >= 5.0f) kietiakiai.push_back(s);
            else vargsiukai.push_back(s);
        }
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
