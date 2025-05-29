//
// Created by sim on 5/26/2025.
//
#include <iostream>
#include "../h-uri/NonPets.h"
#include "../h-uri/Farm.h"


NonPets::NonPets(): Animal("", 0, 0), ResultedGood(""), resultedMoney(0) {}

const std::string & NonPets::getResultedGood() const { return ResultedGood; }

int NonPets::getRestultedMoney() const { return resultedMoney; }

NonPets::NonPets(const std::string &name, const int cost, const int feed_time, const std::string &resulted_good,
    const int resulted_money):
    Animal(name, cost, feed_time),
    ResultedGood(resulted_good), resultedMoney(resulted_money) {}

NonPets::NonPets(const std::string &resulted_good, const int resulted_money): ResultedGood(resulted_good), resultedMoney(resulted_money) {}

void NonPets::interact() const {
    std::cout << "ATENTIE: Nu incerca sa mangai " << getName() << "! Acestea nu sunt animale de companie si poate fi periculos!\n";
    std::cout << "Pastreaza distanta pentru siguranta ta!\n";

    std::cout << "Vrei sa hranesti " << getName() << " in schimb? (1 - Da, 2 - Nu): ";
    int choice;
    std::cin >> choice;

    if (choice == 1) {
        std::cout << "Pentru a hrani " << getName() << " ai nevoie de acces la ferma.\n";
    } else {
        std::cout << "Ai ales sa nu hranesti animalul.\n";
    }
}

void NonPets::interact(Farm& farm, Rabbit& rabbit) const {
    std::cout << "ATENTIE: Nu incerca sa mangai " << getName() << "! Acestea nu sunt animale de companie si poate fi periculos!\n";
    std::cout << "Pastreaza distanta pentru siguranta ta!\n";

    std::cout << "Vrei sa hranesti " << getName() << " in schimb? (1 - Da, 2 - Nu): ";
    int choice;
    std::cin >> choice;

    if (choice == 1) {
        // Call the Farm's feedAnimal method
        // Note: We need to cast this to NonPets& since feedAnimal expects a non-const reference
        farm.feedAnimal(const_cast<NonPets&>(*this), rabbit);
    } else {
        std::cout << "Ai ales sa nu hranesti animalul.\n";
    }
}
