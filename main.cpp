#include <iostream>
#include <string>
#include <ostream>
#include <indicators.hpp>
#include "Pets.h"
#include "NonPets.h"
#include "Rabbit.h"
#include "Plant.h"
#include "Weed.h"
#include "Machine.h"
#include "Silo.h"
#include "Barn.h"
#include "Farm.h"


int main() {
    Silo mySilo;
    Barn myBarn;
    Farm myFarm(mySilo, myBarn);
    NonPets Chicken("gainile", 20, 2, "Oua", 2),
           Cow("vacile", 25,  5, "Lapte", 5),
           Pig("porcii", 35,  7, "Bacon", 12),
           Sheep("oile", 40,  12, "Lana", 15),
           Goat("caprele", 70,  15, "Branza", 20);
    Pets Dog("caine", 100, 4, true),
         Cat("pisica", 150, 7, true);
    Rabbit rabbit{};
    Plant Wheat("grau", 2, 2, 1),
          Corn("porumb", 5, 5, 3),
          Bean("fasole", 10, 10, 7),
          Carrot("morcovi", 12, 7, 10);
    Weed Volbura("volbura", 0 , 0, 0, true, 15) /*e greu de scos, sufoca plantele*/,
         Dracila("dracila", 0 , 0, 0, false, 5)/*pot sa o manance oile, nu e otravitoare,cred ca e relativ usor de scos*/,
         Mohor("mohor", 0 , 0, 0, true, 20)/*e greu de scos ca seamana cu graul, e buruiana*/ ;
    Machine Bakery("Bakery", 50, 20, 400),
            FeedMill("FeedMill", 50, 25, 500),
            Popcorn("PopcornPot", 100, 30, 1000),
            Oven("Oven", 150, 35, 1500),
            Grill("Grill", 200, 40, 1600);
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
                        myFarm.harvestPlant(Wheat, Mohor);
                        break;
                    case 2:
                        myFarm.harvestPlant(Corn, Volbura);
                        break;
                    case 3:
                        myFarm.harvestPlant(Bean, Volbura);
                        break;
                    case 4:
                        myFarm.harvestPlant(Carrot, Volbura);
                        break;

                }break;
            case 2:
                std :: cout<< "Ce animale vrei sa hranesti?\n";
                std :: cout << "- gaini (1) \n" << "- vaci (2) \n" << "- porci (3) \n" << "- oi (4) \n" << "- capre (5) \n";
                std :: cin >> ans2;
                switch (ans2) {
                    case 1:
                        myFarm.feedAnimal(Chicken, rabbit);
                        break;
                    case 2:
                        myFarm.feedAnimal(Cow, rabbit);
                        break;
                    case 3:
                        myFarm.feedAnimal(Pig, rabbit);
                        break;
                    case 4:
                        myFarm.feedAnimal(Sheep, rabbit);
                        break;
                    case 5:
                        myFarm.feedAnimal(Goat, rabbit);
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


