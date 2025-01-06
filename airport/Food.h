#ifndef FOOD_H
#define FOOD_H

#include <iostream>
#include <string>

class Food {
private:
    std::string type; // Noe Ghaza 
    std::string meal; // Vade Ghazayi

public:
    void setType(const std::string& t) { type = t; }   // Tanzime Noe Ghaza
    std::string getType() const { return type; }       // Daryaft Noe Ghaza

    void setMeal(const std::string& m) { meal = m; }   // Tanzime Vade Ghazayi
    std::string getMeal() const { return meal; }       // Daryaft Vade Ghazayi

    // Operatorhaye Voroody va Khoroojy baraye Kelase Food
    friend std::ostream& operator<<(std::ostream& out, const Food& food) {
        out << food.type << ": " << food.meal;
        return out;
    }

    friend std::istream& operator>>(std::istream& in, Food& food) {
        in >> food.type >> food.meal;
        return in;
    }
};

#endif // FOOD_H
