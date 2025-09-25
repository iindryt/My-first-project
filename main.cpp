#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::fixed;
using std::setprecision;
using std::left;
using std::setw;
using std::cerr;

struct Studentas {
    string vard;
    string pav;
    vector<int> paz;
    int egzas;
    float rezVid;
    float rezMed;
};
int random(int min, int max) {
    return min + rand() % (max - min + 1);
}
float Mediana(const vector<int> &pazymiai) {
    if (pazymiai.empty()) 
        return 0.0;
    vector<int> kopija = pazymiai;
    sort(kopija.begin(), kopija.end());
    
    size_t n = kopija.size();
    if (n % 2 == 1) {
        return kopija[n / 2];
    } else {
        return (kopija[n/2 - 1] + kopija[n/2]) / 2.0;
    }
}
float Vidurkis(const vector<int>& pazymiai) {
    if (pazymiai.empty()) return 0.0;
    int suma = 0;
    for (int paz : pazymiai) {
        suma += paz;
    }
    return (float)suma / pazymiai.size();
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
    int  m, pazymiuSkaicius = 0;

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
        } else {
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


    //Pridedamas klausimas apie egzamino pazymio generavima
    char genEgz;
    cout << "Ar norite generuoti egzamino pazymi? (t/n): ";
    cin >> genEgz;

        if (genEgz == 't' || genEgz == 'T') {
            Laik.egzas = random(1, 10);
            cout << "Sugeneruotas egzamino pazymys: " << Laik.egzas << endl;
        } else {
           Laik.egzas = ivestiEgzamina();
        }

    float vidurkis = Vidurkis(Laik.paz);
    float mediana = Mediana(Laik.paz);

    Laik.rezVid = Laik.egzas * 0.6 + vidurkis * 0.4;
    Laik.rezMed = Laik.egzas * 0.6 + mediana * 0.4;

    return Laik;
}
vector<Studentas> nuskaitytiIsFailo(const string &failoVardas) {
    vector<Studentas> studentai;
    std::ifstream in(failoVardas);

    if (!in) {
        cout << "Klaida: nepavyko atidaryti failo: " << failoVardas << endl;
        return studentai;
    }

    string eilute;
    //Pirma eilute (header) praleidziam
    getline(in, eilute);

    while (getline(in, eilute)) {
        if (eilute.empty()) continue;

        std::istringstream ss(eilute);
        string vard, pav;
        ss >> vard >> pav;

        Studentas s;
        s.vard = vard;
        s.pav = pav;

        vector<int> laikPaz;
        int paz;

        while (ss >> paz) {
            laikPaz.push_back(paz);
        }

        if (laikPaz.size() < 2) {
            cerr << "Klaida: per mazai pazymiu eiluteje: " << eilute << endl;
            continue;
        }

        s.egzas = laikPaz.back();
        laikPaz.pop_back();
        s.paz = laikPaz;

        float vidurkis = Vidurkis(s.paz);
        float mediana = Mediana(s.paz);

        s.rezVid = s.egzas * 0.6 + vidurkis * 0.4;
        s.rezMed = s.egzas * 0.6 + mediana * 0.4;

        studentai.push_back(s);
    }

    return studentai;
}

int main() {
    srand(time(NULL));
    vector<Studentas> Grupe;
    int veiksmas;

    while (true) {
        cout << "\nPasirinkite veiksma:\n";
        cout << "1 - Prideti studenta rankiniu budu\n";
        cout << "2 - Nuskaityti studentus is failo\n";
        cout << "3 - Rodyti studentu rezultatus\n";
        cout << "4 - Baigti programa\n";
        cout << "Jusu pasirinkimas yra: ";
        cin >> veiksmas;

        if (veiksmas == 1) {
            Studentas s = ivesk();
            if (s.vard == "0") {
                cout << "Studentu ivedimas nutrauktas." << endl;
                continue;
            }
            if (s.paz.size() == 0) {
                cout << "Studentas neivestas del netinkamu pazymiu." << endl;
                continue;
            }
            Grupe.push_back(s);
        }
        else if (veiksmas == 2) {
            string failas;
            cout << "Iveskite failo pavadinima: ";
            cin >> failas;
            vector<Studentas> isFailo = nuskaitytiIsFailo(failas);
            Grupe.insert(Grupe.end(), isFailo.begin(), isFailo.end());
            cout << "Is failo yra nuskaityta " << isFailo.size() << " studentu." << endl;
        }
        else if (veiksmas == 3) {
            if (Grupe.empty()) {
                cout << "Studentu sarasas tuscias." << endl;
                continue;
            }
            bool iFaila = Grupe.size() > 10000;
            std::ofstream out;

            if (iFaila) {
                out.open("rezultatai.txt");
                if (!out) {
                    cout << "Klaida: nepavyko sukurti rezultatu failo." << endl;
                    continue;
                }
            cout << "Studentu yra daugiau nei 10 000, rezultatai bus issaugoti faile 'rezultatai.txt'." << endl;
            }
            //Rusiavimas pagal vardus
            sort(Grupe.begin(), Grupe.end(), [](const Studentas &a, const Studentas &b) {
                return a.vard < b.vard;
            });

            int pasirinkimas;
            cout << "\nPasirinkite galutinio balo skaiciavimo metoda:\n";
            cout << "1 - Vidurkis\n";
            cout << "2 - Mediana\n";
            cout << "3 - Abu (vidurkis ir mediana)\n";
            cout << "Jusu pasirinkimas: ";
            cin >> pasirinkimas;

            if (pasirinkimas == 1) {
                if (iFaila) {
                    out << left << setw(15) << "Pavarde" << setw(15) << "Vardas" << "Galutinis (Vid.)" << endl;
                    out << "----------------------------------------------" << endl;
                    for (int i = 0; i < Grupe.size(); i++) {
                        out << left << setw(15) << Grupe[i].pav
                        << setw(15) << Grupe[i].vard
                        << fixed << setprecision(2) << Grupe[i].rezVid << endl;
                    }
                    out.close();
                    cout << "Rezultatai issaugoti faile 'rezultatai.txt'" << endl;
                } else {
                    cout << left << setw(15) << "Pavarde" << setw(15) << "Vardas" << "Galutinis (Vid.)" << endl;
                    cout << "----------------------------------------------" << endl;
                    for (int i = 0; i < Grupe.size(); i++) {
                        cout << left << setw(15) << Grupe[i].pav
                         << setw(15) << Grupe[i].vard
                         << fixed << setprecision(2) << Grupe[i].rezVid << endl;
                    }
                } 
            }else if (pasirinkimas == 2) {
                 if (iFaila) {
                    out << left << setw(15) << "Pavarde" << setw(15) << "Vardas" << "Galutinis (Med.)" <<endl; 
                    out << "----------------------------------------------" << endl;
                    for (int i = 0; i < Grupe.size(); i++) {
                        out << left << setw(15) << Grupe[i].pav
                        << setw(15) << Grupe[i].vard
                        << fixed << setprecision(2) << Grupe[i].rezMed << endl;
                    }
                    out.close();
                    cout << "Rezultatai issaugoti faile 'rezultatai.txt'" << endl;
                } else {
                    cout << left << setw(15) << "Pavarde" << setw(15) << "Vardas" << "Galutinis (Med.)" << endl;
                    cout << "----------------------------------------------" << endl;
                    for (int i = 0; i < Grupe.size(); i++) {
                        cout << left << setw(15) << Grupe[i].pav
                         << setw(15) << Grupe[i].vard
                         << fixed << setprecision(2) << Grupe[i].rezMed << endl;
                    }
                } 
        
            }else if (pasirinkimas == 3) {
                if (iFaila) {
                    out << left << setw(15) << "Pavarde"
                        << setw(15) << "Vardas"
                        << setw(20) << "Galutinis (Vid.)"
                        << setw(20) << "Galutinis (Med.)" << endl;
                    out << string(70, '-') << endl;

                    for (int i = 0; i < Grupe.size(); i++) {
                        out << left << setw(15) << Grupe[i].pav
                            << setw(15) << Grupe[i].vard
                            << setw(20) << fixed << setprecision(2) << Grupe[i].rezVid
                            << setw(20) << fixed << setprecision(2) << Grupe[i].rezMed << endl;
                    }

                    out.close();
                    cout << "Rezultatai issaugoti faile 'rezultatai.txt'" << endl;

                } else  {
                    cout << left << setw(15) << "Pavarde"
                         << setw(15) << "Vardas"
                         << setw(20) << "Galutinis (Vid.)"
                         << setw(20) << "Galutinis (Med.)" << endl;
                    cout << string(70, '-') << endl;

                    for (int i = 0; i < Grupe.size(); i++) {
                        cout << left << setw(15) << Grupe[i].pav
                             << setw(15) << Grupe[i].vard
                             << setw(20) << fixed << setprecision(2) << Grupe[i].rezVid
                             << setw(20) << fixed << setprecision(2) << Grupe[i].rezMed << endl;
                    }
                }
            }

            }     else {
                cout << "Klaida: pasirinktas netinkamas simbolis. Iveskite 1, 2 arba 3." << endl;
            }
        }
             else if (veiksmas == 4) {
            cout << "Programa baigiama." << endl;
            break;
        }
        else {
            cout << "Klaidingas pasirinkimas, bandykite dar karta." << endl;
        }
    }

    return 0;
}



