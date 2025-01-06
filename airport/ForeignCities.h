#pragma once
#include <iostream>        // Ketabkhane Voroody/Khoroojy
#include <string>  

class ForeignCities {
private:
    std::string cities[10];  // Araye Shahrhaye Khareji
    int cityCount = 0;       // Tedade Shahrhaye Khareji

public:
    void addCity(const std::string& city) {
        // Afzoudane Shahr be Araye Shahrhaye Khareji
        if (cityCount < 10) {
            cities[cityCount++] = city;
        }
        else {
            std::cerr << "Liste Shahrha por ast.\n";
        }
    }

    std::string getCities() const {
        // Daryaft Liste Shahrhaye Khareji
        std::string allCities;
        for (int i = 0; i < cityCount; ++i) {
            allCities += cities[i] + " ";
        }
        return allCities;
    }
};
