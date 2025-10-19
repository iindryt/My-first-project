#ifndef TESTAVIMAS_H
#define TESTAVIMAS_H

#include <iostream>
#include <vector>
#include <list>
#include <type_traits>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include "studentas.h"
#include "duomenys.h"
#include "laikmatis.h"

// -------------------------------------------------------------
// Optimizuotas testavimas su 3 strategijomis:
// 1 strategija — dvi kopijos (kietiakiai + vargsiukai)
// 2 strategija — viena kopija (vargsiukai), studentai = kietiakiai
// 3 strategija — automatinis greičiausios strategijos pasirinkimas
// -------------------------------------------------------------

template <typename Container>
void testuotiKonteineri(const std::string& failoVardas, const std::string& pavadinimas) {
    std::cout << "\n=== Testuojamas konteineris: " << pavadinimas << " ===\n";

    Laikmatis tViso; // Bendras laikas

    // --- Nuskaitymas ---
    Laikmatis tNuskaitymui;
    Container studentai = nuskaitytiIsFailoTemplate<Container>(failoVardas, false);
    std::cout << "Failas nuskaitytas per " << tNuskaitymui.praejes_laikas() << " s.\n";

    if (studentai.empty()) {
        std::cout << "Failas nerastas arba tuščias. Testavimas nutrauktas.\n";
        return;
    }

    // --- Pasirinkti strategiją ---
    int strategija;
    std::cout << "Pasirinkite skirstymo strategija:\n";
    std::cout << "1 - dvi kopijos (kietiakiai + vargsiukai)\n";
    std::cout << "2 - viena kopija su trynimu (vargsiukai, studentai = kietiakiai)\n";
    std::cout << "3 - automatinis greičiausios strategijos pasirinkimas\n";
    std::cout << "Jusu pasirinkimas: ";
    std::cin >> strategija;

    // --- Automatinis pasirinkimas ---
    if (strategija == 3) {
        if constexpr (std::is_same_v<Container, std::vector<Studentas>>) {
            std::cout << "Pasirinkta strategija 1 (dvi kopijos) - vektoriui efektyviau.\n";
            strategija = 1;
        } else {
            std::cout << "Pasirinkta strategija 2 (viena kopija + trynimas) - listui efektyviau.\n";
            strategija = 2;
        }
    }

    // --- Skirstymas į kietiakius / vargšiukus ---
    Laikmatis tSkirstymui;
    Container kietiakiai, vargsiukai;

    if constexpr (std::is_same_v<Container, std::vector<Studentas>>) {
        // --- Vektorius su STL algoritmais ---
        if (strategija == 1) {
            kietiakiai.reserve(studentai.size());
            vargsiukai.reserve(studentai.size());

            std::copy_if(studentai.begin(), studentai.end(), std::back_inserter(kietiakiai),
                         [](const Studentas& s){ return s.rezVid >= 5.0f; });
            std::copy_if(studentai.begin(), studentai.end(), std::back_inserter(vargsiukai),
                         [](const Studentas& s){ return s.rezVid < 5.0f; });
        }
        else if (strategija == 2) {
            auto it = std::partition(studentai.begin(), studentai.end(),
                                     [](const Studentas& s){ return s.rezVid >= 5.0f; });
            kietiakiai.assign(studentai.begin(), it);
            vargsiukai.assign(it, studentai.end());
        }
    } else {
        // --- List: klasikinis for + erase ---
        if (strategija == 1) {
            for (const auto& s : studentai) {
                if (s.rezVid >= 5.0f) kietiakiai.push_back(s);
                else vargsiukai.push_back(s);
            }
        } else if (strategija == 2) {
            for (auto it = studentai.begin(); it != studentai.end(); ) {
                if (it->rezVid < 5.0f) {
                    vargsiukai.push_back(*it);
                    it = studentai.erase(it);
                } else ++it;
            }
            kietiakiai = studentai;
        }
    }

    std::cout << std::fixed << std::setprecision(6);
    std::cout << "Skirstymas truko: " << tSkirstymui.praejes_laikas() << " s.\n";

    // --- Įrašymas į failus ---
    Laikmatis tFailams;
    {
        std::ofstream outKiet("kietiakiai.txt");
        for (const auto& s : kietiakiai) outKiet << s.vard << " " << s.pav << " " << s.rezVid << "\n";

        std::ofstream outVarg("vargsiukai.txt");
        for (const auto& s : vargsiukai) outVarg << s.vard << " " << s.pav << " " << s.rezVid << "\n";
    }
    std::cout << "Įrašymas į failus truko: " << tFailams.praejes_laikas() << " s.\n";

    // --- Atminties sąnaudos ---
    auto skaiciuotiAtminti = [](size_t kiekis, bool yraList) {
        size_t dydis = sizeof(Studentas);
        if (yraList) dydis += 2 * sizeof(void*);
        return kiekis * dydis;
    };
    bool arList = std::is_same_v<Container, std::list<Studentas>>;

    std::cout << "\nAtminties sąnaudos (apytiksliai):\n";
    std::cout << " - Bendras studentų konteineris: " << skaiciuotiAtminti(studentai.size(), arList) << " baitų\n";
    std::cout << " - Kietiakiai:                   " << skaiciuotiAtminti(kietiakiai.size(), arList) << " baitų\n";
    std::cout << " - Vargšiukai:                   " << skaiciuotiAtminti(vargsiukai.size(), arList) << " baitų\n";
    std::cout << " - Viso (apytiksliai):           " << skaiciuotiAtminti(studentai.size() + vargsiukai.size(), arList) << " baitų\n";

    std::cout << "\nVisas testas (" << pavadinimas << ") truko: " << tViso.praejes_laikas() << " s.\n";
}

#endif // TESTAVIMAS_H
