//
// Created by sim on 5/26/2025.
//

#include "../h-uri/Rabbit.h"

Rabbit::Rabbit(): Animal("", 0, 0), Pets(false), NonPets("", 0) {}

Rabbit::Rabbit(const std::string &name, const int cost, const int feed_time, bool pet, const std::string &resulted_good,
    const int resulted_money):
    Animal(name, cost, feed_time), Pets(pet), NonPets(resulted_good, resulted_money) {}

void Rabbit::rabbitInterference(int &money) {
    std::srand(std::time(nullptr));
    if (std::rand() % 2 == 0) {  // 50% șansă să apară un iepure
        std::cout << "A aparut un iepure salbatic in timp ce hraneai animalele!\n";
        std::cout << "Ce vrei sa faci cu el?\n";
        std::cout << "1. Il mangai \n";
        std::cout << "2. Il prinzi si il vinzi (obtii bani)\n";
        int opt;
        std::cin >> opt;

        if (opt == 2) {
            int gainedMoney; // între 15 și 35
            gainedMoney = 15 + std::rand() % 21;
            money += gainedMoney;
            std::cout << "Ai prins iepurele si ai castigat " << gainedMoney << " bani!\n";
            std::cout << "Banii actuali: " << money << "\n";
        } else {
            std::cout << "Ai mangaiat iepurele. Pentru ca ai fost dragut cu el, lumea este puutin mai buna acum! \n";
        }
    }
}

// void Rabbit::interact() const {
//     std::cout << "Ai hrănit " << getName() << " și ai obținut " << getResultedGood() << ".\n";
// }
