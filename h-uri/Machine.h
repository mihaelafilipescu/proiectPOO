//
// Created by sim on 5/26/2025.
//

#ifndef MACHINE_H
#define MACHINE_H
#include <string>
#include <vector>
#include <map>

struct Recipe {
    std::map<std::string, int> siloIngredients;  // ingredient -> quantity needed
    std::map<std::string, int> barnIngredients;  // ingredient -> quantity needed
    std::string productName;
    int productQuantity;
    int productionTime; // in seconds
};

class Machine {
    std::string Name;
    int Cost;
    int BuildTime;
    int Maintenance;
    std::vector<Recipe> recipes;
    bool isWorking;

public:
    Machine();
    [[nodiscard]] const std::string& getName() const;
    [[nodiscard]] int getCost() const;
    [[nodiscard]] int getBuildTime() const;
    [[nodiscard]] int getMaintenance() const;
    [[nodiscard]] bool getIsWorking() const;
    [[nodiscard]] const std::vector<Recipe>& getRecipes() const;

    Machine(std::string Name_, const int Cost_, const int BuildTime_, const int Maintenance_);
    Machine(std::string Name_, const int Cost_, const int BuildTime_, const int Maintenance_, std::vector<Recipe> recipes_);

    void setWorking(bool working);
    void addRecipe(const Recipe& recipe);

    // Static factory methods for specific machines
    static Machine createFlourMill();
    static Machine createBakery();
    static Machine createDairy();
    static Machine createButchery();
    static Machine createBrewery();
    static Machine createTextileMill();

    ~Machine();
};

#endif //MACHINE_H