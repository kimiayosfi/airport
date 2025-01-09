#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <sstream>

class Date {
private:
    int day;
    int month;
    int year;
    int hour;
    int minute;

public:
    // Setter and Getter methods
    void setDay(int d) { day = d; }
    int getDay() const { return day; }

    void setMonth(int m) { month = m; }
    int getMonth() const { return month; }

    void setYear(int y) { year = y; }
    int getYear() const { return year; }

    void setHour(int h) { hour = h; }
    int getHour() const { return hour; }

    void setMinute(int m) { minute = m; }
    int getMinute() const { return minute; }

    // Overloaded Input/Output operators
    friend std::ostream& operator<<(std::ostream& out, const Date& date) {
        out << date.day << "/" << date.month << "/" << date.year << " " << date.hour << ":" << date.minute;
        return out;
    }

    friend std::istream& operator>>(std::istream& in, Date& date) {
        char slash, colon;
        in >> date.day >> slash >> date.month >> slash >> date.year >> date.hour >> colon >> date.minute;
        return in;
    }


    static Date fromString(const std::string& str) {
        Date date;
        std::istringstream iss(str);
        char slash, colon;
        iss >> date.day >> slash >> date.month >> slash >> date.year >> date.hour >> colon >> date.minute;
        return date;
    }
};

#endif // DATE_H
