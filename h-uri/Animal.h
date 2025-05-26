//
// Created by sim on 5/26/2025.
//

#ifndef ANIMAL_H
#define ANIMAL_H
#include <string>


class Animal {
    std::string Name;
    int Cost;
    int FeedTime;

public:
    // Animal() = default;
    [[nodiscard]] const std::string& getName() const;
    [[nodiscard]] int getCost() const;
    [[nodiscard]] int getFeedTime() const;

    Animal(const Animal& other);
    Animal& operator=(const Animal& other);
    Animal(const std::string &name = "", const int cost = 0, const int feed_time = 0);

    virtual ~Animal();
    // virtual void interact(int &money) const = 0;
};




#endif //ANIMAL_H
