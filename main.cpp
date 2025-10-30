#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <fstream>
#include <ctime>
#include <iomanip>

#include "studentas.h"
#include "funkcijos.h"
#include "duomenys.h"
#include "testavimas.h"
#include "laikmatis.h"

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    std::vector<Studentas> GrupeVector;
    std::list<Studentas> GrupeList;

    int veiksmas;

    while (true) {
        std::cout << "\nPasirinkite veiksma:\n";
        std::cout << "1 - Prideti studenta rankiniu budu\n";
        std::cout << "2 - Nuskaityti studentus is failo\n";
        std::cout << "3 - Rodyti studentu rezultatus\n";
        std::cout << "4 - Baigti programa\n";
        std::cout << "5 - Generuoti studentu failus (1k - 10mln)\n";
        std::cout << "6 - Testuoti konteinerius (vector vs list)\n";
        std::cout << "7 - Automatinis testavimas su visais failais\n";
        std::cout << "Jusu pasirinkimas yra: ";
        std::cin >> veiksmas;

        if (veiksmas == 1) {
            char tipas;
            std::cout << "Naudoti konteiner?: vector (v) ar list (l)? ";
            std::cin >> tipas;

            if (tipas != 'v' && tipas != 'l') {
                std::cerr << "Klaida: netinkamas konteinerio pasirinkimas! Turi buti 'v' arba 'l'.\n";
                continue;
            }

            Studentas s = ivesk();
            if (s.vard == "0") continue;

            if (tipas == 'v') GrupeVector.push_back(s);
            else GrupeList.push_back(s);
        }
        else if (veiksmas == 2) {
            std::string failas;
            std::cout << "Iveskite failo pavadinima: ";
            std::cin >> failas;

            char tipas;
            std::cout << "Naudoti konteineri: vector (v) ar list (l)? ";
            std::cin >> tipas;

            if (tipas != 'v' && tipas != 'l') {
                std::cerr << "Klaida: netinkamas konteinerio pasirinkimas! Turi buti 'v' arba 'l'.\n";
                continue;
            }

            if (tipas == 'v') {
                auto isFailo = nuskaitytiIsFailoTemplate<std::vector<Studentas>>(failas);
                if (isFailo.empty()) std::cout << "Tuscias failas. Nera studentu.\n";
                GrupeVector.insert(GrupeVector.end(), isFailo.begin(), isFailo.end());
            }
            else {
                auto isFailo = nuskaitytiIsFailoTemplate<std::list<Studentas>>(failas);
                if (isFailo.empty()) std::cout << "Tuscias failas. Nera studentu.\n";
                GrupeList.insert(GrupeList.end(), isFailo.begin(), isFailo.end());
            }
        }
        else if (veiksmas == 3) {
            if (!GrupeVector.empty()) {
                spausdintiRezultatusIrRusiavima(GrupeVector);
            }
            else if (!GrupeList.empty()) {
                std::vector<Studentas> laikinas(GrupeList.begin(), GrupeList.end());
                spausdintiRezultatusIrRusiavima(laikinas);
            }
            else {
                std::cout << "Tuscias sarasas. Nera studentu.\n";
            }
        }
        else if (veiksmas == 4) break;
        else if (veiksmas == 5) {
            generuotiFaila(1000, "studentai_1000.txt");
            generuotiFaila(10000, "studentai_10000.txt");
            generuotiFaila(100000, "studentai_100000.txt");
            generuotiFaila(1000000, "studentai_1000000.txt");
            generuotiFaila(10000000, "studentai_10000000.txt");
        }
        else if (veiksmas == 6) {
            std::string testFailas;
            std::cout << "Iveskite failo pavadinima: ";
            std::cin >> testFailas;

            testuotiKonteineri<std::vector<Studentas>>(testFailas, "std::vector");
            testuotiKonteineri<std::list<Studentas>>(testFailas, "std::list");
        }
        else if (veiksmas == 7) {
            std::vector<std::string> failai = {
                "studentai_1000.txt",
                "studentai_10000.txt",
                "studentai_100000.txt",
                "studentai_1000000.txt",
                "studentai_10000000.txt"
            };

            std::ofstream out("test_rez.txt");
            if (!out.is_open()) continue;

            for (auto& failas : failai) {
                std::streambuf* originalCout = std::cout.rdbuf();
                std::cout.rdbuf(out.rdbuf());

                testuotiKonteineri<std::vector<Studentas>>(failas, "std::vector");
                testuotiKonteineri<std::list<Studentas>>(failas, "std::list");

                std::cout.rdbuf(originalCout);
            }
        }
        else {
            std::cerr << "Klaida: netinkamas meniu pasirinkimas!\n";
        }
    }

    return 0;
}
