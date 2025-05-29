//
// Created by sim on 5/26/2025.
//

#include "Plant.h"
#include "Farm.h"


int Plant::baseGetGrowTime() const { return GrowTime; }

const std::string & Plant::getName() const { return Name; }

int Plant::getCost() const { return Cost; }

int Plant::getGrowTime() const { return GrowTime; }

int Plant::getResultedMoney() const { return resultedMoney; }

Plant::Plant(): Name(""), Cost(0), GrowTime(0), resultedMoney(0) {}

Plant::Plant(const std::string &name, const int cost, const int grow_time, const int resulted_money): Name(name),
    Cost(cost),
    GrowTime(grow_time),
    resultedMoney(resulted_money) {
}

Plant::~Plant() {
}
