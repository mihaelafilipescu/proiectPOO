//
// Created by sim on 5/26/2025.
//

#ifndef PETS_H
#define PETS_H
#include <iostream>
#include "Animal.h"



class Pets : virtual public Animal {
    bool pet;
    // bool fed;
public:
    Pets();
    // [[nodiscard]] bool getPet() const { return pet; };
    Pets ( const std::string& name, const int cost, const int feed_time, bool pet);
    explicit Pets( bool pet_);

    void interact() const override;
};



#endif //PETS_H
