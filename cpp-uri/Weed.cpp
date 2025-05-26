//
// Created by sim on 5/26/2025.
//

#include "../h-uri/Weed.h"

Weed::Weed() {
}

Weed::Weed(const std::string &name, const int cost, const int grow_time, const int resulted_money, const bool poisonous,
    const int removeCost):
    Plant(name, cost, grow_time, resulted_money), isPoisonous(poisonous), RemoveCost(removeCost) {}

Weed::~Weed() {
}

int Weed::getGrowTime() const {
    int extraTime = 0;

    //buruieni in 40% din cazuri
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 99);

    if (dis(gen) < 40) {
        // intre 5 si 10 secunde in plus
        std::uniform_int_distribution<> weedDelay(1, 10);
        extraTime = weedDelay(gen);
        std::cout << "Ups! Au aparut buruieni. Timpul de recoltare a fost prelungit cu "
                << extraTime << " secunde.\n";
    }
    return baseGetGrowTime() + extraTime;
}
