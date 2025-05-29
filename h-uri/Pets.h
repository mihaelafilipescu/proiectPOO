
//
// Created by sim on 5/26/2025.
//

#ifndef PETS_H
#define PETS_H
#include <iostream>
#include <thread>
#include <chrono>
#include "Animal.h"

class Farm; // Forward declaration

class Pets : virtual public Animal {
    bool petted;
public:
    Pets();
    [[nodiscard]] bool isPetted() const { return petted; }
    Pets(const std::string& name, const int cost, const int feed_time, bool petted = false);
    explicit Pets(bool petted_);

    void interact() const override;

private:
    void resetPettedStatus() const;
};

#endif //PETS_H