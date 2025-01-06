#ifndef AIRPORT_H
#define AIRPORT_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Date.h"
#include "Food.h"
#include "Tax.h" // اضافه کردن کلاس Tax

class Airport {
public:
    struct Flight {
        std::string flightID;
        std::string flightType;
        std::string originCity;
        std::string destinationCity;
        Date flightDate;
        std::string planeName;
        bool isCancelled;
        double price;
        double tax;
        Food food;

        double getPriceWithTax() const {
            Tax taxCalculator;
            return taxCalculator.calculateTax(price, tax);
        }
    };

private:
    std::vector<Flight> flights;

public:
    void addFlight(const Flight& flight) {
        flights.push_back(flight);
    }

    void removeFlight(const std::string& flightID) {
        flights.erase(std::remove_if(flights.begin(), flights.end(), [&](const Flight& f) {
            return f.flightID == flightID;
            }), flights.end());
    }

    void displayFlights() const {
        std::cout << "Parvazhaye mojoud:" << std::endl;
        for (const auto& flight : flights) {
            std::cout << flight.flightID << " " << flight.flightType << " " << flight.originCity << " "
                << flight.destinationCity << " " << flight.flightDate << " " << flight.planeName << " "
                << (flight.isCancelled ? "Laghv Shodeh" : "Laghv Nashodeh") << " "
                << "Gheymat: " << flight.getPriceWithTax() << " "
                << "Maliat: " << flight.tax << " "
                << "Ghaza: " << flight.food.getType() << " "
                << "Vade Ghazayi: " << flight.food.getMeal() << std::endl;
        }
    }

    void saveFlightsToFile(const std::string& filename) const {
        std::ofstream file(filename);
        if (file.is_open()) {
            for (const auto& flight : flights) {
                file << "flightID=" << flight.flightID << "\n"
                    << "flightType=" << flight.flightType << "\n"
                    << "originCity=" << flight.originCity << "\n"
                    << "destinationCity=" << flight.destinationCity << "\n"
                    << "flightDate=" << flight.flightDate << "\n"
                    << "planeName=" << flight.planeName << "\n"
                    << "isCancelled=" << (flight.isCancelled ? "true" : "false") << "\n"
                    << "price=" << flight.getPriceWithTax() << "\n" // ذخیره قیمت با احتساب مالیات
                    << "tax=" << flight.tax << "\n"
                    << "foodType=" << flight.food.getType() << "\n"
                    << "meal=" << flight.food.getMeal() << "\n";
            }
            file.close();
        }
        else {
            std::cerr << "Ghader be Baz Kardan File Nist.\n";
        }
    }

    void loadFlightsFromFile(const std::string& filename) {
        std::ifstream file(filename);
        if (file.is_open()) {
            Flight flight;
            std::string line;
            while (std::getline(file, line)) {
                if (line.find("flightID=") == 0) flight.flightID = line.substr(9);
                else if (line.find("flightType=") == 0) flight.flightType = line.substr(11);
                else if (line.find("originCity=") == 0) flight.originCity = line.substr(11);
                else if (line.find("destinationCity=") == 0) flight.destinationCity = line.substr(16);
                else if (line.find("flightDate=") == 0) flight.flightDate = Date::fromString(line.substr(11));
                else if (line.find("planeName=") == 0) flight.planeName = line.substr(10);
                else if (line.find("isCancelled=") == 0) flight.isCancelled = (line.substr(12) == "true");
                else if (line.find("price=") == 0) flight.price = std::stod(line.substr(6));
                else if (line.find("tax=") == 0) flight.tax = std::stod(line.substr(4));
                else if (line.find("foodType=") == 0) flight.food.setType(line.substr(9));
                else if (line.find("meal=") == 0) flight.food.setMeal(line.substr(5));

                if (!line.empty() && line.find("meal=") == 0) {
                    flights.push_back(flight);
                }
            }
            file.close();
        }
        else {
            std::cerr << "Ghader be Baz Kardan File Nist.\n";
        }
    }
};

#endif // AIRPORT_H
