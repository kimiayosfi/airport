#ifndef DOMESTICFLIGHTS_H
#define DOMESTICFLIGHTS_H

#include "Airport.h"  

class DomesticFlights : public Airport {
private:
    std::string originCity;       // Shahr Mabda
    std::string destinationCity;  // Shahr Maghsad
    Date flightDate;              // Tarikh Parvaz
    std::string planeName;        // Nam Havapeyma
    bool isCancelled;             // Vaziyat Laghv Parvaz

public:
    void setOriginCity(const std::string& city) { originCity = city; }  // Tanzime Shahr Mabda
    std::string getOriginCity() const { return originCity; }            // Daryaft Shahr Mabda

    void setDestinationCity(const std::string& city) { destinationCity = city; }  // Tanzime Shahr Maghsad
    std::string getDestinationCity() const { return destinationCity; }            // Daryaft Shahr Maghsad

    void setFlightDate(const Date& date) { flightDate = date; }        // Tanzime Tarikh Parvaz
    Date getFlightDate() const { return flightDate; }                  // Daryaft Tarikh Parvaz

    void setPlaneName(const std::string& name) { planeName = name; }   // Tanzime Nam Havapeyma
    std::string getPlaneName() const { return planeName; }             // Daryaft Nam Havapeyma

    void setIsCancelled(bool cancelled) { isCancelled = cancelled; }   // Tanzime Vaziyat Laghv Parvaz
    bool getIsCancelled() const { return isCancelled; }                // Daryaft Vaziyat Laghv Parvaz
};

#endif // DOMESTICFLIGHTS_H
