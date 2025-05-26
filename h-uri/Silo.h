//
// Created by sim on 5/26/2025.
//

#ifndef SILO_H
#define SILO_H
#include <iostream>
#include <string>
#include <vector>


class Silo {
    std::vector<std::pair<std::string, int>> storedPlants;
public:
    explicit Silo(const std::vector<std::pair<std::string, int>> &stored_plants);

    Silo();
    ~Silo();
    Silo(const Silo &other);

    Silo(Silo &&other) noexcept;

    Silo & operator=(const Silo &other);

    Silo & operator=(Silo &&other) noexcept;

    friend std::ostream& operator<<(std::ostream& os, const Silo& silo);

    void storePlants( const std::string& plantName, int quantity);

    void siloContent() const;
};




#endif //SILO_H
