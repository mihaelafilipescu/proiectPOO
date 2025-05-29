//
// Created by sim on 5/26/2025.
//

#include "../h-uri/Silo.h"
#include <algorithm>

Silo::Silo(const std::vector<std::pair<std::string, int>> &stored_plants): storedPlants(stored_plants) {
}

Silo::Silo() {}

Silo::~Silo() {
}

Silo::Silo(const Silo &other): storedPlants(other.storedPlants) {
}

Silo::Silo(Silo &&other) noexcept: storedPlants(std::move(other.storedPlants)) {
}

Silo & Silo::operator=(const Silo &other) {
    if (this == &other)
        return *this;
    storedPlants = other.storedPlants;
    return *this;
}

Silo & Silo::operator=(Silo &&other) noexcept {
    if (this == &other)
        return *this;
    storedPlants = std::move(other.storedPlants);
    return *this;
}

void Silo::storePlants(const std::string &plantName, int quantity) {
    for (size_t i = 0 ; i < storedPlants.size(); ++i) {
        if (storedPlants[i].first == plantName) {
            storedPlants[i].second += quantity;
            // std::cout << quantity << " " << plantName << " adaugate in silo. \n";
            return;
        }
    }
    storedPlants.emplace_back(plantName, quantity);
    // std::cout << quantity << " " << plantName << " adaugate in silo. \n";
}

void Silo::siloContent() const {
    std::cout<< "In silo ai: \n";
    for (const auto & storedPlant : storedPlants) {
        std::cout << "- " << storedPlant.first << ": " << storedPlant.second << "\n";
    }
}

std::ostream & operator<<(std::ostream &os, const Silo &silo) {
    for (const auto& stored_plants : silo.storedPlants) {
        os << stored_plants.first << " " << stored_plants.second << " ";
    }
    return os;
}

// Functii noi pentru machine production
bool Silo::hasEnough(const std::string& itemName, int quantity) const {
    for (const auto& item : storedPlants) {
        if (item.first == itemName) {
            return item.second >= quantity;
        }
    }
    return false;
}

void Silo::removeItem(const std::string& itemName, int quantity) {
    for (size_t i = 0; i < storedPlants.size(); ++i) {
        if (storedPlants[i].first == itemName) {
            if (storedPlants[i].second >= quantity) {
                storedPlants[i].second -= quantity;
                // Remove item completely if quantity becomes 0
                if (storedPlants[i].second == 0) {
                    storedPlants.erase(storedPlants.begin() + i);
                }
                return;
            }
        }
    }
}

const std::vector<std::pair<std::string, int>>& Silo::getStoredPlants() const {
    return storedPlants;
}