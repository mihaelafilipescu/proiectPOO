//
// Created by sim on 5/26/2025.
//

#ifndef PLANT_H
#define PLANT_H
#include <string>
#include "Farm.h"



class Plant {
    std::string Name;
    int Cost;
    int GrowTime;
    int resultedMoney;
protected:
    [[nodiscard]] int baseGetGrowTime() const;
public:
    [[nodiscard]] const std::string& getName() const;

    [[nodiscard]] int getCost() const;
    [[nodiscard]] virtual int getGrowTime() const;
    [[nodiscard]] int getResultedMoney() const;
    explicit Plant ();

    Plant(const std::string& name, const int cost, const int grow_time, const int resulted_money);

    virtual ~Plant();
};



#endif //PLANT_H
