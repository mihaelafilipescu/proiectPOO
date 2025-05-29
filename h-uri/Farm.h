//
// Created by sim on 5/26/2025.
//

#ifndef FARM_H
#define FARM_H
#include <indicators.hpp>
#include "Barn.h"
#include "Machine.h"
#include "Silo.h"
#include <vector>

class Plant;
class Weed;
class Rabbit; // Forward declaration
class NonPets;

class Farm {
    int money = 500;
    Silo silo;
    Barn barn;
    std::vector<Machine> ownedMachines;

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

    void decreaseMoney(int amount);

    void addMachine(const Machine& machine);
    void showOwnedMachines() const;
    void showMachineRecipes(const Machine& machine) const;
    bool checkIngredientsAvailable(const Recipe& recipe) const;
    void consumeIngredients(const Recipe& recipe);
    void produceWithMachine(int machineIndex);
    void showProductionMenu();

    Silo& getSilo() { return silo; }
    Barn& getBarn() { return barn; }
    // const std::vector<Machine>& getOwnedMachines() const { return ownedMachines; }
};

#endif //FARM_H