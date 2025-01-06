#ifndef FOREIGNFLIGHTS_H
#define FOREIGNFLIGHTS_H

#include "Airport.h"  

class ForeignFlights : public Airport {
private:
    std::string originCity;       // شهر مبدا
    std::string destinationCity;  // شهر مقصد
    Date flightDate;              // تاریخ پرواز
    std::string planeName;        // نام هواپیما
    bool isCancelled;             // وضعیت لغو پرواز

public:
    void setOriginCity(const std::string& city) { originCity = city; }  // تنظیم شهر مبدا
    std::string getOriginCity() const { return originCity; }            // دریافت شهر مبدا

    void setDestinationCity(const std::string& city) { destinationCity = city; }  // تنظیم شهر مقصد
    std::string getDestinationCity() const { return destinationCity; }            // دریافت شهر مقصد

    void setFlightDate(const Date& date) { flightDate = date; }        // تنظیم تاریخ پرواز
    Date getFlightDate() const { return flightDate; }                  // دریافت تاریخ پرواز

    void setPlaneName(const std::string& name) { planeName = name; }   // تنظیم نام هواپیما
    std::string getPlaneName() const { return planeName; }             // دریافت نام هواپیما

    void setIsCancelled(bool cancelled) { isCancelled = cancelled; }   // تنظیم وضعیت لغو پرواز
    bool getIsCancelled() const { return isCancelled; }                // دریافت وضعیت لغو پرواز
};

#endif // FOREIGNFLIGHTS_H
