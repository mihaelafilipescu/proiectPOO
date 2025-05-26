//
// Created by sim on 5/26/2025.
//

#ifndef BARN_H
#define BARN_H
#include <iostream>
#include <string>
#include <vector>

class Barn {
    std::vector<std::pair<std::string, int>> storedItems;
public:
    explicit Barn(const std::vector<std::pair<std::string, int>> &stored_items);

    Barn();
    ~Barn();
    Barn(const Barn &other);

    Barn(Barn &&other) noexcept;

    Barn & operator=(const Barn &other);


    friend std::ostream& operator<<(std::ostream& os, const Barn& barn);

    void storeItems( const std::string& itemName, int quantity);

    void barnContent() const;
};




#endif //BARN_H
