//
// Created by sim on 5/26/2025.
//

#ifndef NONPETS_H
#define NONPETS_H
#include <iostream>
#include "Animal.h"


class NonPets : virtual public Animal {
    std::string ResultedGood;
    int resultedMoney;
public:
    NonPets();
    [[nodiscard]] const std::string& getResultedGood() const;
    int getRestultedMoney() const;
    NonPets( const std::string& name, const int cost, const int feed_time, const std::string& resulted_good, const int resulted_money);

    NonPets( const std::string& resulted_good, const int resulted_money);

    void interact(int& money) const override;
};




#endif //NONPETS_H
