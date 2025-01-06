#include <fstream>
#include <algorithm>
#include <iostream>
#include <string>
#include "Airport.h"
#include "DomesticFlights.h"
#include "ForeignFlights.h"
#include "DomesticCities.h"
#include "ForeignCities.h"
#include "Food.h"

class Admin {
private:
    int adminID;
    std::string adminName;
    std::string adminPassword;
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

public:
    Admin(int id = 0, std::string name = "", std::string password = "") : adminID(id), adminName(name), adminPassword(password), isCancelled(false) {}

    void setAdminID(int id) { adminID = id; }
    int getAdminID() const { return adminID; }

    void setAdminName(const std::string& name) { adminName = name; }
    std::string getAdminName() const { return adminName; }

    void setAdminPassword(const std::string& password) { adminPassword = password; }
    std::string getAdminPassword() const { return adminPassword; }

    void setFlightID(const std::string& id) { flightID = id; }
    std::string getFlightID() const { return flightID; }

    void setFlightType(const std::string& type) { flightType = type; }
    std::string getFlightType() const { return flightType; }

    void setOriginCity(const std::string& city) { originCity = city; }
    std::string getOriginCity() const { return originCity; }

    void setDestinationCity(const std::string& city) { destinationCity = city; }
    std::string getDestinationCity() const { return destinationCity; }

    void setFlightDate(const Date& date) { flightDate = date; }
    Date getFlightDate() const { return flightDate; }

    void setPlaneName(const std::string& name) { planeName = name; }
    std::string getPlaneName() const { return planeName; }

    void setIsCancelled(bool cancelled) { isCancelled = cancelled; }
    bool getIsCancelled() const { return isCancelled; }

    void setPrice(double p) { price = p; }
    double getPrice() const { return price; }

    void setTax(double t) { tax = t; }
    double getTax() const { return tax; }

    void setFoodType(const std::string& type) { food.setType(type); }
    std::string getFoodType() const { return food.getType(); }

    void setMeal(const std::string& meal) { food.setMeal(meal); }
    std::string getMeal() const { return food.getMeal(); }

    bool authenticate(const std::string& name, const std::string& password) const {
        return adminName == name && adminPassword == password;
    }

    void manageFlights(Airport& airport, bool add) {
        Airport::Flight flight = { flightID, flightType, originCity, destinationCity, flightDate, planeName, isCancelled, price, tax, food };
        if (add) {
            airport.addFlight(flight);
        }
        else {
            airport.removeFlight(flightID);
        }
        airport.saveFlightsToFile("flights.txt");
    }
};

void saveAdminToFile(const std::string& filename, const Admin& admin) {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << "adminID=" << admin.getAdminID() << "\n"
            << "adminName=" << admin.getAdminName() << "\n"
            << "adminPassword=" << admin.getAdminPassword() << "\n";
        file.close();
    }
    else {
        std::cerr << "Ghader be Baz Kardan File Nist.\n";
    }
}

Admin loadAdminFromFile(const std::string& filename) {
    Admin admin;
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            if (line.find("adminID=") == 0) admin.setAdminID(std::stoi(line.substr(8)));
            else if (line.find("adminName=") == 0) admin.setAdminName(line.substr(10));
            else if (line.find("adminPassword=") == 0) admin.setAdminPassword(line.substr(13));
        }
        file.close();
    }
    else {
        std::cerr << "Ghader be Baz Kardan File Nist.\n";
    }
    return admin;
}
