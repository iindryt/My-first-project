#include "duomenys.h"
#include "funkcijos.h" // kad būtų galima naudoti random ir t.t.
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

vector<Studentas> nuskaitytiIsFailo(const string& failoVardas) {
    vector<Studentas> studentai;
    ifstream in(failoVardas);

    if (!in) {
        cout << "Klaida: nepavyko atidaryti failo: " << failoVardas << endl;
        return studentai;
    }

    string eilute;
    getline(in, eilute); // praleidziam header

    while (getline(in, eilute)) {
        if (eilute.empty()) continue;

        istringstream ss(eilute);
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

        s.rezVid = s.egzas * 0.6f + vidurkis * 0.4f;
        s.rezMed = s.egzas * 0.6f + mediana * 0.4f;

        studentai.push_back(s);
    }

    return studentai;
}

void generuotiFaila(int kiekis, const string& failoVardas, int ndKiekis) {
    ofstream out(failoVardas);
    if (!out) {
        cerr << "Nepavyko sukurti failo: " << failoVardas << endl;
        return;
    }

    out << "Vardas Pavarde";
    for (int i = 1; i <= ndKiekis; i++) {
        out << " ND" << i;
    }
    out << " Egzaminas" << endl;

    for (int i = 1; i <= kiekis; ++i) {
        out << "Vardas" << i << " Pavarde" << i;
        for (int j = 0; j < ndKiekis; ++j) {
            out << " " << random(1, 10);
        }
        out << " " << random(1, 10) << endl;
    }

    out.close();
    cout << "Failas '" << failoVardas << "' sukurtas su " << kiekis << " irasu." << endl;
}
