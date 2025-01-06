#ifndef DOMESTICCITIES_H
#define DOMESTICCITIES_H

class DomesticCities {
private:
    std::string cities[10];  // Araye Shahrhaye Dakheli
    int cityCount = 0;       // Tedade Shahrhaye Dakheli

public:
    void addCity(const std::string& city) {
        // Afzoudane Shahr be Araye Shahrhaye Dakheli
        if (cityCount < 10) {
            cities[cityCount++] = city;
        }
        else {
            std::cerr << "Liste Shahrha por ast.\n";
        }
    }

    std::string getCities() const {
        // Daryaft Liste Shahrhaye Dakheli
        std::string allCities;
        for (int i = 0; i < cityCount; ++i) {
            allCities += cities[i] + " ";
        }
        return allCities;
    }
};

#endif // DOMESTICCITIES_H
