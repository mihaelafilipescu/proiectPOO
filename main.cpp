#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <chrono>
#include <ostream>
// #include "ext/indicators.hpp"
// #include "ext/progress_bar.hpp"
// #include "ext/cursor_control.hpp"
#include <thread>


// class progressBar {
// public:
//     using namespace indicators;
//
//     indicators::ProgressBar bar{
//         indicators::option::BarWidth{50},
//         indicators::option::Start{" ["},
//         indicators::option::Fill{"█"},
//         indicators::option::Lead{"█"},
//         indicators::option::Remainder{"-"},
//         indicators::option::End{"]"},
//         indicators::option::PrefixText{"Training Gaze Network 👀"},
//         indicators::option::ForegroundColor{indicators::Color::yellow},
//         indicators::option::ShowElapsedTime{true},
//         indicators::option::ShowRemainingTime{true},
//         indicators::option::FontStyles{std::vector<indicators::FontStyle>{indicators::FontStyle::bold}}
//     };
//
//     while (true){
//         bar.tick();
//         if (bar.is_completed())
//             break;
//         std::this_thread::sleep_for(std::chrono::milliseconds(1000));
//     }
//
// };


class Animal {
    std::string Name;
    int Cost;
    int FeedTime;
    std::string ResultedGood;
    int resultedMoney;

public:
    [[nodiscard]] const std::string& getName() const { return Name; };
    [[nodiscard]] int getCost() const { return Cost; };
    [[nodiscard]] int getFeedTime() const { return FeedTime; };
    [[nodiscard]] const std::string& getResultedGood() const { return ResultedGood; };
    int getRestultedMoney() const { return resultedMoney; };
    explicit Animal() : Cost(0), FeedTime(0), resultedMoney(0) {
    };

    Animal(const Animal& other) : Name{other.Name}, Cost{other.Cost},
                                  FeedTime{other.FeedTime},
                                  ResultedGood{other.ResultedGood}, resultedMoney{other.resultedMoney} {
    };

    Animal(const std::string &name, int cost, int feed_time, const std::string &resulted_good, int restulted_money)
        : Name(name),
          Cost(cost),
          FeedTime(feed_time),
          ResultedGood(resulted_good),
          resultedMoney(restulted_money) {
    }

    ~Animal() = default;
};

class Plant {
    std::string Name;
    int Cost;
    int GrowTime;
    int resultedMoney;
public:
    [[nodiscard]] const std::string& getName() const { return Name; }

    [[nodiscard]] int getCost() const { return Cost; };
    [[nodiscard]] int getGrowTime() const { return GrowTime; };
    int getResultedMoney() const { return resultedMoney; };
    explicit Plant () : Name(""), Cost(0), GrowTime(0), resultedMoney(0) {}
    Plant(const std::string &name, int cost, int grow_time, int resulted_money)
        : Name(name),
          Cost(cost),
          GrowTime(grow_time),
          resultedMoney(resulted_money) {
    }

    ~Plant() = default;
};

class Machine {
    std::string Name;
    int Cost;
    int BuildTime;
    int Maintenance;
public:
    [[nodiscard]] const std::string& getName() const { return Name; };
    [[nodiscard]] int getCost() const { return Cost; };
    [[nodiscard]] int getBuildTime() const { return BuildTime; };
    [[nodiscard]] int getMaintenance() const { return Maintenance; };
    Machine(std::string  Name_, const int Cost_,  const int BuildTime_, const int Maintenance_) : Name{std::move(Name_)}, Cost{Cost_},
         BuildTime{BuildTime_}, Maintenance{Maintenance_}{};

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

    friend std::ostream& operator<<(std::ostream& os, const Silo& silo) {
        for (const auto& stored_plants : silo.storedPlants) {
            os << stored_plants.first << " " << stored_plants.second << " ";
        }
        return os;
    };

    // Adaugă plante în Silo
    void storePlants( const std::string& plantName, int quantity) {
        for (size_t i = 0 ; i < storedPlants.size(); ++i) {
            if (storedPlants[i].first == plantName) {
                storedPlants[i].second += quantity;
                // std::cout << quantity << " " << plantName << " adaugate in silo. \n";
                return;
            }
        }
        storedPlants.emplace_back(plantName, quantity);
        // std::cout << quantity << " " << plantName << " adaugate in silo. \n";
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


    friend std::ostream& operator<<(std::ostream& os, const Barn& barn) {
        for (const auto& stored_items : barn.storedItems) {
            os << stored_items.first << " " << stored_items.second << "\n";
        }
        return os;
    };

    void storeItems( const std::string& itemName, int quantity) {
        for (size_t i = 0 ; i < storedItems.size(); i++) {
            if (storedItems[i].first == itemName) {
                storedItems[i].second += quantity;
                // std::cout << quantity << " " << itemName << " adaugate in barn. \n";
                return;
            }
        }
        storedItems.emplace_back(itemName, quantity);
        // std::cout << quantity << " " << itemName << " adaugate in barn. \n";
    }

    void barnContent() const {
        std::cout<< "In barn ai: \n";
        for (size_t i = 0 ; i < storedItems.size(); i++) {
            std::cout << "- " << storedItems[i].first << ": " << storedItems[i].second << "\n";
        }
    }
};

class Farm {
    int money = 50;
    Silo silo;
    Barn barn;
public:
    int getMoney () const { return money; }

    explicit Farm(int money)
        : money(money) {
    }

    Farm(Silo silo, Barn barn)
        : silo(std::move(silo)),
          barn(std::move(barn)) {
    }
    explicit Farm(Silo silo)
        : silo(std::move(silo)) {
    }
    explicit Farm(Barn barn)
        : barn(std::move(barn)) {
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

    friend std::ostream& operator<<(std::ostream& os, const Farm& farm) {
        os << "In ferma ai: \n";
        os << "- " << farm.money << " bani \n";
        os << "- " << farm.silo << "\n";
        os << "- " << farm.barn << "\n";
        return os;
    }


    void harvestPlant(const Plant& plant) {
        int count;
        std::cout << "Cate kilograme de " << plant.getName() << " vrei sa plantezi?\n";
        std::cin >> count;
        if (count >= 1) {
            int growTimeInSeconds = plant.getGrowTime();
            const std::chrono::seconds waitingTime(count * growTimeInSeconds);
            std:: cout << "Ai plantat " << count << " kg de "  << plant.getName() << "! Trebuie sa astepti "
                            << waitingTime << " secunde ca sa poti sa le culegi!\n";
            std::this_thread::sleep_for(waitingTime);
            std:: cout << "Felicitari, ai cules " << count << " kg de " << plant.getName() << "!\n";
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

            std:: cout<< "Cine este adevaratul " << animal.getName() << "??????????????????????\n";
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
            std::cout << "Trebuie sa astepti " << animal.getFeedTime() << " secunde ca " << animal.getName() << " sa fie hranite!\n";
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

    void buyMachine(const Machine &machine, const Farm &farm) {
        std::cout << "Ai nevoie de " << machine.getCost() << " bani ca sa cumperi " << machine.getName() << ".\n";
        std::cout << "Acum ai " << farm.getMoney() << " de bani!\n";
        if (farm.getMoney() >= machine.getCost()) {
            const int buildTime = machine.getBuildTime();
            const std::chrono::seconds waitingTime(buildTime);
            std:: cout<< "Trebuie sa astepti " << machine.getBuildTime() << "s pentru a se contrui!\n";
            std::this_thread::sleep_for(waitingTime);;
            money = farm.getMoney() - machine.getCost();
            std:: cout<< "Ai cumparat " << machine.getName() << "!\n";
            std::cout << "Ai ramas cu " << money << " de bani!\n";
        }
        else {
            std:: cout<< "Nu ai destui bani pentru a cumpara " << machine.getName() << ".\n";
            std:: cout<< "Tip! : planteaza produse si hraneste animale pentru a castiga bani!\n";
        }
    }

    void machineMaintenance(const Machine &machine, const Farm &farm) {
        std::cout << "Ai nevoie de " << machine.getMaintenance() << " bani ca sa repari " << machine.getName() << ".\n";
        std::cout << "Acum ai " << farm.getMoney() << " de bani!\n";
        if (farm.getMoney() >= machine.getCost()) {
            const int buildTime = machine.getBuildTime();
            const std::chrono::seconds waitingTime(buildTime);
            std:: cout<< "Trebuie sa astepti " << machine.getBuildTime() << "s pentru a se repara!\n";
            std::this_thread::sleep_for(waitingTime);;
            money = farm.getMoney() - machine.getMaintenance();
            std:: cout<< "Ai reparat " << machine.getName() << "!\n";
            std::cout << "Ai ramas cu " << money << " de bani!\n";
        }
        else {
            std:: cout<< "Nu ai destui bani pentru a repara " << machine.getName() << ".\n";
            std:: cout<< "Tip! : planteaza produse si hraneste animale pentru a castiga bani!\n";
        }
    }

};




int main() {
    Silo mySilo;
    Barn myBarn;
    Farm myFarm(mySilo, myBarn);
    // std :: cout<< myFarm;
    Animal Chicken("gainile", 20, 2, "Oua", 2),
           Cow("vacile", 25,  5, "Lapte", 5),
           Pig("porcii", 35,  7, "Bacon", 12),
           Sheep("oile", 40,  12, "Lana", 15),
           Goat("caprele", 70,  15, "Branza", 20);
    Plant Wheat("grau", 2, 2, 1),
          Corn("porumb", 5, 5, 3),
          Bean("fasole", 10, 10, 7),
          Carrot("morcovi", 12, 7, 10);
    Machine Bakery("Bakery", 50,  5, 400),
            FeedMill("FeedMill", 50,  10, 500),
            Popcorn("PopcornPot", 100,  30, 1000),
            Oven("Oven", 150,  60, 1500),
            Grill("Grill", 200,  120, 1600);
    std :: cout << "Bine ai venit in ferma ta!\n" << "Ce doresti sa faci acum?\n";
    std :: cout << "- sa plantez recolta (1) \n" << "- sa hranesc animalele (2) \n" << "- sa construiesc o masinarie (3)\n" << "- sa repar o masinarie (4)\n";
    int ans1, ans2, ans4, ans5;
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
            case 3:
                std::cout << "Ce masinarie doresti sa-ti cumperi?\n";
                std::cout << "- brutarie (1)\n" << "- cuptor (2)\n" << "- masina de popcorn (3)\n" << "- gratar (4)\n";
                std :: cin >> ans4;
                switch (ans4) {
                    case 1:
                        myFarm.buyMachine(Bakery, myFarm);
                        break;
                    case 2:
                        myFarm.buyMachine(Oven, myFarm);
                        break;
                    case 3:
                        myFarm.buyMachine(Popcorn, myFarm);
                        break;
                    case 4:
                        myFarm.buyMachine(Grill, myFarm);
                        break;
                }break;
            case 4:
                std::cout << "Ce masinarie doresti sa repari?\n";
            std::cout << "- brutarie (1)\n" << "- cuptor (2)\n" << "- masina de popcorn (3)\n" << "- gratar (4)\n";
            std :: cin >> ans5;
            switch (ans5) {
                case 1:
                    myFarm.machineMaintenance(Bakery, myFarm);
                    break;
                case 2:
                    myFarm.machineMaintenance(Oven, myFarm);
                    break;
                case 3:
                    myFarm.machineMaintenance(Popcorn, myFarm);
                    break;
                case 4:
                    myFarm.machineMaintenance(Grill, myFarm);
                    break;
            }break;
        }
        std :: cout << "Doresti sa continui jocul?\n";
        std :: cin >> ans3;
        if (ans3 == "Nu" || ans3 == "nu" || ans3 == "NU") break;
        std:: cout << "Ce doresti sa faci acum?\n" << "- sa plantez recolta (1) \n" << "- sa hranesc animalele (2) \n" << "- sa construiesc o masinarie (3)\n" << "- sa repar o masinarie (4)\n";
    }
    return 0;
}


