#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <unistd.h>

class Animal {
    std::string Name;
    int Cost;
    int LevelUnlock;
    int FeedTime;
    std::string ResultedGood;
    int Fed;

public:
    const std::string& getName() const { return Name; };
    int getCost() const { return Cost; };
    int getFeedTime() const { return FeedTime; };
    int getLevelUnlock() const { return LevelUnlock; };
    const std::string& getResultedGood() const { return ResultedGood; };
    int getFed() { return Fed; };
    void setFed( int Fed_) { Fed = Fed_; };
    Animal(const int x) : Fed{x} {};
    Animal( const std::string& Name_, int Cost_, int LevelUnlock_, int FeedTime_, const std::string& ResultedGood_) : Name{Name_}, Cost{Cost_},
        LevelUnlock{LevelUnlock_}, FeedTime{FeedTime_}, ResultedGood{ResultedGood_} {};
    Animal(const Animal& other) : Name{other.Name}, Cost{other.Cost},
        LevelUnlock{other.LevelUnlock}, FeedTime{other.FeedTime}, ResultedGood{other.ResultedGood}{};

    ~Animal() = default;

    void feedAnimal(Animal& animal) {
        std::string raspuns;
        std::string raspuns2;
        std::cout<<"Vrei sa hranesti " << animal.getName() <<"? (da/nu)\n";
        std::cin >> raspuns;
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
            std::cout << "Trebuie sa astepti " << animal.getFeedTime() << " secunde ca " << animal.getName() << " sa fie hranit!\n";
            sleep(animal.getFeedTime());
            std::cout << "Felicitari, ai primit " << animal.getResultedGood() << " pentru ca ai hranit " << animal.getName() << "!\n";
        }
        else {
            std::cout << animal.getName() << " nu a fost hranit!\n";
        }
    }
};

class Silo;

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

   void harvestPlant(Plant& plant) {
       int count;
       int waitingTime;
       std::cout << "Cate " << plant.getName() << " vrei sa plantezi?\n";
       std::cin >> count;
       if (count >= 1) {
            waitingTime = count * plant.getGrowTime();
            std:: cout << "Ai plantat " << count << " "  << plant.getName() << " ! Trebuie sa astepti "
                            << waitingTime << " secunde ca sa poti sa le culegi!\n";
            sleep(waitingTime);
            std:: cout << "Felicitari, ai cules " << count << " " << plant.getName() << "!\n";
            // storePlant( plant.getName, count )
       }
    };
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

// class Silo {
//     std::vector<Plant> Plants;
// public:
//     // Adaugă plante în Silo
//     void storePlant(const std::string& plantName, int quantity) {
//         Plants[plantName] += quantity;
//         std::cout << quantity << " " << plantName << " adăugate în silo.\n";
//     }
// };


class Barn {
    std::vector<Plant> ResultedGood;
};



int main() {
    Animal Chicken("Kitchen", 20, 1, 2, "Aripioare picante"),
           Cow("Cow", 25, 5, 5, "Brinza"),
           Pig("Pig", 35, 10, 7, "Sorici"),
           Sheep("Sheep", 40, 25, 12, "Ciubotele"),
           Goat("Goat", 70, 38, 15, "Baby Messi");
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
    // Wheat.harvestPlant(Wheat);


    return 0;
}