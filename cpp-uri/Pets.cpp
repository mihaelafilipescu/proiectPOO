//
// Created by sim on 5/26/2025.
//

#include "../h-uri/Pets.h"

Pets::Pets(): Animal("", 0, 0), petted(false) {
}

Pets::Pets(const std::string &name, const int cost, const int feed_time, bool petted):
    Animal(name, cost, feed_time), petted(petted) {}

Pets::Pets(bool petted_): petted(petted_) {}

void Pets::interact() const {
    if (petted) {
        std::cout << "Animalul de companie " << getName() << " a fost deja mangaiat si este multumit!\n";
    } else {
        std::cout << "Ai mangaiat animalul de companie " << getName() << "! Pare fericit si relaxat!\n";

        // Modificăm statusul petted la true
        const_cast<Pets*>(this)->petted = true;

        // Creăm un thread pentru a reseta statusul după 5 secunde
        std::thread([this]() {
            std::this_thread::sleep_for(std::chrono::seconds(5));
            const_cast<Pets*>(this)->petted = false;
            std::cout << "Animalutul tau a uitat ca l-ai mangaiat. Poti sa il mangai din nou!\n";
        }).detach();
    }
}
