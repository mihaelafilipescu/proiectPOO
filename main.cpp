#include <iostream>
#include <vector>
#include <string>
#include <chrono>

class Animal {
    std::string Name;
    int Cost;
    int LevelUnlock;
    int FeedTime;
    std::string ResultedGood;
    int Fed;
    std::chrono::steady_clock::time_point lastFedTime; // Momentul ultimei hrăniri

public:
    const std::string& getName() const { return Name; };
    int getCost() const { return Cost; };
    int getFeedTime() const { return FeedTime; };
    int getLevelUnlock() const { return LevelUnlock; };
    const std::string& getResultedGood() const { return ResultedGood; };
    int getFed() const { return Fed; };
    int setFed(int Fed_) { Fed = Fed_; };
    Animal(const int x) : Fed{x} {};
    Animal(const std::string& Name_, int Cost_, int LevelUnlock_, int FeedTime_, const std::string& ResultedGood_) : Name{Name_}, Cost{Cost_},
        LevelUnlock{LevelUnlock_}, FeedTime{FeedTime_}, ResultedGood{ResultedGood_} {};
    Animal(const Animal& other) : Name{other.Name}, Cost{other.Cost},
        LevelUnlock{other.LevelUnlock}, FeedTime{other.FeedTime}, ResultedGood{other.ResultedGood}{};

    ~Animal() = default;

    void feedAnimal(Animal& animal) {
        int intervalSec = animal.getFeedTime();
        std::string raspuns;
        std::string raspuns2;
        std::cout<<"Vrei sa hranesti " << animal.getName() <<"? (da/nu)\n";
        std::cin >> raspuns;
        if (animal.getFed() == 0 || canBeFed(intervalSec)){
            if (animal.getName() == "Goat"){
                std:: cout<< "Cine este adevaratul " << animal.getName() << " ??????????????????????\n";
                std:: cout<< "Messi sau Ronaldo? \n" ;
                std:: cin >> raspuns2;
                if (raspuns2 == "Ronaldo" || raspuns2 == "RONALDO"){
                    std::cout <<"Raspuns gresit! Nu poti hrani "<< animal.getName() << "\n";
                    raspuns = "nu";
                }
                else{
                    std:: cout<< "Raspuns corect!\n";
                }
            }
            if (raspuns == "DA" || raspuns == "da" || raspuns == "Da") {
                //baga operator de afisare;
                animal.setFed(1);
                lastFedTime = std::chrono::steady_clock::now();
                std::cout << animal.getName() <<" a fost hranit!\n";
            }
            else {
                std::cout << animal.getName() << " nu a fost hranit!\n";
            }
        }
         else{
             std:: cout<< animal.getName() << " a fost deja hranit!";
         }
    }

    bool canBeFed(int intervalSec) {
        auto now = std::chrono::steady_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(now - lastFedTime).count();
        return elapsed >= intervalSec;
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

    ~Plant() = default;
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

    ~Machine() = default;
};

class Silo {
    std::vector<Plant> Plants;
};
// class Barn {
//     std::vector<Plant> ResultedGood;
// };



int main() {
    Animal Chicken("Kitchen", 20, 1, 20, "Aripioare picante"),
           Cow("Cow", 25, 5, 60, "Brinza"),
           Pig("Pig", 35, 10, 90, "Sorici"),
           Sheep("Sheep", 40, 25, 360, "Ciubotele"),
           Goat("Goat", 70, 38, 480, "Baby Messi");
    Plant Wheat("Wheat", 2, 1, 2),
          Corn("Corn", 5, 3, 5),
          Bean("Soybeans", 10, 5, 20),
          Carrot("Carrot", 12, 10, 10);
    Machine Bakery("Bakery", 50, 1, 5, 20),
            FeedMill("FeedMill", 50, 1, 10, 50),
            Popcorn("PopcornPot", 100, 5, 30, 100),
            Oven("Oven", 150, 10, 60, 150),
            Grill("Grill", 200, 15, 120, 160);

    Goat.feedAnimal(Goat);


    return 0;
}