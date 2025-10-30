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
#include "funkcijos.h"

template <typename Container>
void testuotiKonteineri(const std::string& failoVardas, const std::string& pavadinimas) {
    std::cout << "\n=== Testuojamas konteineris: " << pavadinimas << " ===\n";
    Laikmatis tViso;

    // -----------------------------
    // 1. Nuskaitymas is failo
    // -----------------------------
    Laikmatis tNuskaitymui;
    Container studentai = nuskaitytiIsFailoTemplate<Container>(failoVardas, false);
    double laikasNuskaitymas = tNuskaitymui.praejes_laikas();

    if (studentai.empty()) {
        std::cout << "Failas tuscias.\n";
        return;
    }

    // -----------------------------
    // Strategijos pasirinkimas
    // -----------------------------
    int strategija = 0;
    while (strategija < 1 || strategija > 3) {
        std::cout << "Pasirinkite strategija:\n";
        std::cout << "1 - Dvi kopijos (studentai -> kietiakiai + vargsiukai)\n";
        std::cout << "2 - Viena kopija su trynimu (studentai = kietiakiai)\n";
        std::cout << "3 - Automatinis palyginimas ir greitesn?s pasirinkimas\n";
        std::cout << "Jusu pasirinkimas: ";
        std::cin >> strategija;
        if (strategija < 1 || strategija > 3)
            std::cout << "Neteisingas pasirinkimas, bandykite dar karta.\n";
    }

    // -----------------------------
    // Pasirinkimas pagal ka skirstyti
    // -----------------------------
    int baloPasirinkimas = 0;
    while (baloPasirinkimas < 1 || baloPasirinkimas > 2) {
        std::cout << "Pasirinkite pagal ka skirstyti studentus:\n";
        std::cout << "1 - Vidurkis\n2 - Mediana\n";
        std::cout << "Jusu pasirinkimas: ";
        std::cin >> baloPasirinkimas;
        if (baloPasirinkimas < 1 || baloPasirinkimas > 2)
            std::cout << "Neteisingas pasirinkimas, bandykite dar karta.\n";
    }
    Balas pasirinktasBalsas = (baloPasirinkimas == 1) ? Balas::Vidurkis : Balas::Mediana;

    Container kietiakiai, vargsiukai;
    double laikasStrategija = 0;
    int pasirinktaTikra = strategija; // faktin? strategija, bus nustatyta 3 strategijoje

    // -----------------------------
    // 2. Skirstymas i grupes
    // -----------------------------
    if (strategija == 1) {
        Laikmatis tStrategijai;
        strategija1(studentai, kietiakiai, vargsiukai, pasirinktasBalsas);
        laikasStrategija = tStrategijai.praejes_laikas();
    }
    else if (strategija == 2) {
        Laikmatis tStrategijai;
        strategija2(studentai, kietiakiai, vargsiukai, pasirinktasBalsas);
        laikasStrategija = tStrategijai.praejes_laikas();
    }
    else if (strategija == 3) {
        strategija3(studentai, kietiakiai, vargsiukai, pasirinktasBalsas, pasirinktaTikra);
        // laikasStrategija = tStrategijai.praejes_laikas();  ? neteisinga vieta
        // vietoj to matuok tik pasirinkt? strategij?:
        Laikmatis tStrategijai;
        if (pasirinktaTikra == 1)
            strategija1(studentai, kietiakiai, vargsiukai, pasirinktasBalsas);
        else
            strategija2(studentai, kietiakiai, vargsiukai, pasirinktasBalsas);
        laikasStrategija = tStrategijai.praejes_laikas();
    }


    // -----------------------------
    // 3. Atminties skai?iavimas
    // -----------------------------
    std::cout << "\n--- Atminties sunaudojimas ---\n";

    size_t atmStudentai = skaiciuotiAtminti(studentai);
    size_t atmKietiakiai = skaiciuotiAtminti(kietiakiai);
    size_t atmVargsiukai = skaiciuotiAtminti(vargsiukai);

    std::cout << " - Bendras studentu konteineris: " << atmStudentai << " baitu\n";
    std::cout << " - Kietiakiai:                   " << atmKietiakiai << " baitu\n";
    std::cout << " - Vargsiukai:                   " << atmVargsiukai << " baitu\n";

    size_t atmViso = 0;

    // -----------------------------
    // Taisyklingas bendros atminties skai?iavimas
    // -----------------------------
    if (strategija == 1 || (strategija == 3 && pasirinktaTikra == 1)) {
        // Strategija 1: studentai konteineryje lieka, kietiakiai ir vargsiukai papildomi
        atmViso = atmStudentai + atmKietiakiai + atmVargsiukai;
    }
    else if (strategija == 2 || (strategija == 3 && pasirinktaTikra == 2)) {
        // Strategija 2: studentai konteineryje jau tik kietiakiai, vargsiukai papildomai
        atmViso = atmKietiakiai + atmVargsiukai;
    }

    std::cout << " - Viso (apytiksliai):           " << atmViso << " baitu\n";

    // -----------------------------
    // 4. I?vedimas ? failus
    // -----------------------------
    Laikmatis tIrasymui;
    irasytiIFailus(kietiakiai, vargsiukai, pasirinktasBalsas);
    double laikasIrasymas = tIrasymui.praejes_laikas();

    // -----------------------------
    // 5. Spausdinimas
    // -----------------------------
    std::cout << "Failo nuskaitymas truko: " << laikasNuskaitymas << " s\n";
    if (strategija == 3)
        std::cout << "Strategijos (3 - automatinis) vykdymo laikas: " << laikasStrategija << " s\n";
    else
        std::cout << "Strategijos (" << strategija << ") vykdymo laikas: " << laikasStrategija << " s\n";

    std::cout << "Failo irasymas truko: " << laikasIrasymas << " s\n";
    std::cout << "Visas testas truko: " << tViso.praejes_laikas() << " s\n";
}

#endif // TESTAVIMAS_H
