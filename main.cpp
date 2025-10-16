#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <ctime>
#include <string>
#include <fstream>

#include "studentas.h"
#include "funkcijos.h"
#include "duomenys.h"
#include "testavimas.h"

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

        // --- Rankinis studento ivedimas ---
        if (veiksmas == 1) {
            char tipas;
            std::cout << "Naudoti konteinerį: vector (v) ar list (l)? ";
            std::cin >> tipas;
            bool naudotiVector = (tipas == 'v');

            Studentas s = ivesk();
            if (s.vard == "0") {
                std::cout << "Studentu ivedimas nutrauktas." << std::endl;
            }
            else if (s.paz.empty()) {
                std::cout << "Studentas neivestas del netinkamu pazymiu." << std::endl;
            }
            else {
                if (naudotiVector) {
                    GrupeVector.push_back(s);
                    const Studentas& ref = GrupeVector.back();
                    std::cout << "Studento obj. saugomas adresu " << &ref << " (vector)" << std::endl;
                }
                else {
                    GrupeList.push_back(s);
                    const Studentas& ref = GrupeList.back();
                    std::cout << "Studento obj. saugomas adresu " << &ref << " (list)" << std::endl;
                }
            }
        }

        // --- Nuskaitymas is failo ---
        else if (veiksmas == 2) {
            std::string failas;
            std::cout << "Iveskite failo pavadinima: ";
            std::cin >> failas;

            char tipas;
            std::cout << "Naudoti konteineri: vector (v) ar list (l)? ";
            std::cin >> tipas;

            if (tipas == 'v') {
                auto isFailo = nuskaitytiIsFailoTemplate<std::vector<Studentas>>(failas);
                GrupeVector.insert(GrupeVector.end(), isFailo.begin(), isFailo.end());
                std::cout << "Is failo nuskaityta " << isFailo.size() << " studentu (vector)\n";
            }
            else if (tipas == 'l') {
                auto isFailo = nuskaitytiIsFailoTemplate<std::list<Studentas>>(failas);
                GrupeList.insert(GrupeList.end(), isFailo.begin(), isFailo.end());
                std::cout << "Is failo nuskaityta " << isFailo.size() << " studentu (list)\n";
            }
            else {
                std::cout << "Neteisingas pasirinkimas. Nuskaitymas nutrauktas.\n";
            }
        }

        // --- Rodyti rezultatus ---
        else if (veiksmas == 3) {
            if (!GrupeVector.empty()) {
                spausdintiRezultatusIrRusiavima(GrupeVector);
            }
            else if (!GrupeList.empty()) {
                std::vector<Studentas> laikinas(GrupeList.begin(), GrupeList.end());
                spausdintiRezultatusIrRusiavima(laikinas);
            }
            else {
                std::cout << "Nera duomenu rodyti." << std::endl;
            }
        }

        // --- Baigti programa ---
        else if (veiksmas == 4) {
            std::cout << "Programa baigiama." << std::endl;
            break;
        }

        // --- Generuoti failus ---
        else if (veiksmas == 5) {
            std::cout << "\nGeneruojami failai su studentais...\n";
            generuotiFaila(1000, "studentai_1000.txt");
            generuotiFaila(10000, "studentai_10000.txt");
            generuotiFaila(100000, "studentai_100000.txt");
            generuotiFaila(1000000, "studentai_1000000.txt");
            generuotiFaila(10000000, "studentai_10000000.txt");
            std::cout << "Failu generavimas baigtas.\n";
        }

        // --- Testavimas rankiniu budu ---
        else if (veiksmas == 6) {
            std::string testFailas;
            std::cout << "Iveskite failo pavadinima konteineriu testavimui: ";
            std::cin >> testFailas;

            testuotiKonteineri<std::vector<Studentas>>(testFailas, "std::vector");
            testuotiKonteineri<std::list<Studentas>>(testFailas, "std::list");
        }

        // --- Automatinis testavimas su visais failais ---
        else if (veiksmas == 7) {
            std::vector<std::string> failai = {
                "studentai_1000.txt",
                "studentai_10000.txt",
                "studentai_100000.txt",
                "studentai_1000000.txt",
                "studentai_10000000.txt"
            };

            std::ofstream out("test_rez.txt");
            if (!out.is_open()) {
                std::cerr << "Klaida: nepavyko sukurti test_rez.txt failo!\n";
                continue;
            }

            out << "AUTOMATINIS KONTEINERIU TESTAVIMAS\n";
            out << "-----------------------------------\n\n";

            for (const auto& failas : failai) {
                out << "Failas: " << failas << "\n";

                // Laikinai peradresuojame cout į failą
                std::streambuf* originalCout = std::cout.rdbuf();
                std::cout.rdbuf(out.rdbuf());

                testuotiKonteineri<std::vector<Studentas>>(failas, "std::vector");
                testuotiKonteineri<std::list<Studentas>>(failas, "std::list");

                std::cout.rdbuf(originalCout); // atstatome cout

                out << "-------------------------------------------\n\n";
                std::cout << "Atliktas testas su failu: " << failas << std::endl;
            }

            out.close();
            std::cout << "Automatinis testavimas baigtas. Rezultatai issaugoti faile test_rez.txt.\n";
        }

        else {
            std::cout << "Klaidingas pasirinkimas, bandykite dar karta." << std::endl;
        }
    }

    return 0;
}
