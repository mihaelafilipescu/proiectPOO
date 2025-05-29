#include <iostream>
#include <string>
#include <ostream>
#include <indicators.hpp>
#include "../h-uri/Animal.h"
#include "../h-uri/Pets.h"
#include "../h-uri/NonPets.h"
#include "../h-uri/Rabbit.h"
#include "../h-uri/Plant.h"
#include "../h-uri/Weed.h"
#include "../h-uri/Machine.h"
#include "../h-uri/Silo.h"
#include "../h-uri/Barn.h"
#include "../h-uri/Farm.h"


int main() {
    Silo mySilo;
    Barn myBarn;
    Farm myFarm(mySilo, myBarn);
    NonPets Chicken("gainile", 20, 2, "Oua", 2),
           Cow("vacile", 25,  5, "Lapte", 5),
           Pig("porcii", 35,  7, "Bacon", 12),
           Sheep("oile", 40,  12, "Lana", 15),
           Goat("caprele", 70,  15, "Branza", 20);
    Pets Dog("caine", 100, 4, false),
         Cat("pisica", 150, 7, false);
    Rabbit rabbit("iepurele", 30, 8, false, "Blana", 8);
    Plant Wheat("grau", 2, 2, 1),
          Corn("porumb", 5, 5, 3),
          Bean("fasole", 10, 10, 7),
          Carrot("morcovi", 12, 7, 10);
    Weed Volbura("volbura", 0 , 0, 0, 15) /*e greu de scos, sufoca plantele*/,
         Dracila("dracila", 0 , 0, 0, 5)/*pot sa o manance oile, nu e otravitoare,cred ca e relativ usor de scos*/,
         Mohor("mohor", 0 , 0, 0, 20)/*e greu de scos ca seamana cu graul, e buruiana*/ ;
    Machine Bakery("Bakery", 50, 20, 400),
            FeedMill("FeedMill", 50, 25, 500),
            Popcorn("PopcornPot", 100, 30, 1000),
            Oven("Oven", 150, 35, 1500),
            Grill("Grill", 200, 40, 1600);

    std :: cout << "Bine ai venit in ferma ta!\n" << "Ce doresti sa faci acum?\n";
    std :: cout << "- sa plantez recolta (1) \n" << "- sa hranesc animalele (2) \n" << "- sa interactionez cu animalele (3)\n" <<  "- sa construiesc o masinarie (4)\n" << "- sa repar o masinarie (5)\n";

    int ans1, ans2, ans3, ans4, ans5;
    std :: string continueGame;

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
                std::cout<< "Cu ce animal vrei sa interactionezi?\n";
                std::cout<< "=== ANIMALE DE COMPANIE ===\n";
                std::cout<< "- caine (1)\n" << "- pisica (2)\n";
                std::cout<< "=== ANIMALE DE FERMA ===\n";
                std::cout<< "- gaini (3)\n" << "- vaci (4)\n" << "- porci (5)\n" << "- oi (6)\n" << "- capre (7)\n";
                std::cout<< "=== ANIMALE SPECIALE ===\n";
                std::cout<< "- iepure (8)\n";

                std :: cin >> ans3;
                switch (ans3) {
                    case 1:
                        std::cout << "\n=== INTERACTIONEAZA CU CAINELE ===\n";
                        Dog.interact();
                        break;
                    case 2:
                        std::cout << "\n=== INTERACTIONEAZA CU PISICA ===\n";
                        Cat.interact();
                        break;
                    case 3:
                        std::cout << "\n=== INTERACTIONEAZA CU GAINILE ===\n";
                        Chicken.interact(myFarm, rabbit);
                        break;
                    case 4:
                        std::cout << "\n=== INTERACTIONEAZA CU VACILE ===\n";
                        Cow.interact(myFarm, rabbit);
                        break;
                    case 5:
                        std::cout << "\n=== INTERACTIONEAZA CU PORCII ===\n";
                        Pig.interact(myFarm, rabbit);
                        break;
                    case 6:
                        std::cout << "\n=== INTERACTIONEAZA CU OILE ===\n";
                        Sheep.interact(myFarm, rabbit);
                        break;
                    case 7:
                        std::cout << "\n=== INTERACTIONEAZA CU CAPRELE ===\n";
                        Goat.interact(myFarm, rabbit);
                        break;
                    case 8:
                        std::cout << "\n=== INTERACTIONEAZA CU IEPURELE ===\n";
                        rabbit.interact();
                        break;
                }
                break;

            case 4:
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

            case 5:
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

            default:
                std::cout << "Alegere invalida! Te rog sa alegi o optiune valida (1-5).\n";
                break;
        }

        std :: cout << "\n" << myFarm << "\n"; // Afișează statusul fermei
        std :: cout << "Doresti sa continui jocul? (da/nu)\n";
        std :: cin >> continueGame;
        if (continueGame == "Nu" || continueGame == "nu" || continueGame == "NU" || continueGame == "no" || continueGame == "NO")
            break;

        std:: cout << "\nCe doresti sa faci acum?\n" << "- sa plantez recolta (1) \n" << "- sa hranesc animalele (2) \n" << "- sa interactionez cu animalele (3)\n" << "- sa construiesc o masinarie (4)\n" << "- sa repar o masinarie (5)\n";
    }

    std::cout << "\nMultumesc ca ai jucat! La revedere!\n";
    return 0;
}