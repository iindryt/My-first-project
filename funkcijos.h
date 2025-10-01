#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H

#include <vector>
#include "studentas.h"

int random(int min, int max);
float Mediana(const std::vector<int>& pazymiai);
float Vidurkis(const std::vector<int>& pazymiai);
int ivestiEgzamina();
Studentas ivesk();
void spausdintiRezultatusIrRusiavima(const std::vector<Studentas>& Grupe);

#endif // FUNKCIJOS_H
