#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H

#include "studentas.h"
#include <vector>
#include <string>

int random(int min, int max);

float Mediana(const std::vector<int>& pazymiai);
float Vidurkis(const std::vector<int>& pazymiai);

int ivestiEgzamina();
Studentas ivesk();

#endif // FUNKCIJOS_H
