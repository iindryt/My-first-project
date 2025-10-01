#ifndef DUOMENYS_H
#define DUOMENYS_H

#include <string>
#include <vector>
#include "studentas.h"

std::vector<Studentas> nuskaitytiIsFailo(const std::string& failoVardas);
void generuotiFaila(int kiekis, const std::string& failoVardas, int ndKiekis = 5);

#endif // DUOMENYS_H

