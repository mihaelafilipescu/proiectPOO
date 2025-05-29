//
// Created by sim on 5/26/2025.
//

#include "../h-uri/Machine.h"

Machine::Machine(): isWorking(false) {
}

const std::string & Machine::getName() const { return Name; }

int Machine::getCost() const { return Cost; }

int Machine::getBuildTime() const { return BuildTime; }

int Machine::getMaintenance() const { return Maintenance; }

bool Machine::getIsWorking() const { return isWorking; }

const std::vector<Recipe>& Machine::getRecipes() const { return recipes; }

Machine::Machine(std::string Name_, const int Cost_, const int BuildTime_, const int Maintenance_):
    Name{std::move(Name_)}, Cost{Cost_}, BuildTime{BuildTime_}, Maintenance{Maintenance_}, isWorking(false) {}

Machine::Machine(std::string Name_, const int Cost_, const int BuildTime_, const int Maintenance_, std::vector<Recipe> recipes_):
    Name{std::move(Name_)}, Cost{Cost_}, BuildTime{BuildTime_}, Maintenance{Maintenance_}, recipes{std::move(recipes_)}, isWorking(false) {}

void Machine::setWorking(bool working) {
    isWorking = working;
}

void Machine::addRecipe(const Recipe& recipe) {
    recipes.push_back(recipe);
}

Machine Machine::createFlourMill() {
    std::vector<Recipe> recipes;

    Recipe flourRecipe;
    flourRecipe.siloIngredients["grau"] = 2;
    flourRecipe.productName = "faina";
    flourRecipe.productQuantity = 3;
    flourRecipe.productionTime = 15;
    recipes.push_back(flourRecipe);

    Recipe cornFlourRecipe;
    cornFlourRecipe.siloIngredients["porumb"] = 2;
    cornFlourRecipe.productName = "faina_porumb";
    cornFlourRecipe.productQuantity = 2;
    cornFlourRecipe.productionTime = 12;
    recipes.push_back(cornFlourRecipe);

    return Machine("Moara", 150, 30, 25, recipes);
}

Machine Machine::createBakery() {
    std::vector<Recipe> recipes;

    Recipe breadRecipe;
    breadRecipe.siloIngredients["faina"] = 2;
    breadRecipe.barnIngredients["oua"] = 1;
    breadRecipe.productName = "paine";
    breadRecipe.productQuantity = 4;
    breadRecipe.productionTime = 25;
    recipes.push_back(breadRecipe);

    Recipe cakeRecipe;
    cakeRecipe.siloIngredients["faina"] = 1;
    cakeRecipe.barnIngredients["oua"] = 2;
    cakeRecipe.barnIngredients["lapte"] = 1;
    cakeRecipe.productName = "prajituri";
    cakeRecipe.productQuantity = 3;
    cakeRecipe.productionTime = 35;
    recipes.push_back(cakeRecipe);

    return Machine("Brutarie", 200, 45, 30, recipes);
}

Machine Machine::createDairy() {
    std::vector<Recipe> recipes;

    Recipe cheeseRecipe;
    cheeseRecipe.barnIngredients["lapte"] = 3;
    cheeseRecipe.productName = "branza";
    cheeseRecipe.productQuantity = 2;
    cheeseRecipe.productionTime = 40;
    recipes.push_back(cheeseRecipe);

    Recipe butterRecipe;
    butterRecipe.barnIngredients["lapte"] = 4;
    butterRecipe.productName = "unt";
    butterRecipe.productQuantity = 1;
    butterRecipe.productionTime = 30;
    recipes.push_back(butterRecipe);

    Recipe yogurtRecipe;
    yogurtRecipe.barnIngredients["lapte"] = 2;
    yogurtRecipe.productName = "iaurt";
    yogurtRecipe.productQuantity = 3;
    yogurtRecipe.productionTime = 20;
    recipes.push_back(yogurtRecipe);

    return Machine("Laptarie", 180, 40, 28, recipes);
}

Machine Machine::createButchery() {
    std::vector<Recipe> recipes;

    Recipe sausageRecipe;
    sausageRecipe.barnIngredients["carne"] = 3;
    sausageRecipe.productName = "carnati";
    sausageRecipe.productQuantity = 4;
    sausageRecipe.productionTime = 30;
    recipes.push_back(sausageRecipe);

    Recipe hamRecipe;
    hamRecipe.barnIngredients["carne"] = 4;
    hamRecipe.productName = "sunca";
    hamRecipe.productQuantity = 2;
    hamRecipe.productionTime = 50;
    recipes.push_back(hamRecipe);

    return Machine("Macelarie", 220, 35, 35, recipes);
}

Machine Machine::createBrewery() {
    std::vector<Recipe> recipes;

    Recipe beerRecipe;
    beerRecipe.siloIngredients["grau"] = 2;
    beerRecipe.siloIngredients["orz"] = 1;
    beerRecipe.productName = "bere";
    beerRecipe.productQuantity = 5;
    beerRecipe.productionTime = 45;
    recipes.push_back(beerRecipe);

    Recipe whiskeyRecipe;
    whiskeyRecipe.siloIngredients["porumb"] = 3;
    whiskeyRecipe.siloIngredients["orz"] = 2;
    whiskeyRecipe.productName = "whiskey";
    whiskeyRecipe.productQuantity = 2;
    whiskeyRecipe.productionTime = 60;
    recipes.push_back(whiskeyRecipe);

    return Machine("Distilerie", 300, 50, 45, recipes);
}

Machine Machine::createTextileMill() {
    std::vector<Recipe> recipes;

    Recipe cottonFabricRecipe;
    cottonFabricRecipe.siloIngredients["bumbac"] = 3;
    cottonFabricRecipe.productName = "tesaturi_bumbac";
    cottonFabricRecipe.productQuantity = 2;
    cottonFabricRecipe.productionTime = 35;
    recipes.push_back(cottonFabricRecipe);

    Recipe woolFabricRecipe;
    woolFabricRecipe.barnIngredients["lana"] = 2;
    woolFabricRecipe.productName = "tesaturi_lana";
    woolFabricRecipe.productQuantity = 3;
    woolFabricRecipe.productionTime = 40;
    recipes.push_back(woolFabricRecipe);

    return Machine("Tesatorie", 250, 42, 38, recipes);
}

Machine::~Machine() {
}