#include <iostream>
#include <vector>
#include <string>

class Animal {
    std::string Name;
    int Cost;
    int LevelUnlock;
    int FeedTime;
    std::string ResultedGood;
    std::string Fed;

public:
    const std::string& getName() const { return Name; };
    int getCost() const { return Cost; };
    int getFeedTime() const { return FeedTime; };
    int getLevelUnlock() const { return LevelUnlock; };
    const std::string& getResultedGood() const { return ResultedGood; };
    const std::string& getFed() const { return Fed; };
    Animal(const std::string& x) : Fed{x} {};
    Animal(const std::string& Name_, int Cost_, int LevelUnlock_, int FeedTime_, const std::string& ResultedGood_) : Name{Name_}, Cost{Cost_},
        LevelUnlock{LevelUnlock_}, FeedTime{FeedTime_}, ResultedGood{ResultedGood_} {};
    Animal(const Animal& other) : Name{other.Name}, Cost{other.Cost},
        LevelUnlock{other.LevelUnlock}, FeedTime{other.FeedTime}, ResultedGood{other.ResultedGood}{};

    ~Animal() = default;


    void feedAnimal(Animal& animal) {
        std::string raspuns;
        std::cout<<"Vrei sa hranesti" << animal.getName() <<"? (da/nu)\n";
        std::cin >> raspuns;
        if (raspuns == "DA" || raspuns == "da" || raspuns == "Da") {
            Animal animal{"true" };
            std::cout << animal.getName() <<" a fost hranit!\n";
        } else {
            std::cout << animal.getName() << " nu a fost hrănit!\n";
        }
    }

};

class Plant {
    std::string Name;
    int Cost;
    int LevelUnlock;
    int GrowTime;
public:
    const std::string& getName() const { return Name; };
    int getCost() const { return Cost; };
    int getLevelUnlock() const { return LevelUnlock; };
    int getGrowTime() const { return GrowTime; };
    Plant(const std::string& Name_, int Cost_, int LevelUnlock_, int GrowTime_): Name{Name_}, Cost{Cost_},
        LevelUnlock{LevelUnlock_}, GrowTime{GrowTime_}{};
};

class Machine {
    std::string Name;
    int Cost;
    int LevelUnlock;
    int BuildTime;
    int Maintenance;
public:
    const std::string& getName() const { return Name; };
    int getCost() const { return Cost; };
    int getLevelUnlock() const { return LevelUnlock; };
    int getBuildTime() const { return BuildTime; };
    int getMaintenance() const { return Maintenance; };
    Machine(const std::string& Name_, int Cost_, int LevelUnlock_, int BuildTime_, int Maintenance_) : Name{Name_}, Cost{Cost_},
        LevelUnlock{LevelUnlock_}, BuildTime{BuildTime_}, Maintenance{Maintenance_}{};
};

class Silo {
    std::vector<Plant> Plants;
};
// class Barn {
//     std::vector<Plant> ResultedGood;
// };



int main() {
    Animal Chicken("Chicken", 20, 1, 20, "Egg"),
           Cow("Cow", 25, 5, 60, "Milk"),
           Pig("Pig", 35, 10, 90, "Bacon"),
           Sheep("Sheep", 40, 25, 360, "Wool"),
           Goat("Goat", 70, 38, 480, "Goat Milk");
    Plant Wheat("Wheat", 2, 1, 2),
          Corn("Corn", 5, 3, 5),
          Bean("Soybeans", 10, 5, 20),
          Carrot("Carrot", 12, 10, 10);
    Machine Bakery("Bakery", 50, 1, 5, 20),
            FeedMill("FeedMill", 50, 1, 10, 50),
            Popcorn("PopcornPot", 100, 5, 30, 100),
            Oven("Oven", 150, 10, 60, 150),
            Grill("Grill", 200, 15, 120, 160);

    return 0;
}