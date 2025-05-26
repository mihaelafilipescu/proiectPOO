//
// Created by sim on 5/26/2025.
//

#ifndef FARM_H
#define FARM_H
#include <indicators.hpp>
#include "Barn.h"
#include "Machine.h"
#include "NonPets.h"
#include "Plant.h"
#include "Rabbit.h"
#include "Silo.h"
#include "Weed.h"


class Farm {
    int money = 50;
    Silo silo;
    Barn barn;
public:
    int getMoney () const;

    explicit Farm(int money);

    Farm(Silo silo, Barn barn);

    explicit Farm(Silo silo);

    explicit Farm(Barn barn);

    Farm(const Farm &other);

    Farm(Farm &&other) noexcept;

    Farm & operator=(const Farm &other);

    Farm & operator=(Farm &&other) noexcept;

    ~Farm();

    friend std::ostream& operator<<(std::ostream& os, const Farm& farm);

    void progressBar (int timp);


    void harvestPlant(const Plant& plant, const Weed& weed);

    void feedAnimal(const NonPets& animal,  Rabbit& rabbit);

    void buyMachine(const Machine &machine, const Farm &farm);

    void machineMaintenance(const Machine &machine, const Farm &farm);
};



#endif //FARM_H
