//
// Created by sim on 5/26/2025.
//

#include "../h-uri/Barn.h"

Barn::Barn(const std::vector<std::pair<std::string, int>> &stored_items): storedItems(stored_items) {
}

Barn::Barn() {}

Barn::~Barn() {
}

Barn::Barn(const Barn &other): storedItems(other.storedItems) {
}

Barn::Barn(Barn &&other) noexcept: storedItems(std::move(other.storedItems)) {
}

Barn & Barn::operator=(const Barn &other) {
    if (this == &other)
        return *this;
    storedItems = other.storedItems;
    return *this;
}

void Barn::storeItems(const std::string &itemName, int quantity) {
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

void Barn::barnContent() const {
    std::cout<< "In barn ai: \n";
    for (size_t i = 0 ; i < storedItems.size(); i++) {
        std::cout << "- " << storedItems[i].first << ": " << storedItems[i].second << "\n";
    }
}

std::ostream & operator<<(std::ostream &os, const Barn &barn) {
    for (const auto& stored_items : barn.storedItems) {
        os << stored_items.first << " " << stored_items.second << "\n";
    }
    return os;
}

// Functii noi pentru machine production
bool Barn::hasEnough(const std::string& itemName, int quantity) const {
    for (const auto& item : storedItems) {
        if (item.first == itemName) {
            return item.second >= quantity;
        }
    }
    return false;
}

void Barn::removeItem(const std::string& itemName, int quantity) {
    for (size_t i = 0; i < storedItems.size(); ++i) {
        if (storedItems[i].first == itemName) {
            if (storedItems[i].second >= quantity) {
                storedItems[i].second -= quantity;
                // Remove item completely if quantity becomes 0
                if (storedItems[i].second == 0) {
                    storedItems.erase(storedItems.begin() + i);
                }
                return;
            }
        }
    }
}

const std::vector<std::pair<std::string, int>>& Barn::getStoredItems() const {
    return storedItems;
}