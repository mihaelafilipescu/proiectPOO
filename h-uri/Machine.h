//
// Created by sim on 5/26/2025.
//

#ifndef MACHINE_H
#define MACHINE_H
#include <string>


class Machine {
    std::string Name;
    int Cost;
    int BuildTime;
    int Maintenance;
public:
    Machine();
    [[nodiscard]] const std::string& getName() const;
    [[nodiscard]] int getCost() const;;
    [[nodiscard]] int getBuildTime() const;;
    [[nodiscard]] int getMaintenance() const;;
    Machine(std::string  Name_, const int Cost_,  const int BuildTime_, const int Maintenance_);

    ~Machine();

};




#endif //MACHINE_H
