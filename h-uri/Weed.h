//
// Created by sim on 5/26/2025.
//

#ifndef WEED_H
#define WEED_H
#include <random>
#include <iostream>
#include "Plant.h"

class Plant;


class Weed : public Plant {
    int RemoveCost;
public:
    Weed();
    Weed (const std::string& name, const int cost, const int grow_time, const int resulted_money, const int removeCost);
    ~Weed() override;

    int getGrowTime() const override;
    void removeWeeds(Farm &farm) const;
};




#endif //WEED_H
