#ifndef DUOMENYS_H
#define DUOMENYS_H

#include "studentas.h"
#include <vector>
#include <string>

std::vector<Studentas> nuskaitytiIsFailo(const std::string& failoVardas);
void generuotiFaila(int kiekis, const std::string& failoVardas, int ndKiekis = 5);

#endif // DUOMENYS_H

