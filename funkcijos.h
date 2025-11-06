#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H

#include <vector>
#include <list>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <type_traits>
#include "studentas.h"
#include "laikmatis.h"


int random(int min, int max);
float Mediana(const std::vector<int>& pazymiai);
float Mediana(std::list<int> pazymiai);
float Vidurkis(const std::vector<int>& pazymiai);
float Vidurkis(const std::list<int>& pazymiai);
int ivestiEgzamina();
Studentas ivesk();


enum class Balas { Vidurkis, Mediana };

template <typename Container>
void strategija1_paprasta(const Container& visi, Container& kietiakiai, Container& vargsiukai, Balas pagal = Balas::Vidurkis) {
    auto kriterijus = [pagal](const Studentas& s) {
        return (pagal == Balas::Vidurkis) ? (s.rezVid >= 5.0f) : (s.rezMed >= 5.0f);
        };

    // Rankiniu budu kopijuojame studentus
    for (auto it = visi.begin(); it != visi.end(); ++it) {
        if (kriterijus(*it))
            kietiakiai.push_back(*it);
        else
            vargsiukai.push_back(*it);
    }
}

template <typename Container>
void strategija2_rankine(Container& visi, Container& kietiakiai, Container& vargsiukai, Balas pagal = Balas::Vidurkis) {
    auto kriterijus = [pagal](const Studentas& s) {
        return (pagal == Balas::Vidurkis) ? (s.rezVid >= 5.0f) : (s.rezMed >= 5.0f);
        };

    // Rankiniu budu pasaliname "vargsiukus" ir kopijuojame juos
    for (auto it = visi.begin(); it != visi.end();) {
        if (!kriterijus(*it)) {
            vargsiukai.push_back(*it);
            it = visi.erase(it);  // veikia tiek su vector, tiek su list
        }
        else {
            ++it;
        }
    }

    // Po trynimo „visi“ liko tik kietiakiai
    kietiakiai = visi;
}


template <typename Container>
void strategija1(const Container& visi, Container& kietiakiai, Container& vargsiukai, Balas pagal = Balas::Vidurkis) {
    auto kriterijus = [pagal](const Studentas& s) {
        return (pagal == Balas::Vidurkis) ? (s.rezVid >= 5.0f) : (s.rezMed >= 5.0f);
        };

    std::copy_if(visi.begin(), visi.end(), std::back_inserter(kietiakiai), kriterijus);
    std::copy_if(visi.begin(), visi.end(), std::back_inserter(vargsiukai),
        [pagal](const Studentas& s) {
            return !((pagal == Balas::Vidurkis) ? (s.rezVid >= 5.0f) : (s.rezMed >= 5.0f));
        });
}


template <typename Container>
void strategija2(Container& visi, Container& kietiakiai, Container& vargsiukai, Balas pagal = Balas::Vidurkis) {
    auto kriterijus = [pagal](const Studentas& s) {
        return (pagal == Balas::Vidurkis) ? (s.rezVid >= 5.0f) : (s.rezMed >= 5.0f);
        };

    // Naudojame STL algoritmą partition visiems konteineriams
    auto it = std::partition(visi.begin(), visi.end(), kriterijus);

    kietiakiai.assign(visi.begin(), it);
    vargsiukai.assign(it, visi.end());
    visi = kietiakiai;
}

template <typename Container>
void strategija3(Container& visi, Container& kietiakiai, Container& vargsiukai, Balas pagal, int& pasirinktaTikra) {
    bool yraVector = std::is_same_v<Container, std::vector<Studentas>>;

    if (yraVector) {
        // --- VECTOR: lyginame rankines, tada taikome STL ---
        Container k1, v1, k2, v2;
        Container visiKopija = visi;

        std::cout << "Testuojamos rankines strategijos (vektoriui):\n";

        // 1 strategija (rankine)
        Laikmatis t1;
        strategija1_paprasta(visi, k1, v1, pagal);
        double laikas1 = t1.praejes_laikas();

        // 2 strategija (rankine)
        Laikmatis t2;
        strategija2_rankine(visiKopija, k2, v2, pagal);
        double laikas2 = t2.praejes_laikas();

        std::cout << "Strategija 1 (rankine) laikas: " << laikas1 << " s\n";
        std::cout << "Strategija 2 (rankine) laikas: " << laikas2 << " s\n";

        // Pasirenkame greitesne rankine
        int greitesne = (laikas1 <= laikas2) ? 1 : 2;
        pasirinktaTikra = greitesne;

        std::cout << "Pasirinkta greitesne rankine strategija: " << greitesne << "\n";

        // 2. Paleidziame atitinkama STL versija
        Laikmatis tSTL;
        if (greitesne == 1) {
            std::cout << "Vykdoma STL strategija 1 \n";
            strategija1(visi, kietiakiai, vargsiukai, pagal);
        }
        else {
            std::cout << "Vykdoma STL strategija 2 \n";
            strategija2(visi, kietiakiai, vargsiukai, pagal);
        }

        double laikasSTL = tSTL.praejes_laikas();
    }
    else {
        // --- LIST ar kitas konteineris: tik rankines ---
        Container k1, v1, k2, v2;
        Container visiKopija = visi;

        std::cout << "Testuojamos rankines strategijos (list/kitam konteineriui):\n";

        Laikmatis t1;
        strategija1_paprasta(visi, k1, v1, pagal);
        double laikas1 = t1.praejes_laikas();

        Laikmatis t2;
        strategija2_rankine(visiKopija, k2, v2, pagal);
        double laikas2 = t2.praejes_laikas();

        std::cout << "Strategija 1 (rankine) laikas: " << laikas1 << " s\n";
        std::cout << "Strategija 2 (rankine) laikas: " << laikas2 << " s\n";

        if (laikas1 <= laikas2) {
            std::cout << "Pasirinkta greitesne: STRATEGIJA 1 (rankine)\n";
            kietiakiai = std::move(k1);
            vargsiukai = std::move(v1);
            pasirinktaTikra = 1;
        }
        else {
            std::cout << "Pasirinkta greitesne: STRATEGIJA 2 (rankine)\n";
            kietiakiai = std::move(k2);
            vargsiukai = std::move(v2);
            pasirinktaTikra = 2;
        }

        std::cout << "Automatinis rezimas list'ui STL netaikytas.\n";
    }
}




// ======================================
// Atminties skaiciavimas
// ======================================
template <typename Container>
size_t skaiciuotiAtminti(const Container& konteineris) {
    bool arList = std::is_same_v<Container, std::list<Studentas>>;
    size_t dydis = sizeof(Studentas);
    if (arList) dydis += 2 * sizeof(void*); // list turi papildomus rodyklius
    return konteineris.size() * dydis;
}

// ======================================
// ISvedimas i failus
// ======================================
// ======================================
// ISvedimas i failus (surusiuota pagal balus nuo maziausio iki didziausio)
// ======================================
template <typename Container>
void irasytiIFailus(const Container& kietiakiai,
    const Container& vargsiukai,
    Balas pagal)
{
    // Sukuriame kopijas, kad gal?tume rikiuoti
    Container kietiakiaiR = kietiakiai;
    Container vargsiukaiR = vargsiukai;

    auto rikiuotiPagalBalus = [pagal](auto& sarasas) {
        if constexpr (std::is_same_v<std::decay_t<decltype(sarasas)>, std::vector<Studentas>>) {
            std::sort(sarasas.begin(), sarasas.end(), [&](const Studentas& a, const Studentas& b) {
                float ga = (pagal == Balas::Vidurkis) ? a.rezVid : a.rezMed;
                float gb = (pagal == Balas::Vidurkis) ? b.rezVid : b.rezMed;
                return ga < gb;  // nuo maziausio iki didziausio
                });
        }
        else if constexpr (std::is_same_v<std::decay_t<decltype(sarasas)>, std::list<Studentas>>) {
            sarasas.sort([&](const Studentas& a, const Studentas& b) {
                float ga = (pagal == Balas::Vidurkis) ? a.rezVid : a.rezMed;
                float gb = (pagal == Balas::Vidurkis) ? b.rezVid : b.rezMed;
                return ga < gb;
                });
        }
        };

    // Rusiuojam abu sarasus
    rikiuotiPagalBalus(kietiakiaiR);
    rikiuotiPagalBalus(vargsiukaiR);

    std::ofstream outK("kietiakiai.txt");
    std::ofstream outV("vargsiukai.txt");

    if (!outK || !outV) {
        std::cerr << "Klaida: nepavyko atidaryti i?vedimo fail?.\n";
        return;
    }

    for (const auto& s : kietiakiaiR) {
        outK << s.vard << " " << s.pav << " "
            << ((pagal == Balas::Vidurkis) ? s.rezVid : s.rezMed) << "\n";
    }

    for (const auto& s : vargsiukaiR) {
        outV << s.vard << " " << s.pav << " "
            << ((pagal == Balas::Vidurkis) ? s.rezVid : s.rezMed) << "\n";
    }

    outK.close();
    outV.close();
}





// ==========================================================
// Templatine funkcija spausdinimui ir rusiavimui
// ==========================================================
template <typename Container>
void spausdintiRezultatusIrRusiavima(Container& Grupe) {
    using std::cout;
    using std::endl;
    using std::left;
    using std::setw;
    using std::fixed;
    using std::setprecision;
    using std::ofstream;
    using std::string;

    if (Grupe.empty()) {
        cout << "Studentu sarasas tuscias." << endl;
        return;
    }

    // --- Rikiavimas pagal vard? kaip default ---
    auto compVard = [](const Studentas& a, const Studentas& b) { return a.vard < b.vard; };
    if constexpr (std::is_same_v<Container, std::vector<Studentas>>)
        std::sort(Grupe.begin(), Grupe.end(), compVard);
    else if constexpr (std::is_same_v<Container, std::list<Studentas>>)
        Grupe.sort(compVard);

    Laikmatis laikRusiavimui;
    double rusiavimoLaikas = laikRusiavimui.praejes_laikas();

    // --- Galutinio balo skaiciavimo pasirinkimas ---
    int pasirinkimas = 0;
    while (pasirinkimas < 1 || pasirinkimas > 3) {
        cout << "\nPasirinkite galutinio balo skaiciavimo metoda:\n";
        cout << "1 - Vidurkis\n2 - Mediana\n3 - Abu (vidurkis ir mediana)\n";
        cout << "Jusu pasirinkimas: ";
        std::cin >> pasirinkimas;
        if (pasirinkimas < 1 || pasirinkimas > 3)
            cout << "Neteisingas pasirinkimas, bandykite dar kart?.\n";
    }

    Laikmatis laikIrasymui;
    ofstream fout("rezultatai.txt");
    if (!fout) { cout << "Klaida: nepavyko sukurti rezultatu failo." << endl; return; }

    if (pasirinkimas == 1) {
        fout << left << setw(15) << "Pavarde" << setw(15) << "Vardas" << "Galutinis (Vid.)" << endl;
        fout << string(45, '-') << endl;
        for (const auto& s : Grupe)
            fout << left << setw(15) << s.pav << setw(15) << s.vard << fixed << setprecision(2) << s.rezVid << endl;
    }
    else if (pasirinkimas == 2) {
        fout << left << setw(15) << "Pavarde" << setw(15) << "Vardas" << "Galutinis (Med.)" << endl;
        fout << string(45, '-') << endl;
        for (const auto& s : Grupe)
            fout << left << setw(15) << s.pav << setw(15) << s.vard << fixed << setprecision(2) << s.rezMed << endl;
    }
    else {
        fout << left << setw(15) << "Pavarde" << setw(15) << "Vardas"
            << setw(20) << "Galutinis (Vid.)" << setw(20) << "Galutinis (Med.)" << endl;
        fout << string(70, '-') << endl;
        for (const auto& s : Grupe)
            fout << left << setw(15) << s.pav << setw(15) << s.vard
            << setw(20) << fixed << setprecision(2) << s.rezVid
            << setw(20) << fixed << setprecision(2) << s.rezMed << endl;
    }
    fout.close();

    cout << "Rezultatai issaugoti faile 'rezultatai.txt'\n";
    cout << "Rusiavimas truko: " << rusiavimoLaikas << " sek.\n";
    cout << "Isvedimas i 'rezultatai.txt' truko: " << laikIrasymui.praejes_laikas() << " sek.\n";

    // --- Strategijos pasirinkimas (privalomas) ---
    int strategija = 0;
    while (strategija < 1 || strategija > 3) {
        cout << "\nPasirinkite strategija (1, 2 arba 3, 3 - palyginti laikus): ";
        std::cin >> strategija;
        if (strategija < 1 || strategija > 3)
            cout << "Neteisingas pasirinkimas, bandykite dar karta.\n";
    }

    // --- Pagal ka skirstyti studentus ---
    int baloPasirinkimas = 0;
    while (baloPasirinkimas < 1 || baloPasirinkimas > 2) {
        cout << "Pasirinkite pagal ka skirstyti studentus:\n";
        cout << "1 - Vidurkis\n2 - Mediana\n";
        cout << "Jusu pasirinkimas: ";
        std::cin >> baloPasirinkimas;
        if (baloPasirinkimas < 1 || baloPasirinkimas > 2)
            cout << "Neteisingas pasirinkimas, bandykite dar karta.\n";
    }

    Container kietiakiai, vargsiukai;
    double laikas1 = 0, laikas2 = 0;
    Balas pagal = (baloPasirinkimas == 1) ? Balas::Vidurkis : Balas::Mediana;


    if (strategija == 1) {
        Laikmatis t;
        strategija1(Grupe, kietiakiai, vargsiukai, pagal);
        laikas1 = t.praejes_laikas();
        cout << "Strategija 1 truko: " << laikas1 << " s\n";
    }
    else if (strategija == 2) {
        Laikmatis t;
        strategija2(Grupe, kietiakiai, vargsiukai, pagal);
        laikas2 = t.praejes_laikas();
        cout << "Strategija 2 truko: " << laikas2 << " s\n";
    }
    else { // strategija 3 – palyginti laikus
        Container k1, v1, k2, v2;
        Laikmatis t1, t2;
        strategija1(Grupe, k1, v1, pagal); laikas1 = t1.praejes_laikas();
        strategija2(Grupe, k2, v2, pagal); laikas2 = t2.praejes_laikas();

        cout << "Strategija 1 truko: " << laikas1 << " s\n";
        cout << "Strategija 2 truko: " << laikas2 << " s\n";

        if (laikas1 <= laikas2) { kietiakiai = k1; vargsiukai = v1; cout << "Pasirinkta strategija 1 (greitesne)\n"; }
        else { kietiakiai = k2; vargsiukai = v2; cout << "Pasirinkta strategija 2 (greitesne)\n"; }
    }



    // --- Rikiavimas kietiakiai / vargsiukai ---
int rikiavimoPasirinkimas = 0;
while (true) {
    std::cout << "\nKaip norite, kad butu surikiuoti 'kietiakiai' ir 'vargsiukai'?\n";
    std::cout << "1 - Pagal varda\n2 - Pagal pavarde\n3 - Pagal galutini bala\n";
    std::cout << "Jusu pasirinkimas: ";
    std::cin >> rikiavimoPasirinkimas;

    if (!std::cin) { // ne skaicius
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Klaida: iveskite 1, 2 arba 3.\n";
        continue;
    }

    if (rikiavimoPasirinkimas < 1 || rikiavimoPasirinkimas > 3) {
        std::cout << "Klaida: iveskite 1, 2 arba 3.\n";
        continue;
    }

    break; // tinkamas pasirinkimas
}

    auto rikiuotiPagal = [&](Container& sarasas) {
        switch (rikiavimoPasirinkimas) {
        case 1:
            if constexpr (std::is_same_v<Container, std::vector<Studentas>>)
                std::sort(sarasas.begin(), sarasas.end(), [](const Studentas& a, const Studentas& b) { return a.vard < b.vard; });
            else if constexpr (std::is_same_v<Container, std::list<Studentas>>)
                sarasas.sort([](const Studentas& a, const Studentas& b) { return a.vard < b.vard; });
            break;
        case 2:
            if constexpr (std::is_same_v<Container, std::vector<Studentas>>)
                std::sort(sarasas.begin(), sarasas.end(), [](const Studentas& a, const Studentas& b) { return a.pav < b.pav; });
            else if constexpr (std::is_same_v<Container, std::list<Studentas>>)
                sarasas.sort([](const Studentas& a, const Studentas& b) { return a.pav < b.pav; });
            break;
        case 3:
            if constexpr (std::is_same_v<Container, std::vector<Studentas>>)
                std::sort(sarasas.begin(), sarasas.end(), [&](const Studentas& a, const Studentas& b) {
                float ga = (baloPasirinkimas == 1) ? a.rezVid : a.rezMed;
                float gb = (baloPasirinkimas == 1) ? b.rezVid : b.rezMed;
                return ga > gb;
                    });
            else if constexpr (std::is_same_v<Container, std::list<Studentas>>)
                sarasas.sort([&](const Studentas& a, const Studentas& b) {
                float ga = (baloPasirinkimas == 1) ? a.rezVid : a.rezMed;
                float gb = (baloPasirinkimas == 1) ? b.rezVid : b.rezMed;
                return ga > gb;
                    });
            break;
        default:
            cout << "Neteisingas pasirinkimas, paliekama be papildomo rikiavimo.\n";
        }
        };

    rikiuotiPagal(kietiakiai);
    rikiuotiPagal(vargsiukai);

    // --- I?vedimas ? failus ---
    Laikmatis laikIrasymui2;
    ofstream outKiet("kietiakiai.txt");
    ofstream outVarg("vargsiukai.txt");

    if (!outKiet || !outVarg) {
        cout << "Klaida: nepavyko sukurti failu." << endl;
        return;
    }

    auto spausdinti = [](ofstream& fout, const Container& sarasas, bool pagalVidurki) {
        string antraste = pagalVidurki ? "Galutinis (Vid.)" : "Galutinis (Med.)";
        fout << left << setw(15) << "Pavarde" << setw(15) << "Vardas" << antraste << endl;
        fout << string(45, '-') << endl;

        for (const auto& s : sarasas) {
            float balas = pagalVidurki ? s.rezVid : s.rezMed;
            fout << left << setw(15) << s.pav << setw(15) << s.vard << fixed << setprecision(2) << balas << endl;
        }
        };

    bool pagalVidurki = (baloPasirinkimas == 1);
    spausdinti(outKiet, kietiakiai, pagalVidurki);
    spausdinti(outVarg, vargsiukai, pagalVidurki);

    outKiet.close();
    outVarg.close();

    cout << "Studentai surusiuoti ir issaugoti:\n";
    cout << " - kietiakiai.txt: " << kietiakiai.size() << " studentu\n";
    cout << " - vargsiukai.txt: " << vargsiukai.size() << " studentu\n";
    cout << "Rusiavimas i kietiakus/vargsiukus truko: " << laikRusiavimui.praejes_laikas() << " sek.\n";
    cout << "Isvedimas i kietiakiai/vargsiukai failus truko: " << laikIrasymui2.praejes_laikas() << " sek.\n";
}




#endif // FUNKCIJOS_H
