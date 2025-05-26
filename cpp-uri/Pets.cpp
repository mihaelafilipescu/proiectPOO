//
// Created by sim on 5/26/2025.
//

#include "../h-uri/Pets.h"

Pets::Pets(): Animal("", 0, 0), pet(false) {
}

Pets::Pets(const std::string &name, const int cost, const int feed_time, bool pet): Animal(name, cost, feed_time), pet(pet) {}

Pets::Pets(bool pet_): pet(pet_) {}

void Pets::interact(int& money) const {
    // pet = 1;
    std::cout << "Ai mângâiat animalul de companie " << getName() << "!\n";
}
