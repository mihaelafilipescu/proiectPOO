//
// Created by sim on 5/26/2025.
//

#include "../h-uri/Farm.h"
#include "../h-uri/Plant.h"
#include "../h-uri/Rabbit.h"
#include "../h-uri/NonPets.h"
#include "../h-uri/Weed.h"

int Farm::getMoney() const { return money; }

Farm::Farm(int money): money(money) {
}

Farm::Farm(Silo silo, Barn barn): silo(std::move(silo)),
                                  barn(std::move(barn)) {
}

Farm::Farm(Silo silo): silo(std::move(silo)) {
}

Farm::Farm(Barn barn): barn(std::move(barn)) {
}

Farm::Farm(const Farm &other): silo(other.silo),
                               barn(other.barn) {
}

Farm::Farm(Farm &&other) noexcept: silo(std::move(other.silo)),
                                   barn(std::move(other.barn)) {
}

Farm & Farm::operator=(const Farm &other) {
    if (this == &other)
        return *this;
    silo = other.silo;
    barn = other.barn;
    money = other.money;
    return *this;
}

Farm & Farm::operator=(Farm &&other) noexcept {
    if (this == &other)
        return *this;
    silo = std::move(other.silo);
    barn = std::move(other.barn);
    money = std::move(other.money);
    return *this;
}

Farm::~Farm() {
}

void Farm::progressBar(int timp) {
    using namespace indicators;
    ProgressBar bar{
        option::BarWidth{50},
        option::Start{"["},
        option::Fill{"="},
        option::Lead{">"},
        option::Remainder{" "},
        option::End{"]"},
        option::ForegroundColor{Color::yellow},
        option::ShowPercentage{true},
        option::FontStyles{std::vector<FontStyle>{FontStyle::bold}}
    };
    // Update bar state
    while (true) {
        bar.tick();
        if (bar.is_completed())
            break;
        std::this_thread::sleep_for(std::chrono::milliseconds(timp*10));
    }

}

void Farm::harvestPlant(const Plant &plant, const Weed &weed) {
    int count;
    std::cout << "Cate kilograme de " << plant.getName() << " vrei sa plantezi?\n";
    std::cin >> count;
    if (count >= 1) {
        int growTimeInSeconds = plant.getGrowTime();
        const std::chrono::seconds waitingTime(count * growTimeInSeconds);
        std:: cout << "Ai plantat " << count << " kg de "  << plant.getName() << "! Trebuie sa astepti "
                << waitingTime << " secunde ca sa poti sa le culegi!\n";
        weed.getGrowTime();
        weed.removeWeeds(*this);
        // std::this_thread::sleep_for(waitingTime);
        progressBar(growTimeInSeconds);
        std:: cout << "Felicitari, ai cules " << count << " kg de " << plant.getName() << "!\n";
        silo.storePlants(plant.getName(), count);
        money += (plant.getResultedMoney()*count);
        std::cout << "Acum ai " << money << " de bani!\n";
    }
    silo.siloContent();
}

void Farm::feedAnimal(const NonPets &animal, Rabbit &rabbit) {
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
        rabbit.rabbitInterference(money);
        // std::this_thread::sleep_for(waitingTime);;
        progressBar(feedTime);
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

void Farm::buyMachine(const Machine &machine, const Farm &farm) {
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

void Farm::machineMaintenance(const Machine &machine, const Farm &farm) {
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

std::ostream & operator<<(std::ostream &os, const Farm &farm) {
    os << "In ferma ai: \n";
    os << "- " << farm.money << " bani \n";
    os << "- " << farm.silo << "\n";
    os << "- " << farm.barn << "\n";
    return os;
}

void Farm::decreaseMoney(int amount) {
    money -= amount;
}

