//
// Created by sim on 5/26/2025.
//

#ifndef RABBIT_H
#define RABBIT_H
#include "Pets.h"
#include "NonPets.h"
#include <chrono>
#include <random>



class Rabbit : public Pets, public NonPets {
public:
    Rabbit();
    Rabbit(const std::string& name, const int cost, const int feed_time, bool pet, const std::string& resulted_good, const int resulted_money);

    void rabbitInterference(int& money);
    void interact() const override;

private:
    bool attemptPetting() const; // Returnează true dacă iepurele te mușcă
};

#endif //RABBIT_H