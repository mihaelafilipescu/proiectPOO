//
// Created by sim on 5/26/2025.
//

#include "Pets.h"

Pets::Pets(): Animal("", 0, 0), pet(false) {
}

Pets::Pets(const std::string &name, const int cost, const int feed_time, bool pet): Animal(name, cost, feed_time), pet(pet) {}

Pets::Pets(bool pet_): pet(pet_) {}

void Pets::interact() const {
    if (pet) {
        std::cout << "Animalul de companie " << getName() << " a fost deja mangaiat si este multumit!\n";
    } else {
        std::cout << "Ai mangaiat animalul de companie " << getName() << "! Pare fericit și relaxat!\n";
    }
}

