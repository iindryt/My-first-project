#include "funkcijos.h"
#include "studentas.h"
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::fixed;
using std::left;
using std::setw;
using std::setprecision;
using std::ofstream;

int random(int min, int max) {
    return min + rand() % (max - min + 1);
}

float Mediana(const vector<int>& pazymiai) {
    if (pazymiai.empty()) return 0.0f;
    vector<int> kopija = pazymiai;
    std::sort(kopija.begin(), kopija.end());

    size_t n = kopija.size();
    if (n % 2 == 1)
        return kopija[n / 2];
    else
        return (kopija[n / 2 - 1] + kopija[n / 2]) / 2.0f;
}

float Vidurkis(const vector<int>& pazymiai) {
    if (pazymiai.empty()) return 0.0f;
    int suma = 0;
    for (int paz : pazymiai) {
        suma += paz;
    }
    return static_cast<float>(suma) / pazymiai.size();
}

int ivestiEgzamina() {
    int egz;
    while (true) {
        cout << "Iveskite egzamino pazymi (1-10): ";
        if (!(cin >> egz)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Klaida: iveskite skaiciu nuo 1 iki 10." << endl;
            continue;
        }
        if (egz < 1 || egz > 10) {
            cout << "Egzamino pazymys turi buti tarp 1 ir 10." << endl;
            continue;
        }
        return egz;
    }
}

Studentas ivesk() {
    Studentas Laik;
    int m, pazymiuSkaicius = 0;

    cout << "Iveskite varda (arba 0 jei norite baigti): ";
    cin >> Laik.vard;
    if (Laik.vard == "0") return Laik;

    cout << "Iveskite pavarde: ";
    cin >> Laik.pav;

    char pasirinkimas;
    cout << "Ar norite generuoti atsitiktinius namu darbu pazymius? (t/n): ";
    cin >> pasirinkimas;

    if (pasirinkimas == 't' || pasirinkimas == 'T') {
        cout << "Iveskite kiek namu darbu generuoti: ";
        cin >> pazymiuSkaicius;

        for (int i = 0; i < pazymiuSkaicius; i++) {
            m = random(1, 10);
            cout << "Sugeneruoto namu darbo nr. " << i + 1 << " pazymys: " << m << endl;
            Laik.paz.push_back(m);
        }
    }
    else {
        cout << "Iveskite namu darbu pazymius po viena. Norint baigti, iveskite ne skaiciu (pvz., raide)." << endl;
        while (true) {
            cout << "Iveskite namu darba nr. " << pazymiuSkaicius + 1 << ": ";
            if (!(cin >> m)) {
                cin.clear();
                cin.ignore(1000, '\n');
                break;
            }
            if (m < 1 || m > 10) {
                cout << "Klaida: pazymys turi buti tarp 1 ir 10." << endl;
                continue;
            }
            Laik.paz.push_back(m);
            pazymiuSkaicius++;
        }

        if (pazymiuSkaicius == 0) {
            cout << "Nepavyko ivesti nei vieno pazymio." << endl;
            return Laik;
        }
    }

    char genEgz;
    cout << "Ar norite generuoti egzamino pazymi? (t/n): ";
    cin >> genEgz;

    if (genEgz == 't' || genEgz == 'T') {
        Laik.egzas = random(1, 10);
        cout << "Sugeneruotas egzamino pazymys: " << Laik.egzas << endl;
    }
    else {
        Laik.egzas = ivestiEgzamina();
    }

    float vidurkis = Vidurkis(Laik.paz);
    float mediana = Mediana(Laik.paz);

    Laik.rezVid = Laik.egzas * 0.6f + vidurkis * 0.4f;
    Laik.rezMed = Laik.egzas * 0.6f + mediana * 0.4f;

    return Laik;
}


void spausdintiRezultatusIrRusiavima(const vector<Studentas>& Grupe) {
    if (Grupe.empty()) {
        cout << "Studentu sarasas tuscias." << endl;
        return;
    }

    // --- Rūšiavimas pagal vardą ---
    Laikmatis laikRusiavimui;
    vector<Studentas> surikiuoti = Grupe;

    std::sort(surikiuoti.begin(), surikiuoti.end(), [](const Studentas& a, const Studentas& b) {
        return a.vard < b.vard;
        });
    double rusiavimoLaikas = laikRusiavimui.praejes_laikas();

    // --- Pasirinkimas kaip skaičiuoti galutinį balą ---
    int pasirinkimas;
    cout << "\nPasirinkite galutinio balo skaiciavimo metoda:\n";
    cout << "1 - Vidurkis\n";
    cout << "2 - Mediana\n";
    cout << "3 - Abu (vidurkis ir mediana)\n";
    cout << "Jusu pasirinkimas: ";
    cin >> pasirinkimas;

    Laikmatis laikIrasymui;
    ofstream fout("rezultatai.txt");
    if (!fout) {
        cout << "Klaida: nepavyko sukurti rezultatu failo." << endl;
        return;
    }

    if (pasirinkimas == 1) {
        fout << left << setw(15) << "Pavarde" << setw(15) << "Vardas" << "Galutinis (Vid.)" << endl;
        fout << "----------------------------------------------" << endl;
        for (const auto& s : surikiuoti) {
            fout << left << setw(15) << s.pav
                << setw(15) << s.vard
                << fixed << setprecision(2) << s.rezVid << endl;
        }
    }
    else if (pasirinkimas == 2) {
        fout << left << setw(15) << "Pavarde" << setw(15) << "Vardas" << "Galutinis (Med.)" << endl;
        fout << "----------------------------------------------" << endl;
        for (const auto& s : surikiuoti) {
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

        for (const auto& s : surikiuoti) {
            fout << left << setw(15) << s.pav
                << setw(15) << s.vard
                << setw(20) << fixed << setprecision(2) << s.rezVid
                << setw(20) << fixed << setprecision(2) << s.rezMed << endl;
        }
    }
    fout.close();
    double isvedimoLaikas = laikIrasymui.praejes_laikas();

    cout << "Rezultatai issaugoti faile 'rezultatai.txt'\n";
    cout << "Rusiavimas truko: " << rusiavimoLaikas << " sek.\n";
    cout << "Isvedimas i 'rezultatai.txt' truko: " << isvedimoLaikas << " sek.\n";

    // --- Skirstymas į kietiakus / vargšiukus ---
    int rusiuotPasirinkimas;
    cout << "\nPagal ka norite surusiuoti studentus i dvi kategorijas (kietiakiai / vargsiukai)?\n";
    cout << "1 - Pagal galutini bala (vidurkis)\n";
    cout << "2 - Pagal galutini bala (mediana)\n";
    cout << "Jusu pasirinkimas: ";
    cin >> rusiuotPasirinkimas;

    Laikmatis laikRusiavimui2;
    vector<Studentas> kietiakiai, vargsiukai;
    for (const auto& s : Grupe) {
        float galutinis = (rusiuotPasirinkimas == 1) ? s.rezVid : s.rezMed;
        if (galutinis >= 5.0f)
            kietiakiai.push_back(s);
        else
            vargsiukai.push_back(s);
    }
    double rusiavimasIKategorijas = laikRusiavimui2.praejes_laikas();

     //pasirinkimas kaip rikiuoti kietiakus/vargšiukus ---
 int rikiavimoPasirinkimas;
 cout << "\nKaip norite, kad butu surikiuoti 'kietiakiai' ir 'vargsiukai'?\n";
 cout << "1 - Pagal varda\n";
 cout << "2 - Pagal pavarde\n";
 cout << "3 - Pagal galutini bala\n";
 cout << "Jusu pasirinkimas: ";
 cin >> rikiavimoPasirinkimas;

 auto rikiuotiPagal = [&](vector<Studentas>& sarasas) {
     switch (rikiavimoPasirinkimas) {
     case 1:
         std::sort(sarasas.begin(), sarasas.end(), [](const Studentas& a, const Studentas& b) {
             return a.vard < b.vard;
             });
         break;
     case 2:
         std::sort(sarasas.begin(), sarasas.end(), [](const Studentas& a, const Studentas& b) {
             return a.pav < b.pav;
             });
         break;
     case 3:
         std::sort(sarasas.begin(), sarasas.end(), [&](const Studentas& a, const Studentas& b) {
             float ga = (rusiuotPasirinkimas == 1) ? a.rezVid : a.rezMed;
             float gb = (rusiuotPasirinkimas == 1) ? b.rezVid : b.rezMed;
             return ga > gb; // didesnis balas pirmiau
             });
         break;
     default:
         cout << "Neteisingas pasirinkimas, paliekama be papildomo rikiavimo.\n";
         break;
     }
     };

 rikiuotiPagal(kietiakiai);
 rikiuotiPagal(vargsiukai);


    // --- Išvedimas į failus (pataisyta dalis) ---
    Laikmatis laikIrasymui2;
    ofstream outKiet("kietiakiai.txt");
    ofstream outVarg("vargsiukai.txt");

    if (!outKiet || !outVarg) {
        cout << "Klaida: nepavyko sukurti failu." << endl;
        return;
    }

    auto spausdinti = [](ofstream& fout, const vector<Studentas>& sarasas, bool pagalVidurki) {
        // Dinamiška antraštė pagal pasirinkimą
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

    double isvedimasIKategorijas = laikIrasymui2.praejes_laikas();

    cout << "Studentai surusiuoti ir issaugoti:\n";
    cout << " - kietiakiai.txt: " << kietiakiai.size() << " studentu\n";
    cout << " - vargsiukai.txt: " << vargsiukai.size() << " studentu\n";

    cout << "Rusiavimas i kietiakus/vargsiukus truko: " << rusiavimasIKategorijas << " sek.\n";
    cout << "Isvedimas i kietiakiai/vargsiukai failus truko: " << isvedimasIKategorijas << " sek.\n";
}
