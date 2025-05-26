//
// Created by sim on 5/26/2025.
//

#include "../h-uri/Machine.h"

Machine::Machine() {
}

const std::string & Machine::getName() const { return Name; }

int Machine::getCost() const { return Cost; }

int Machine::getBuildTime() const { return BuildTime; }

int Machine::getMaintenance() const { return Maintenance; }

Machine::Machine(std::string Name_, const int Cost_, const int BuildTime_, const int Maintenance_): Name{std::move(Name_)}, Cost{Cost_},
    BuildTime{BuildTime_}, Maintenance{Maintenance_} {}

Machine::~Machine() {
}
