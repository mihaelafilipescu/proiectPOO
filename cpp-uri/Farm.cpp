//
// Created by sim on 5/26/2025.
//

#include "../h-uri/Farm.h"
#include "../h-uri/Plant.h"
#include "../h-uri/Rabbit.h"
#include "../h-uri/NonPets.h"
#include "../h-uri/Weed.h"
#include "../h-uri/Machine.h"

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
                               barn(other.barn),
                               money(other.money),
                               ownedMachines(other.ownedMachines) {
}

Farm::Farm(Farm &&other) noexcept: silo(std::move(other.silo)),
                                   barn(std::move(other.barn)),
                                   money(other.money),
                                   ownedMachines(std::move(other.ownedMachines)) {
}

Farm & Farm::operator=(const Farm &other) {
    if (this == &other)
        return *this;
    silo = other.silo;
    barn = other.barn;
    money = other.money;
    ownedMachines = other.ownedMachines;
    return *this;
}

Farm & Farm::operator=(Farm &&other) noexcept {
    if (this == &other)
        return *this;
    silo = std::move(other.silo);
    barn = std::move(other.barn);
    money = std::move(other.money);
    ownedMachines = std::move(other.ownedMachines);
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
        progressBar(buildTime);
        // std::this_thread::sleep_for(waitingTime);;
        addMachine(machine);
        money = farm.getMoney() - machine.getCost();
        std:: cout<< "Ai cumparat " << machine.getName() << "!\n";
        std::cout << "Ai ramas cu " << money << " de bani!\n";
    }
    else {
        std:: cout<< "Nu ai destui bani pentru a cumpara " << machine.getName() << ".\n";
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


void Farm::addMachine(const Machine& machine) {
    ownedMachines.push_back(machine);
    std::cout << "Ai adaugat " << machine.getName() << " in ferma!\n";
}

void Farm::showOwnedMachines() const {
    if (ownedMachines.empty()) {
        std::cout << "Nu ai nicio masina in ferma!\n";
        return;
    }

    std::cout << "\n=== MASINILE TALE ===\n";
    for (size_t i = 0; i < ownedMachines.size(); ++i) {
        const auto& machine = ownedMachines[i];
        std::cout << i + 1 << ". " << machine.getName();
        if (machine.getIsWorking()) {
            std::cout << " (LUCREAZA)";
        }
        std::cout << "\n";
    }
    std::cout << "=====================\n";
}

void Farm::showMachineRecipes(const Machine& machine) const {
    const auto& recipes = machine.getRecipes();
    if (recipes.empty()) {
        std::cout << machine.getName() << " nu are retete disponibile!\n";
        return;
    }

    std::cout << "\n=== RETETE PENTRU " << machine.getName() << " ===\n";
    for (size_t i = 0; i < recipes.size(); ++i) {
        const auto& recipe = recipes[i];
        std::cout << i + 1 << ". " << recipe.productName << " (x" << recipe.productQuantity << ")\n";
        std::cout << "   Timp: " << recipe.productionTime << "s\n";
        std::cout << "   Ingrediente necesare:\n";

        for (const auto& ingredient : recipe.siloIngredients) {
            std::cout << "   - " << ingredient.first << ": " << ingredient.second << " kg (din silo)\n";
        }
        for (const auto& ingredient : recipe.barnIngredients) {
            std::cout << "   - " << ingredient.first << ": " << ingredient.second << " buc (din hambar)\n";
        }
        std::cout << "\n";
    }
    std::cout << "============================================\n";
}

bool Farm::checkIngredientsAvailable(const Recipe& recipe) const {
    // Verifica ingredientele din silo
    for (const auto& ingredient : recipe.siloIngredients) {
        if (!silo.hasEnough(ingredient.first, ingredient.second)) {
            return false;
        }
    }

    // Verifica ingredientele din hambar
    for (const auto& ingredient : recipe.barnIngredients) {
        if (!barn.hasEnough(ingredient.first, ingredient.second)) {
            return false;
        }
    }

    return true;
}

void Farm::consumeIngredients(const Recipe& recipe) {
    // Consuma ingredientele din silo
    for (const auto& ingredient : recipe.siloIngredients) {
        silo.removeItem(ingredient.first, ingredient.second);
        std::cout << "Consumi " << ingredient.second << " kg de " << ingredient.first << " din silo.\n";
    }

    // Consuma ingredientele din hambar
    for (const auto& ingredient : recipe.barnIngredients) {
        barn.removeItem(ingredient.first, ingredient.second);
        std::cout << "Consumi " << ingredient.second << " buc de " << ingredient.first << " din hambar.\n";
    }
}

void Farm::produceWithMachine(int machineIndex) {
    if (machineIndex < 0 || machineIndex >= static_cast<int>(ownedMachines.size())) {
        std::cout << "Masina selectata nu exista!\n";
        return;
    }

    Machine& machine = ownedMachines[machineIndex];

    if (machine.getIsWorking()) {
        std::cout << machine.getName() << " lucreaza deja! Asteapta sa termine.\n";
        return;
    }

    const auto& recipes = machine.getRecipes();
    if (recipes.empty()) {
        std::cout << machine.getName() << " nu are retete disponibile!\n";
        return;
    }

    std::cout << "\nAlege o reteta pentru " << machine.getName() << ":\n";
    for (size_t i = 0; i < recipes.size(); ++i) {
        std::cout << i + 1 << ". " << recipes[i].productName << " (x" << recipes[i].productQuantity << ")\n";
    }

    int recipeChoice;
    std::cout << "Alege reteta (1-" << recipes.size() << "): ";
    std::cin >> recipeChoice;

    if (recipeChoice < 1 || recipeChoice > static_cast<int>(recipes.size())) {
        std::cout << "Alegere invalida!\n";
        return;
    }

    const Recipe& selectedRecipe = recipes[recipeChoice - 1];

    std::cout << "\nVerific ingredientele...\n";
    if (!checkIngredientsAvailable(selectedRecipe)) {
        std::cout << "Nu ai destule ingrediente pentru aceasta reteta!\n";
        std::cout << "Ingrediente necesare:\n";
        for (const auto& ingredient : selectedRecipe.siloIngredients) {
            std::cout << "- " << ingredient.first << ": " << ingredient.second << " kg (din silo)\n";
        }
        for (const auto& ingredient : selectedRecipe.barnIngredients) {
            std::cout << "- " << ingredient.first << ": " << ingredient.second << " buc (din hambar)\n";
        }
        return;
    }

    std::cout << "Incepem productia de " << selectedRecipe.productName << "!\n";
    consumeIngredients(selectedRecipe);

    machine.setWorking(true);
    std::cout << "Masina " << machine.getName() << " lucreaza...\n";
    std::cout << "Timp de productie: " << selectedRecipe.productionTime << " secunde\n";

    // Foloseste progress bar-ul existent
    progressBar(selectedRecipe.productionTime);

    machine.setWorking(false);

    std::cout << "Productia s-a terminat!\n";
    std::cout << "Ai produs " << selectedRecipe.productQuantity << " x " << selectedRecipe.productName << "!\n";

    // Adauga produsul in silo (produsele procesate se pun in silo)
    silo.storePlants(selectedRecipe.productName, selectedRecipe.productQuantity);

    // Calculeaza banii castigati (produsele procesate valoreaza mai mult)
    int earnedMoney = selectedRecipe.productQuantity * 20; // 20 bani per produs procesat
    money += earnedMoney;
    std::cout << "Ai castigat " << earnedMoney << " bani din vanzarea produselor!\n";
    std::cout << "Acum ai " << money << " bani in total!\n";
}

void Farm::showProductionMenu() {
    while (true) {
        std::cout << "\n=== MENIU PRODUCTIE ===\n";
        std::cout << "1. Vezi masinile tale\n";
        std::cout << "2. Vezi retetele unei masini\n";
        std::cout << "3. Produce cu o masina\n";
        std::cout << "4. Cumpara masina noua\n";
        std::cout << "5. Vezi continutul fermei\n";
        std::cout << "6. Iesire din meniu\n";
        std::cout << "Alege optiunea: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                showOwnedMachines();
                break;

            case 2: {
                showOwnedMachines();
                if (!ownedMachines.empty()) {
                    int machineChoice;
                    std::cout << "Pentru care masina vrei sa vezi retetele? (1-" << ownedMachines.size() << "): ";
                    std::cin >> machineChoice;
                    if (machineChoice >= 1 && machineChoice <= static_cast<int>(ownedMachines.size())) {
                        showMachineRecipes(ownedMachines[machineChoice - 1]);
                    } else {
                        std::cout << "Alegere invalida!\n";
                    }
                }
                break;
            }

            case 3: {
                showOwnedMachines();
                if (!ownedMachines.empty()) {
                    int machineChoice;
                    std::cout << "Cu care masina vrei sa produci? (1-" << ownedMachines.size() << "): ";
                    std::cin >> machineChoice;
                    produceWithMachine(machineChoice - 1);
                }
                break;
            }

            case 4: {
                std::cout << "\n=== MAGAZIN MASINI ===\n";
                std::cout << "Ai " << money << " bani disponibili.\n\n";
                std::cout << "1. Moara (150 bani) - Produce faina din cereale\n";
                std::cout << "2. Brutarie (200 bani) - Produce paine si prajituri\n";
                std::cout << "3. Laptarie (180 bani) - Produce branza, unt, iaurt\n";
                std::cout << "4. Macelarie (220 bani) - Produce carnati si sunca\n";
                std::cout << "5. Distilerie (300 bani) - Produce bere si whiskey\n";
                std::cout << "6. Tesatorie (250 bani) - Produce tesaturi\n";
                std::cout << "0. Anuleaza cumpararea\n";
                std::cout << "Ce masina vrei sa cumperi? (0-6): ";

                int machineChoice;
                std::cin >> machineChoice;

                if (machineChoice == 0) {
                    std::cout << "Cumparare anulata.\n";
                    break;
                }

                Machine newMachine;
                bool validChoice = true;

                switch (machineChoice) {
                    case 1: newMachine = Machine::createFlourMill(); break;
                    case 2: newMachine = Machine::createBakery(); break;
                    case 3: newMachine = Machine::createDairy(); break;
                    case 4: newMachine = Machine::createButchery(); break;
                    case 5: newMachine = Machine::createBrewery(); break;
                    case 6: newMachine = Machine::createTextileMill(); break;
                    default:
                        std::cout << "Alegere invalida!\n";
                        validChoice = false;
                        break;
                }

                if (validChoice) {
                    if (money >= newMachine.getCost()) {
                        money -= newMachine.getCost();
                        addMachine(newMachine);
                        std::cout << "Ai cumparat " << newMachine.getName() << " cu " << newMachine.getCost() << " bani!\n";
                        std::cout << "Ai ramas cu " << money << " bani!\n";

                        // Arata progress bar pentru constructie
                        std::cout << "Se construieste masina...\n";
                        progressBar(newMachine.getBuildTime());
                        std::cout << newMachine.getName() << " a fost construita cu succes!\n";
                    } else {
                        std::cout << "Nu ai destui bani! Ai nevoie de " << newMachine.getCost() << " bani, dar ai doar " << money << ".\n";
                        std::cout << "Tip: Planteaza mai multe produse si hraneste animale pentru a castiga bani!\n";
                    }
                }
                break;
            }

            case 5:
                std::cout << *this;
                silo.siloContent();
                barn.barnContent();
                break;

            case 6:
                std::cout << "Iesire din meniul de productie.\n";
                return;

            default:
                std::cout << "Optiune invalida!\n";
                break;
        }
    }
}