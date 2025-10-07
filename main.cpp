#include <iostream>
#include <iomanip>     
#include <vector>
#include <ctime>

#include "studentas.h"
#include "funkcijos.h"
#include "duomenys.h"  

int main() {
    std::srand(std::time(nullptr));
    std::vector<Studentas> Grupe;
    int veiksmas;

    while (true) {
        std::cout << "\nPasirinkite veiksma:\n";
        std::cout << "1 - Prideti studenta rankiniu budu\n";
        std::cout << "2 - Nuskaityti studentus is failo\n";
        std::cout << "3 - Rodyti studentu rezultatus\n";
        std::cout << "4 - Baigti programa\n";
        std::cout << "5 - Generuoti studentu failus (1k – 10mln)\n";
        std::cout << "Jusu pasirinkimas yra: ";
        std::cin >> veiksmas;

        if (veiksmas == 1) {
            Studentas s = ivesk();
            if (s.vard == "0") {
                std::cout << "Studentu ivedimas nutrauktas." << std::endl;
                continue;
            }
            if (s.paz.size() == 0) {
                std::cout << "Studentas neivestas del netinkamu pazymiu." << std::endl;
                continue;
            }
            Grupe.push_back(s);
        }
        else if (veiksmas == 2) {
            std::string failas;
            std::cout << "Iveskite failo pavadinima: ";
            std::cin >> failas;
            std::vector<Studentas> isFailo = nuskaitytiIsFailo(failas);
            Grupe.insert(Grupe.end(), isFailo.begin(), isFailo.end());
            std::cout << "Is failo yra nuskaityta " << isFailo.size() << " studentu." << std::endl;
        }
        else if (veiksmas == 3) {
            spausdintiRezultatusIrRusiavima(Grupe); // iš funkcijos.cpp
        }
        else if (veiksmas == 4) {
            std::cout << "Programa baigiama." << std::endl;
            break;
        }
        else if (veiksmas == 5) {
            std::cout << "\nGeneruojami failai su studentais...\n";
            generuotiFaila(1000, "studentai_1000.txt");
            generuotiFaila(10000, "studentai_10000.txt");
            //generuotiFaila(100000, "studentai_100000.txt");
            //generuotiFaila(1000000, "studentai_1000000.txt");
            //generuotiFaila(10000000, "studentai_10000000.txt");
            std::cout << "Failu generavimas baigtas.\n";
        }
        else {
            std::cout << "Klaidingas pasirinkimas, bandykite dar karta." << std::endl;
        }
    }

    return 0;
}

