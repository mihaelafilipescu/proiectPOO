#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <chrono>
#include <thread>

class Animal {
    std::string Name;
    int Cost;
    int LevelUnlock;
    int FeedTime;
    std::string ResultedGood;
    int Fed;

public:
    [[nodiscard]] const std::string& getName() const { return Name; };
    [[nodiscard]] int getCost() const { return Cost; };
    [[nodiscard]] int getFeedTime() const { return FeedTime; };
    [[nodiscard]] int getLevelUnlock() const { return LevelUnlock; };
    [[nodiscard]] const std::string& getResultedGood() const { return ResultedGood; };
    [[nodiscard]] int getFed() const { return Fed; };
    void setFed(const int Fed_) { Fed = Fed_; };
    explicit Animal(const int x) : Cost(0), LevelUnlock(0), FeedTime(0), Fed{x} {
    };
    Animal( std::string  Name_, const int Cost_, const int LevelUnlock_, const int FeedTime_, std::string  ResultedGood_) : Name{std::move(
            Name_
        )}, Cost{Cost_},
        LevelUnlock{LevelUnlock_}, FeedTime{FeedTime_}, ResultedGood{std::move(ResultedGood_)}, Fed(0) {
    };
    Animal(const Animal& other) : Name{other.Name}, Cost{other.Cost},
                                  LevelUnlock{other.LevelUnlock}, FeedTime{other.FeedTime},
                                  ResultedGood{other.ResultedGood}, Fed(0) {
    };

    ~Animal() = default;
};

class Plant {
    std::string Name;
    int Cost;
    int LevelUnlock;
    int GrowTime;
public:
    [[nodiscard]] const std::string& getName() const { return Name; };
    [[nodiscard]] int getCost() const { return Cost; };
    [[nodiscard]] int getLevelUnlock() const { return LevelUnlock; };
    [[nodiscard]] int getGrowTime() const { return GrowTime; };
    Plant(std::string  Name_, const int Cost_, const int LevelUnlock_, const int GrowTime_): Name{std::move(Name_)}, Cost{Cost_},
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
    [[nodiscard]] const std::string& getName() const { return Name; };
    [[nodiscard]] int getCost() const { return Cost; };
    [[nodiscard]] int getLevelUnlock() const { return LevelUnlock; };
    [[nodiscard]] int getBuildTime() const { return BuildTime; };
    [[nodiscard]] int getMaintenance() const { return Maintenance; };
    Machine(std::string  Name_, const int Cost_, const int LevelUnlock_, const int BuildTime_, const int Maintenance_) : Name{std::move(Name_)}, Cost{Cost_},
        LevelUnlock{LevelUnlock_}, BuildTime{BuildTime_}, Maintenance{Maintenance_}{};

    ~Machine() = default;
};

class Silo {
    std::vector<std::pair<std::string, int>> storedPlants;
public:
    explicit Silo(const std::vector<std::pair<std::string, int>> &stored_plants)
        : storedPlants(stored_plants) {
    }

    Silo() {};
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
        for (const auto & storedPlant : storedPlants) {
            std::cout << "- " << storedPlant.first << " " << storedPlant.second << "\n";
        }
    }
};


class Barn {
    std::vector<std::pair<std::string, int>> storedItems;
public:
    explicit Barn(const std::vector<std::pair<std::string, int>> &stored_items)
        : storedItems(stored_items) {
    }

    Barn() {};
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
    Farm(Silo silo, Barn barn)
        : silo(std::move(silo)),
          barn(std::move(barn)) {
    }
    explicit Farm(Silo silo)
        : silo(std::move(silo)), barn() {
    }
    explicit Farm(Barn barn)
        : silo(), barn(std::move(barn)) {
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
            int growTimeInSeconds = plant.getGrowTime();
            const std::chrono::seconds waitingTime(count * growTimeInSeconds);
            std:: cout << "Ai plantat " << count << " "  << plant.getName() << " ! Trebuie sa astepti "
                            << waitingTime << " secunde ca sa poti sa le culegi!\n";
            std::this_thread::sleep_for(waitingTime);
            std:: cout << "Felicitari, ai cules " << count << " " << plant.getName() << "!\n";
            silo.storePlants(plant.getName(), count);
        }
        silo.siloContent();
    };

    void feedAnimal(const Animal& animal) {
        std::string raspuns;
        std::cout<<"Vrei sa hranesti " << animal.getName() <<"? (da/nu)\n";
        std::cin >> raspuns;
        if (animal.getName() == "Goat"){
            std::string raspuns2;
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
            int feedTime = animal.getFeedTime();
            const std::chrono::seconds waitingTime(feedTime);
            std::cout << "Trebuie sa astepti " << animal.getFeedTime() << " secunde ca " << animal.getName() << " sa fie hranit!\n";
            std::this_thread::sleep_for(waitingTime);;
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

    myFarm.harvestPlant(Wheat);
    myFarm.harvestPlant(Carrot);
    myFarm.feedAnimal(Pig);
    myFarm.feedAnimal(Chicken);

    return 0;
}