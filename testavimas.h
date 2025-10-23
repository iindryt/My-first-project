#ifndef TESTAVIMAS_H
#define TESTAVIMAS_H

#include <iostream>
#include <vector>
#include <list>
#include <type_traits>
#include <fstream>
#include <algorithm>
#include "studentas.h"
#include "duomenys.h"
#include "laikmatis.h"

template <typename Container>
void testuotiKonteineri(const std::string& failoVardas, const std::string& pavadinimas) {
    std::cout << "\n=== Testuojamas konteineris: " << pavadinimas << " ===\n";

    Laikmatis tViso;

    // --- Nuskaitymas ---
    Laikmatis tNuskaitymui;
    Container studentai = nuskaitytiIsFailoTemplate<Container>(failoVardas, false);
    std::cout << "Failas nuskaitytas per " << tNuskaitymui.praejes_laikas() << " s.\n";

    if (studentai.empty()) {
        std::cout << "Failas nerastas arba tuscias. Testavimas nutrauktas.\n";
        return;
    }

    int strategija;
    std::cout << "Pasirinkite skirstymo strategija:\n";
    std::cout << "1 - dvi kopijos (kietiakiai + vargsiukai)\n";
    std::cout << "2 - viena kopija su trynimu (vargsiukai, studentai = kietiakiai)\n";
    std::cout << "3 - automatinis greiciausios strategijos pasirinkimas\n";
    std::cout << "Jusu pasirinkimas: ";
    std::cin >> strategija;

    Container kietiakiai, vargsiukai;

    if (strategija == 3) {
        Container k1, v1, k2, v2;
        double laikas1 = 0.0, laikas2 = 0.0;

        // Strategija 1 (dvi kopijos)
        {
            Laikmatis t;
            if constexpr (std::is_same_v<Container, std::vector<Studentas>>) {
                k1.reserve(studentai.size());
                v1.reserve(studentai.size());
                std::copy_if(studentai.begin(), studentai.end(), std::back_inserter(k1),
                    [](const Studentas& s) { return s.rezVid >= 5.0f; });
                std::copy_if(studentai.begin(), studentai.end(), std::back_inserter(v1),
                    [](const Studentas& s) { return s.rezVid < 5.0f; });
            }
            else { // list
                for (const auto& s : studentai) {
                    if (s.rezVid >= 5.0f) k1.push_back(s);
                    else v1.push_back(s);
                }
            }
            laikas1 = t.praejes_laikas();
        }

        // Strategija 2 (viena kopija su trynimu)
        {
            Laikmatis t;
            Container tmp = studentai;
            if constexpr (std::is_same_v<Container, std::vector<Studentas>>) {
                auto it = std::partition(tmp.begin(), tmp.end(),
                    [](const Studentas& s) { return s.rezVid >= 5.0f; });
                k2.assign(tmp.begin(), it);
                v2.assign(it, tmp.end());
            }
            else { // list
                for (auto it = tmp.begin(); it != tmp.end();) {
                    if (it->rezVid < 5.0f) {
                        v2.push_back(*it);
                        it = tmp.erase(it);
                    }
                    else ++it;
                }
                k2 = tmp;
            }
            laikas2 = t.praejes_laikas();
        }

        std::cout << "Strategijos 1 skirstymas truko: " << laikas1 << " s\n";
        std::cout << "Strategijos 2 skirstymas truko: " << laikas2 << " s\n";

        if (laikas1 <= laikas2) {
            strategija = 1;
            kietiakiai = k1;
            vargsiukai = v1;
        }
        else {
            strategija = 2;
            kietiakiai = k2;
            vargsiukai = v2;
        }

        std::cout << "Pasirinkta strategija: " << strategija << "\n";
    }
    else {
        Laikmatis tSkirstymui;

        if (strategija == 1) {
            if constexpr (std::is_same_v<Container, std::vector<Studentas>>) {
                kietiakiai.reserve(studentai.size());
                vargsiukai.reserve(studentai.size());
                std::copy_if(studentai.begin(), studentai.end(), std::back_inserter(kietiakiai),
                    [](const Studentas& s) { return s.rezVid >= 5.0f; });
                std::copy_if(studentai.begin(), studentai.end(), std::back_inserter(vargsiukai),
                    [](const Studentas& s) { return s.rezVid < 5.0f; });
            }
            else {
                for (const auto& s : studentai) {
                    if (s.rezVid >= 5.0f) kietiakiai.push_back(s);
                    else vargsiukai.push_back(s);
                }
            }
        }
        else if (strategija == 2) {
            Container tmpVargsiukai;
            for (auto it = studentai.begin(); it != studentai.end();) {
                if (it->rezVid < 5.0f) {
                    tmpVargsiukai.push_back(*it);
                    it = studentai.erase(it);
                }
                else ++it;
            }
            kietiakiai = studentai;
            vargsiukai = tmpVargsiukai;
        }

        std::cout << "Skirstymas truko: " << tSkirstymui.praejes_laikas() << " s\n";
    }

    // --- Irasymas i failus ---
    Laikmatis tFailams;
    {
        std::ofstream outKiet("kietiakiai.txt");
        for (const auto& s : kietiakiai)
            outKiet << s.vard << " " << s.pav << " " << s.rezVid << "\n";

        std::ofstream outVarg("vargsiukai.txt");
        for (const auto& s : vargsiukai)
            outVarg << s.vard << " " << s.pav << " " << s.rezVid << "\n";
    }
    std::cout << "Irasymas i failus truko: " << tFailams.praejes_laikas() << " s.\n";

    // --- Atminties skaiciavimas ---
    auto skaiciuotiAtminti = [](size_t kiekis, bool yraList) {
        size_t dydis = sizeof(Studentas);
        if (yraList) dydis += 2 * sizeof(void*);
        return kiekis * dydis;
        };
    bool arList = std::is_same_v<Container, std::list<Studentas>>;

    std::cout << " - Bendras studentu konteineris: " << skaiciuotiAtminti(studentai.size(), arList) << " baitu\n";
    std::cout << " - Kietiakiai:                   " << skaiciuotiAtminti(kietiakiai.size(), arList) << " baitu\n";
    std::cout << " - Vargsiukai:                   " << skaiciuotiAtminti(vargsiukai.size(), arList) << " baitu\n";

    size_t viso = 0;
    if (strategija == 2) {
        viso = skaiciuotiAtminti(kietiakiai.size(), arList) + skaiciuotiAtminti(vargsiukai.size(), arList);
    }
    else {
        viso = skaiciuotiAtminti(studentai.size(), arList) +
            skaiciuotiAtminti(kietiakiai.size(), arList) +
            skaiciuotiAtminti(vargsiukai.size(), arList);
    }
    std::cout << " - Viso (apytiksliai):           " << viso << " baitu\n";

    std::cout << "\nVisas testas (" << pavadinimas << ") truko: " << tViso.praejes_laikas() << " s.\n";
}

#endif // TESTAVIMAS_H
