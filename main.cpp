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
    std::vector<std::pair<std::string, int>> storedPlants;
public:
    explicit Silo(const std::vector<std::pair<std::string, int>> &stored_plants)
        : storedPlants(stored_plants) {
    }

    Silo();
    ~Silo() = default;
    Silo(const Silo &other)
        : storedPlants(other.storedPlants) {
    }
    Silo(Silo &&other) noexcept
        : storedPlants(std::move(other.storedPlants)) {
    }
    Silo & operator=(const Silo &other) {
        if (this == &other)
            return *this;
        storedPlants = other.storedPlants;
        return *this;
    }
    Silo & operator=(Silo &&other) noexcept {
        if (this == &other)
            return *this;
        storedPlants = std::move(other.storedPlants);
        return *this;
    }

    // Adaugă plante în Silo
    void storePlants( const std::string& plantName, int quantity) {
        for (size_t i = 0 ; i < storedPlants.size(); ++i) {
            if (storedPlants[i].first == plantName) {
                storedPlants[i].second += quantity;
                std::cout << quantity << " " << plantName << " adaugate in silo. \n";
                return;
            }
        }
        storedPlants.emplace_back(plantName, quantity);
        std::cout << quantity << " " << plantName << " adaugate in silo. \n";
    }
    void siloContent() const {
        std::cout<< "In silo ai: \n";
        for (size_t i = 0 ; i < storedPlants.size(); i++) {
            std::cout << "- " << storedPlants[i].first << " " << storedPlants[i].second << "\n";
        }
    }
};


class Barn {
    std::vector<std::pair<std::string, int>> storedItems;
public:
    explicit Barn(const std::vector<std::pair<std::string, int>> &stored_items)
        : storedItems(stored_items) {
    }

    Barn();
    ~Barn() = default;
    Barn(const Barn &other)
        : storedItems(other.storedItems) {
    }

    Barn(Barn &&other) noexcept
        : storedItems(std::move(other.storedItems)) {
    }

    Barn & operator=(const Barn &other) {
        if (this == &other)
            return *this;
        storedItems = other.storedItems;
        return *this;
    }

    Barn & operator=(Barn &&other) noexcept {
        if (this == &other)
            return *this;
        storedItems = std::move(other.storedItems);
        return *this;
    }

    void storeItems( const std::string& itemName, int quantity) {
        for (size_t i = 0 ; i < storedItems.size(); i++) {
            if (storedItems[i].first == itemName) {
                storedItems[i].second += quantity;
                std::cout << quantity << " " << itemName << " adaugate in barn. \n";
                return;
            }
        }
        storedItems.emplace_back(itemName, quantity);
        std::cout << quantity << " " << itemName << " adaugate in barn. \n";
    }

    void barnContent() const {
        std::cout<< "In barn ai: \n";
        for (size_t i = 0 ; i < storedItems.size(); i++) {
            std::cout << "- " << storedItems[i].first << " " << storedItems[i].second << "\n";
        }
    }
};

class Farm {
    Silo silo;
    Barn barn;
public:
    Farm(const Silo &silo, const Barn &barn)
        : silo(silo),
          barn(barn) {
    }
    explicit Farm(const Silo &silo)
        : silo(silo), barn() {
    }
    explicit Farm(const Barn &barn)
        : silo(), barn(barn) {
    }

    Farm(const Farm &other)
        : silo(other.silo),
          barn(other.barn) {
    }
    Farm(Farm &&other) noexcept
        : silo(std::move(other.silo)),
          barn(std::move(other.barn)) {
    }
    Farm & operator=(const Farm &other) {
        if (this == &other)
            return *this;
        silo = other.silo;
        barn = other.barn;
        return *this;
    }
    Farm & operator=(Farm &&other) noexcept {
        if (this == &other)
            return *this;
        silo = std::move(other.silo);
        barn = std::move(other.barn);
        return *this;
    }
    ~Farm() = default;


    void harvestPlant(const Plant& plant) {
        int count;
        std::cout << "Cate " << plant.getName() << " vrei sa plantezi?\n";
        std::cin >> count;
        if (count >= 1) {
            const int waitingTime = count * plant.getGrowTime();
            std:: cout << "Ai plantat " << count << " "  << plant.getName() << " ! Trebuie sa astepti "
                            << waitingTime << " secunde ca sa poti sa le culegi!\n";
            sleep(waitingTime);
            std:: cout << "Felicitari, ai cules " << count << " " << plant.getName() << "!\n";
            silo.storePlants(plant.getName(), count);
        }
        silo.siloContent();
    };

    void feedAnimal(Animal& animal) {
        std::string raspuns;
        std::string raspuns2;
        std::cout<<"Vrei sa hranesti " << animal.getName() <<"? (da/nu)\n";
        std::cin >> raspuns;
        if (animal.getName() == "Goat"){
            std:: cout<< "Cine este adevaratul " << animal.getName() << " ??????????????????????\n";
            std:: cout<< "Messi sau Ronaldo? \n" ;
            std:: cin >> raspuns2;
            if (raspuns2 == "Ronaldo" || raspuns2 == "RONALDO" || raspuns2 == "ronaldo"){
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
            barn.storeItems(animal.getResultedGood(), 1);
        }
        else {
            std::cout << animal.getName() << " nu a fost hranit!\n";
        }
        barn.barnContent();
    }

};

int main() {
    Silo mySilo;
    Barn myBarn;
    Farm myFarm(mySilo, myBarn);
    Animal Chicken("Kitchen", 20, 1, 2, "Aripioare picante"),
           Cow("Cow", 25, 5, 5, "Branza"),
           Pig("Pig", 35, 10, 7, "Sorici"),
           Sheep("Sheep", 40, 25, 12, "Ciubotele"),
           Goat("Goat", 70, 38, 15, "Baby Messi");
    Plant Wheat("Wheat", 2, 1, 2),
          Corn("Corn", 5, 3, 5),
          Bean("Soybeans", 10, 5, 10),
          Carrot("Carrot", 12, 10, 7);
    Machine Bakery("Bakery", 50, 1, 5, 20),
            FeedMill("FeedMill", 50, 1, 10, 50),
            Popcorn("PopcornPot", 100, 5, 30, 100),
            Oven("Oven", 150, 10, 60, 150),
            Grill("Grill", 200, 15, 120, 160);

    // myFarm.harvestPlant(Wheat);
    // myFarm.harvestPlant(Carrot);
    // myFarm.harvestPlant(Wheat);
    // myFarm.harvestPlant(Corn);
    // myFarm.harvestPlant(Carrot);
    // myFarm.harvestPlant(Bean);
    // myFarm.feedAnimal(Chicken);
    // myFarm.feedAnimal(Chicken);
    // myFarm.feedAnimal(Cow);
    // myFarm.feedAnimal(Pig);
    // myFarm.feedAnimal(Pig);
    // myFarm.feedAnimal(Chicken);
    // myFarm.feedAnimal(Goat);
    // myFarm.feedAnimal(Pig);
    // myFarm.feedAnimal(Chicken);



    // return 0;
}