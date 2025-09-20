#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::fixed;
using std::setprecision;

struct Studentas {
    string vard;
    string pav;
    vector<int> paz;
    int egzas;
    float rezVid;
    float rezMed;
};
float Mediana(vector<int> &pazymiai) {
    sort(pazymiai.begin(), pazymiai.end());  
    size_t n = pazymiai.size();
    if (n == 0) return 0;
    if (n % 2 == 1) {
        return pazymiai[n / 2];
    } else {
        return (pazymiai[n/2 - 1] + pazymiai[n/2]) / 2.0;
    }
}

int main (){
    Studentas Laik;
    int sum=0, n, m;

    cout << "Iveskite varda: "; 
    cin >> Laik.vard;

    cout << "Iveskite Pavarde: "; 
    cin >> Laik.pav;

    cout << "Iveskite pazymiu skaiciu: "; 
    cin >> n;

    for (int i=0; i<n; i++){
        cout << "Iveskite " << i+1 << " paz. is " << n << " : "; 
        cin >> m;
        Laik.paz.push_back(m);
        sum += m;
    }

    cout << "Iveskite egzamina: "; 
    cin >> Laik.egzas;

    float vidurkis = (float)sum / n;
    float mediana = Mediana(Laik.paz);

    Laik.rezVid = Laik.egzas * 0.6 + vidurkis * 0.4;
    Laik.rezMed = Laik.egzas * 0.6 + mediana * 0.4;
    
    cout << "\nPasirinkite galutinio balo skaiciavimo metoda:" << endl;
    cout << "1 - Vidurkis" << endl;
    cout << "2 - Mediana" << endl;
    cout << "3 - Abu" << endl;

    int pasirinkimas;
    cin >> pasirinkimas;

    cout << endl << left << setw(15) << "Pavarde"
         << setw(15) << "Vardas";

    if (pasirinkimas == 1) {
        cout << "Galutinis (Vid.)" << endl;
        cout << "----------------------------------------------" << endl;
        cout << left << setw(15) << Laik.pav
             << setw(15) << Laik.vard
             << left << setw(20) << fixed << setprecision(2) << Laik.rezVid << endl;

    } else if (pasirinkimas == 2) {
        cout << "Galutinis (Med.)" << endl;
        cout << "----------------------------------------------" << endl;
        cout << left << setw(15) << Laik.pav
             << setw(15) << Laik.vard
             << left << setw(20) << fixed << setprecision(2) << Laik.rezMed << endl;

    } else if (pasirinkimas == 3) {
        cout << "Galutinis (Vid.) / Galutinis (Med.)" << endl;
        cout << "---------------------------------------------------------" << endl;
        cout << left << setw(15) << Laik.pav
             << setw(15) << Laik.vard
             << left << setw(20) << fixed << setprecision(2) << Laik.rezVid
             << left << setw(20) << fixed << setprecision(2) << Laik.rezMed << endl;

    } else {
        cout << "Klaida: pasirinktas netinkamas simbolis. Iveskite 1, 2 arba 3." << endl;
    }

    return 0;
}


