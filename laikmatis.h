#ifndef LAIKMATIS_H
#define LAIKMATIS_H

#include <chrono>

class Laikmatis {
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> pradzia;
public:
    Laikmatis() : pradzia{ std::chrono::high_resolution_clock::now() } {}
    void atstatyti() {
        pradzia = std::chrono::high_resolution_clock::now();
    }
    double praejes_laikas() const {
        return std::chrono::duration<double>(
            std::chrono::high_resolution_clock::now() - pradzia
        ).count();
    }
};

#endif
