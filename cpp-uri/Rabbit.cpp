//
// Created by sim on 5/26/2025.
//

#include "Rabbit.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

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

void Rabbit::interact() const {
    std::cout << "Interactionezi cu iepurele " << getName() << ".\n";
    std::cout << "Ce vrei sa faci?\n";
    std::cout << "1. Il mangai (ATENTIE: Exista riscul sa te muste!)\n";
    std::cout << "2. Il hranesti si obtii " << getResultedGood() << "\n";

    int choice;
    std::cin >> choice;

    if (choice == 1) {
        std::cout << "AVERTIZARE: Iepurele poate sa te muste! Esti sigur? (1 - Da, 2 - Nu): ";
        int confirm;
        std::cin >> confirm;

        if (confirm == 1) {

            if (attemptPetting()) {
                std::cout << "AUCH! " << getName() << " te-a muscat! Ai primit o mica rana!\n";
                std::cout << "Poate data viitoare sa fii mai atent...\n";
            } else {
                std::cout << "Norocul tau! " << getName() << " te-a lasat sa il mangai si pare fericit!\n";
            }
        } else {
            std::cout << "Ai ales sa nu risti. Decizie inteleapta!\n";
        }
    } else if (choice == 2) {
        std::cout << "Ai hranit " << getName() << " si ai obtinut " << getResultedGood() << ".\n";
        std::cout << "Ai castigat " << getRestultedMoney() << " bani din vanzarea produsului!\n";
    } else {
        std::cout << "Alegere invalida!\n";
    }
}

bool Rabbit::attemptPetting() const {
    std::srand(std::time(nullptr));
    // 30% șansă să te muste iepurele
    return (std::rand() % 100) < 30;
}