#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <chrono>
#include <ostream>
#include <thread>

class Animal {
    std::string Name;
    int Cost;
    int LevelUnlock;
    int FeedTime;
    std::string ResultedGood;
    int resultedMoney;

public:
    [[nodiscard]] const std::string& getName() const { return Name; };
    [[nodiscard]] int getCost() const { return Cost; };
    [[nodiscard]] int getFeedTime() const { return FeedTime; };
    [[nodiscard]] int getLevelUnlock() const { return LevelUnlock; };
    [[nodiscard]] const std::string& getResultedGood() const { return ResultedGood; };
    int getRestultedMoney() const { return resultedMoney; };
    explicit Animal() : Cost(0), LevelUnlock(0), FeedTime(0), resultedMoney(0) {
    };
    Animal( std::string  Name_, const int Cost_, const int LevelUnlock_, const int FeedTime_, std::string  ResultedGood_) : Name{std::move(
            Name_
        )}, Cost{Cost_},
        LevelUnlock{LevelUnlock_}, FeedTime{FeedTime_}, ResultedGood{std::move(ResultedGood_)} {
    };
    Animal(const Animal& other) : Name{other.Name}, Cost{other.Cost},
                                  LevelUnlock{other.LevelUnlock}, FeedTime{other.FeedTime},
                                  ResultedGood{other.ResultedGood}, resultedMoney{other.resultedMoney} {
    };

    Animal(const std::string &name, int cost, int level_unlock, int feed_time, const std::string &resulted_good, int restulted_money)
        : Name(name),
          Cost(cost),
          LevelUnlock(level_unlock),
          FeedTime(feed_time),
          ResultedGood(resulted_good),
          resultedMoney(restulted_money) {
    }

    ~Animal() = default;
};

class Plant {
    std::string Name;
    int Cost;
    int LevelUnlock;
    int GrowTime;
    int resultedMoney;
public:
    [[nodiscard]] const std::string& getName() const { return Name; }

    [[nodiscard]] int getCost() const { return Cost; };
    [[nodiscard]] int getLevelUnlock() const { return LevelUnlock; };
    [[nodiscard]] int getGrowTime() const { return GrowTime; };
    int getResultedMoney() const { return resultedMoney; };
    explicit Plant () : Name(""), Cost(0), LevelUnlock(0), GrowTime(0), resultedMoney(0) {}
    Plant(const std::string &name, int cost, int level_unlock, int grow_time, int resulted_money)
        : Name(name),
          Cost(cost),
          LevelUnlock(level_unlock),
          GrowTime(grow_time),
          resultedMoney(resulted_money) {
    }

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
    int money = 50;
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
        money = other.money;
        return *this;
    }
    Farm & operator=(Farm &&other) noexcept {
        if (this == &other)
            return *this;
        silo = std::move(other.silo);
        barn = std::move(other.barn);
        money = std::move(other.money);
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
            money += (plant.getResultedMoney()*count);
            std::cout << "Acum ai " << money << " de bani!\n";
        }
        silo.siloContent();
    };

    void feedAnimal(const Animal& animal) {
        std::string raspuns;
        std::cout<<"Vrei sa hranesti " << animal.getName() <<"? (da/nu)\n";
        std::cin >> raspuns;
        if (animal.getName() == "capre"){
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
            const int feedTime = animal.getFeedTime();
            const std::chrono::seconds waitingTime(feedTime);
            std::cout << "Trebuie sa astepti " << animal.getFeedTime() << " secunde ca " << animal.getName() << " sa fie hranit!\n";
            std::this_thread::sleep_for(waitingTime);;
            std::cout << "Felicitari, ai primit " << animal.getResultedGood() << " pentru ca ai hranit " << animal.getName() << "!\n";
            barn.storeItems(animal.getResultedGood(), 1);
            money += animal.getRestultedMoney();
            std::cout << "Acum ai " << money << " de bani!\n";
        }
        else {
            std::cout << animal.getName() << " nu a fost hranit!\n";
        }
        barn.barnContent();
    }

    // void Bakery (const Machine& bakery) {
    //     int raspuns;
    //     std :: cout << "Ce iti doresti sa prepari in bakery?\n";
    //     std :: cout << "- paine (1)\n" << "- mamaliga (2)\n" << "- briose cu zmeura (3)\n" << "- briose cu mure (4)\n";
    //     switch (raspuns) {
    //         case 1:
    //         case 2:
    //         case 3:
    //         case 4:
    //     }
    // }

};

int main() {
    Silo mySilo;
    Barn myBarn;
    Farm myFarm(mySilo, myBarn);
    Animal Chicken("gaini", 20, 1, 2, "Oua", 2),
           Cow("vaci", 25, 5, 5, "Lapte", 5),
           Pig("porci", 35, 10, 7, "Bacon", 12),
           Sheep("oi", 40, 25, 12, "Lana", 15),
           Goat("capre", 70, 38, 15, "Branza", 20);
    Plant Wheat("grau", 2, 1, 2, 1),
          Corn("porumb", 5, 3, 5, 3),
          Bean("fasole", 10, 5, 10, 7),
          Carrot("morcovi", 12, 10, 7, 10);
    Machine Bakery("Bakery", 50, 1, 5, 20),
            FeedMill("FeedMill", 50, 1, 10, 50),
            Popcorn("PopcornPot", 100, 5, 30, 100),
            Oven("Oven", 150, 10, 60, 150),
            Grill("Grill", 200, 15, 120, 160);
    std :: cout << "Bine ai venit in feram ta!\n" << "Ce doresti sa faci acum?\n";
    std :: cout << "- sa plantez recolta (1) \n" << "- sa hranesc animalele (2) \n";
    int ans1, ans2;
    std :: string ans3;
    while (true) {
        std :: cin >> ans1;
        switch (ans1) {
            case 1:
                std :: cout<< "Ce vrei sa plantezi?\n";
                std :: cout << "- grau (1) \n" << "- porumb (2) \n" << "- fasole (3) \n" << "- morcovi (4) \n";
                std :: cin >> ans2;
                switch (ans2) {
                    case 1:
                        myFarm.harvestPlant(Wheat);
                        break;
                    case 2:
                        myFarm.harvestPlant(Corn);
                        break;
                    case 3:
                        myFarm.harvestPlant(Bean);
                        break;
                    case 4:
                        myFarm.harvestPlant(Carrot);
                        break;

                }break;
            case 2:
                std :: cout<< "Ce animale vrei sa hranesti?\n";
                std :: cout << "- gaini (1) \n" << "- vaci (2) \n" << "- porci (3) \n" << "- oi (4) \n" << "- capre (5) \n";
                std :: cin >> ans2;
                switch (ans2) {
                    case 1:
                        myFarm.feedAnimal(Chicken);
                        break;
                    case 2:
                        myFarm.feedAnimal(Cow);
                        break;
                    case 3:
                        myFarm.feedAnimal(Pig);
                        break;
                    case 4:
                        myFarm.feedAnimal(Sheep);
                        break;
                    case 5:
                        myFarm.feedAnimal(Goat);
                        break;
                }break;
        }
        std :: cout << "Doresti sa continui jocul?\n";
        std :: cin >> ans3;
        if (ans3 == "Nu" || ans3 == "nu" || ans3 == "NU") break;
        std:: cout << "Ce doresti sa faci acum?\n" << "- sa plantez recolta (1) \n" << "- sa hranesc animalele (2) \n";
    }
    return 0;
}


