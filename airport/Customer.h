#include <fstream>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "Tax.h"

class Customer {
private:
    int customerID;
    std::string name;
    double balance;
    std::vector<int> purchasedFlights;

public:
    Customer(int id = 0, std::string n = "", double b = 0) : customerID(id), name(n), balance(b) {}

    void setCustomerID(int id) { customerID = id; }
    int getCustomerID() const { return customerID; }

    void setName(const std::string& n) { name = n; }
    std::string getName() const { return name; }

    void setBalance(double b) { balance = b; }
    double getBalance() const { return balance; }

    void addPurchasedFlight(int flightID) {
        purchasedFlights.push_back(flightID);
    }

    std::vector<int> getPurchasedFlights() const { return purchasedFlights; }

    void buyTicket(int flightID) {
        double flightPrice = getFlightPrice(flightID);

        std::cout << "Mojoudi Feli: " << balance << std::endl;
        std::cout << "Gheymat Parvaz: " << flightPrice << std::endl;

        if (balance >= flightPrice) {
            addPurchasedFlight(flightID);
            balance -= flightPrice;
            saveToFile();
            savePurchaseToFile(flightID);
            std::cout << "Bilit Kharidari Shod." << std::endl;
        }
        else {
            std::cout << "Mojoudi Kafi Nist. Lotfan Mojoudi Hesab Ra Afzayesh Dahid." << std::endl;
        }
    }

    void saveToFile() const {
        std::ofstream file("customers.txt");
        if (file.is_open()) {
            file << "customerID=" << customerID << "\n"
                << "name=" << name << "\n"
                << "balance=" << balance << "\n";
            file.close();
        }
        else {
            std::cerr << "Ghader be Baz Kardan File Nist.\n";
        }
    }

    void savePurchaseToFile(int flightID) const {
        std::ofstream file("purchases.txt", std::ios::app);
        if (file.is_open()) {
            file << "customerID=" << customerID << "\n"
                << "flightID=" << flightID << "\n";
            file.close();
        }
        else {
            std::cerr << "Ghader be Baz Kardan File Nist.\n";
        }
    }

    double getFlightPrice(int flightID) const {
        std::ifstream file("flights.txt");
        if (file.is_open()) {
            std::string line;
            int fileFlightID;
            double price;
            while (std::getline(file, line)) {
                if (line.find("flightID=") == 0) {
                    fileFlightID = std::stoi(line.substr(9));
                    if (fileFlightID == flightID) {
                        while (std::getline(file, line)) {
                            if (line.find("price=") == 0) {
                                price = std::stod(line.substr(6));
                                return price;
                            }
                        }
                    }
                }
            }
            file.close();
        }
        return 0.0;
    }

    void refundTicket(int flightID) {
        auto it = std::find(purchasedFlights.begin(), purchasedFlights.end(), flightID);
        if (it != purchasedFlights.end()) {
            double flightPrice = getFlightPrice(flightID);
            purchasedFlights.erase(it);
            saveToFile();
            removePurchaseFromFile(flightID);

            Tax tax;
            double refundAmount = flightPrice * 0.90;
            balance += refundAmount;
            saveToFile();
            std::cout << "Mablagh Bazgashti: " << refundAmount << std::endl;
        }
    }

    void removePurchaseFromFile(int flightID) const {
        std::ifstream infile("purchases.txt");
        std::ofstream outfile("temp.txt");
        std::string line;
        while (std::getline(infile, line)) {
            if (line.find("customerID=") == 0) {
                int tempCustomerID = std::stoi(line.substr(11));
                std::getline(infile, line);
                int tempFlightID = std::stoi(line.substr(9));
                if (!(tempCustomerID == customerID && tempFlightID == flightID)) {
                    outfile << "customerID=" << tempCustomerID << "\n"
                        << "flightID=" << tempFlightID << "\n";
                }
            }
        }
        infile.close();
        outfile.close();
        std::remove("purchases.txt");
        std::rename("temp.txt", "purchases.txt");
    }

    void loadFromFile() {
        std::ifstream file("customers.txt");
        if (file.is_open()) {
            std::string line;
            while (std::getline(file, line)) {
                if (line.find("customerID=") == 0) {
                    customerID = std::stoi(line.substr(11));
                }
                else if (line.find("name=") == 0) {
                    name = line.substr(5);
                }
                else if (line.find("balance=") == 0) {
                    balance = std::stod(line.substr(8));
                }
            }
            file.close();
        }
        else {
            std::cerr << "Ghader be Baz Kardan File Nist.\n";
        }
    }

    void loadPurchasesFromFile() {
        std::ifstream file("purchases.txt");
        if (file.is_open()) {
            std::string line;
            while (std::getline(file, line)) {
                if (line.find("customerID=") == 0) {
                    int tempCustomerID = std::stoi(line.substr(11));
                    if (tempCustomerID == customerID) {
                        std::getline(file, line);
                        if (line.find("flightID=") == 0) {
                            int flightID = std::stoi(line.substr(9));
                            addPurchasedFlight(flightID);
                        }
                    }
                }
            }
            file.close();
        }
        else {
            std::cerr << "Ghader be Baz Kardan File Nist.\n";
        }
    }

    void displayBalance() const {
        std::cout << "Mojoudi : " << balance << std::endl;
    }
};
