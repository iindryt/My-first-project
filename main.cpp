#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

struct Studentas {
    string vard;
    string pav;
    vector<int> paz;
    int egzas;
    float rez;
};

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

    Laik.rez = Laik.egzas * 0.6 + double(sum) / double(Laik.paz.size()) * 0.4;

    cout << Laik.vard << " | " << Laik.pav << " | " << Laik.rez << endl;
}

