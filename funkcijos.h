#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H

#include <vector>
#include "studentas.h"

int random(int min, int max);
float Mediana(const std::vector<int>& pazymiai);
float Vidurkis(const std::vector<int>& pazymiai);
int ivestiEgzamina();
Studentas ivesk();

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

    Laikmatis laikRusiavimui;

    // --- Rusiavimas pagal varda kaip default ---
    auto compVard = [](const Studentas& a, const Studentas& b) { return a.vard < b.vard; };

    if constexpr (std::is_same_v<Container, std::vector<Studentas>>) {
        std::sort(Grupe.begin(), Grupe.end(), compVard);
    }
    else if constexpr (std::is_same_v<Container, std::list<Studentas>>) {
        Grupe.sort(compVard);
    }

    double rusiavimoLaikas = laikRusiavimui.praejes_laikas();

    // --- Pasirinkimas kaip skaiciuoti galutini bala ---
    int pasirinkimas;
    cout << "\nPasirinkite galutinio balo skaiciavimo metoda:\n";
    cout << "1 - Vidurkis\n";
    cout << "2 - Mediana\n";
    cout << "3 - Abu (vidurkis ir mediana)\n";
    cout << "Jusu pasirinkimas: ";
    std::cin >> pasirinkimas;

    Laikmatis laikIrasymui;
    ofstream fout("rezultatai.txt");
    if (!fout) {
        cout << "Klaida: nepavyko sukurti rezultatu failo." << endl;
        return;
    }

    if (pasirinkimas == 1) {
        fout << left << setw(15) << "Pavarde" << setw(15) << "Vardas" << "Galutinis (Vid.)" << endl;
        fout << "----------------------------------------------" << endl;
        for (const auto& s : Grupe) {
            fout << left << setw(15) << s.pav
                << setw(15) << s.vard
                << fixed << setprecision(2) << s.rezVid << endl;
        }
    }
    else if (pasirinkimas == 2) {
        fout << left << setw(15) << "Pavarde" << setw(15) << "Vardas" << "Galutinis (Med.)" << endl;
        fout << "----------------------------------------------" << endl;
        for (const auto& s : Grupe) {
            fout << left << setw(15) << s.pav
                << setw(15) << s.vard
                << fixed << setprecision(2) << s.rezMed << endl;
        }
    }
    else if (pasirinkimas == 3) {
        fout << left << setw(15) << "Pavarde"
            << setw(15) << "Vardas"
            << setw(20) << "Galutinis (Vid.)"
            << setw(20) << "Galutinis (Med.)" << endl;
        fout << string(70, '-') << endl;

        for (const auto& s : Grupe) {
            fout << left << setw(15) << s.pav
                << setw(15) << s.vard
                << setw(20) << fixed << setprecision(2) << s.rezVid
                << setw(20) << fixed << setprecision(2) << s.rezMed << endl;
        }
    }
    fout.close();

    cout << "Rezultatai issaugoti faile 'rezultatai.txt'\n";
    cout << "Rusiavimas truko: " << rusiavimoLaikas << " sek.\n";
    cout << "Isvedimas i 'rezultatai.txt' truko: " << laikIrasymui.praejes_laikas() << " sek.\n";

    // --- Rusiavimas i kietiakus / vargsiukus ---
    int rusiuotPasirinkimas;
    cout << "\nPagal ka norite surusiuoti studentus i dvi kategorijas (kietiakiai / vargsiukai)?\n";
    cout << "1 - Pagal galutini bala (vidurkis)\n";
    cout << "2 - Pagal galutini bala (mediana)\n";
    cout << "Jusu pasirinkimas: ";
    std::cin >> rusiuotPasirinkimas;

    Laikmatis laikRusiavimui2;

    Container kietiakiai, vargsiukai;
    for (auto& s : Grupe) {
        float galutinis = (rusiuotPasirinkimas == 1) ? s.rezVid : s.rezMed;
        if (galutinis >= 5.0f)
            kietiakiai.push_back(s);
        else
            vargsiukai.push_back(s);
    }

    // --- Pasirinkimas kaip rikiuoti ---
    int rikiavimoPasirinkimas;
    cout << "\nKaip norite, kad butu surikiuoti 'kietiakiai' ir 'vargsiukai'?\n";
    cout << "1 - Pagal varda\n";
    cout << "2 - Pagal pavarde\n";
    cout << "3 - Pagal galutini bala\n";
    cout << "Jusu pasirinkimas: ";
    std::cin >> rikiavimoPasirinkimas;

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
                float ga = (rusiuotPasirinkimas == 1) ? a.rezVid : a.rezMed;
                float gb = (rusiuotPasirinkimas == 1) ? b.rezVid : b.rezMed;
                return ga > gb;
                    });
            else if constexpr (std::is_same_v<Container, std::list<Studentas>>)
                sarasas.sort([&](const Studentas& a, const Studentas& b) {
                float ga = (rusiuotPasirinkimas == 1) ? a.rezVid : a.rezMed;
                float gb = (rusiuotPasirinkimas == 1) ? b.rezVid : b.rezMed;
                return ga > gb;
                    });
            break;
        default:
            cout << "Neteisingas pasirinkimas, paliekama be papildomo rikiavimo.\n";
            break;
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

        fout << left << setw(15) << "Pavarde"
            << setw(15) << "Vardas"
            << antraste << endl;
        fout << string(45, '-') << endl;

        for (const auto& s : sarasas) {
            float balas = (pagalVidurki) ? s.rezVid : s.rezMed;
            fout << left << setw(15) << s.pav
                << setw(15) << s.vard
                << fixed << setprecision(2) << balas << endl;
        }
        };

    spausdinti(outKiet, kietiakiai, rusiuotPasirinkimas == 1);
    spausdinti(outVarg, vargsiukai, rusiuotPasirinkimas == 1);

    outKiet.close();
    outVarg.close();

    cout << "Studentai surusiuoti ir issaugoti:\n";
    cout << " - kietiakiai.txt: " << kietiakiai.size() << " studentu\n";
    cout << " - vargsiukai.txt: " << vargsiukai.size() << " studentu\n";
    cout << "Rusiavimas i kietiakus/vargsiukus truko: " << laikRusiavimui2.praejes_laikas() << " sek.\n";
    cout << "Isvedimas i kietiakiai/vargsiukai failus truko: " << laikIrasymui2.praejes_laikas() << " sek.\n";
}



#endif // FUNKCIJOS_H
