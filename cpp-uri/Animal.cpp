//
// Created by sim on 5/26/2025.
//

#include "Animal.h"

const std::string & Animal::getName() const { return Name; }

int Animal::getCost() const { return Cost; }

int Animal::getFeedTime() const { return FeedTime; }

Animal::Animal(const Animal &other): Name{other.Name}, Cost{other.Cost},
                                     FeedTime{other.FeedTime} {
}

Animal & Animal::operator=(const Animal &other) {  Name = other.Name; Cost = other.Cost; FeedTime = other.FeedTime; return *this; }

Animal::Animal(const std::string &name, const int cost, const int feed_time): Name(name),
                                                                              Cost(cost),
                                                                              FeedTime(feed_time) {
}

Animal::~Animal() = default;
