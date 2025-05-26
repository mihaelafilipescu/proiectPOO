//
// Created by sim on 5/26/2025.
//
#include <iostream>
#include "../h-uri/NonPets.h"

NonPets::NonPets(): Animal("", 0, 0), ResultedGood(""), resultedMoney(0) {}

const std::string & NonPets::getResultedGood() const { return ResultedGood; }

int NonPets::getRestultedMoney() const { return resultedMoney; }

NonPets::NonPets(const std::string &name, const int cost, const int feed_time, const std::string &resulted_good,
    const int resulted_money):
    Animal(name, cost, feed_time),
    ResultedGood(resulted_good), resultedMoney(resulted_money) {}

NonPets::NonPets(const std::string &resulted_good, const int resulted_money): ResultedGood(resulted_good), resultedMoney(resulted_money) {}

// void NonPets::interact(int& money) const {
// }
