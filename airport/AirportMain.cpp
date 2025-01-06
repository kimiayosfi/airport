#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <chrono>
#include "Date.h"
#include "Food.h"
#include "Airport.h"
#include "DomesticFlights.h"
#include "ForeignFlights.h"
#include "DomesticCities.h"
#include "ForeignCities.h"
#include "Customer.h"
#include "Admin.h"
#include "Tax.h"
#include <locale>
#include <conio.h>
#include <cstdlib>
using namespace std;

// kodhaye rangi ANSI
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      // siaah
#define RED     "\033[31m"      // ghermez
#define GREEN   "\033[32m"      // sabz
#define YELLOW  "\033[33m"      // zard
#define BLUE    "\033[34m"      // aabi
#define MAGENTA "\033[35m"      // banafsh
#define CYAN    "\033[36m"      // firouze'i
#define WHITE   "\033[37m"      // sefid
#define BGBLACK   "\033[40m"    // zamine siaah
#define BGRED     "\033[41m"    // zamine ghermez
#define BGGREEN   "\033[42m"    // zamine sabz
#define BGYELLOW  "\033[43m"    // zamine zard
#define BGBLUE    "\033[44m"    // zamine aabi
#define BGMAGENTA "\033[45m"    // zamine banafsh
#define BGCYAN    "\033[46m"    // zamine firouze'i
#define BGWHITE   "\033[47m"    // zamine sefid

// Namayesh Menuye Modir
void displayAdminMenu() {
    cout << BGMAGENTA << WHITE << "=========================" << RESET << endl;
    cout << BGMAGENTA << WHITE << "||" << "      Panel Modir      " << "||" << RESET << endl;
    cout << BGMAGENTA << WHITE << "||" << "1. Afzoudan Parvaz   " << "||" << RESET << endl;
    cout << BGMAGENTA << WHITE << "||" << "2. Hazf Parvaz       " << "||" << RESET << endl;
    cout << BGMAGENTA << WHITE << "||" << "3. Namayesh Tamami Parvazha" << "||" << RESET << endl;
    cout << BGMAGENTA << WHITE << "||" << "4. Khorouj            " << "||" << RESET << endl;
    cout << BGMAGENTA << WHITE << "=========================" << RESET << endl;
}

// Namayesh Menuye Moshtari
void displayCustomerMenu() {
    cout << BGCYAN << WHITE << "=========================" << RESET << endl;
    cout << BGCYAN << WHITE << "||" << "     Panel Moshtari       " << "||" << RESET << endl;
    cout << BGCYAN << WHITE << "||" << "1. Kharid Belit        " << "||" << RESET << endl;
    cout << BGCYAN << WHITE << "||" << "2. Afzayesh Mojoudi Hesab" << "||" << RESET << endl;
    cout << BGCYAN << WHITE << "||" << "3. Estorda Belit     " << "||" << RESET << endl;
    cout << BGCYAN << WHITE << "||" << "4. Namayesh Mojoudi " << "||" << RESET << endl;
    cout << BGCYAN << WHITE << "||" << "5. Namayesh Tarikhche Kharidha" << "||" << RESET << endl;
    cout << BGCYAN << WHITE << "||" << "6. Namayesh Tamami Parvazha" << "||" << RESET << endl;
    cout << BGCYAN << WHITE << "||" << "7. Khorouj             " << "||" << RESET << endl;
    cout << BGCYAN << WHITE << "=========================" << RESET << endl;
}

// Chape Matn ba Ta'kheir
void printWithDelay(const string& message, int delay) {
    for (char ch : message) {
        cout << ch;
        cout.flush();
        this_thread::sleep_for(chrono::milliseconds(delay));
    }
    cout << endl;
}

// Panel Modir
// Panel Modir
void adminPanel(Admin& admin, Airport& airport) {
    int choice;
    do {
        displayAdminMenu();
        cout << "Entekhab konid: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: {
            string flightID, flightType, originCity, destinationCity, planeName;
            Date date;
            bool isCancelled;
            double price, tax;
            string foodType, meal;

            printWithDelay("Shenase Parvaz: ", 50);
            cin >> flightID;
            printWithDelay("Noe Parvaz (Dakheli/Khareji): ", 50);
            cin >> flightType;
            printWithDelay("Shahr Mabda: ", 50);
            cin >> originCity;
            printWithDelay("Shahr Maghsad: ", 50);
            cin >> destinationCity;
            printWithDelay("Tarikh Parvaz (Rouz/Mah/Sal Saat:Daghighe): ", 50);
            cin >> date;
            printWithDelay("Nam Havapeyma: ", 50);
            cin >> planeName;
            printWithDelay("Vaziyat Laghv Shodan (1: Laghv Shodeh, 0: Laghv Nashodeh): ", 50);
            cin >> isCancelled;
            printWithDelay("Gheymat: ", 50);
            cin >> price;
            printWithDelay("Maliat (percentage): ", 50);
            cin >> tax;
            printWithDelay("Noe Ghaza(Economic/Business): ", 50);
            cin >> foodType;
            printWithDelay("Vade Ghazayi: ", 50);
            cin >> meal;

            admin.setFlightID(flightID);
            admin.setFlightType(flightType);
            admin.setOriginCity(originCity);
            admin.setDestinationCity(destinationCity);
            admin.setFlightDate(date);
            admin.setPlaneName(planeName);
            admin.setIsCancelled(isCancelled);
            admin.setPrice(price);
            admin.setTax(tax);
            admin.setFoodType(foodType);
            admin.setMeal(meal);
            admin.manageFlights(airport, true);
            break;
        }
        case 2: {
            string flightID;
            printWithDelay("Shenase Parvaz: ", 50);
            cin >> flightID;
            admin.setFlightID(flightID);
            admin.manageFlights(airport, false);
            break;
        }
        case 3:
            airport.displayFlights();
            break;
        case 4:
            printWithDelay("Khorouj az Panel Modir.", 50);
            break;
        default:
            printWithDelay("Entekhab Namotabar Ast.", 50);
            break;
        }
    } while (choice != 4);
}


// Panel Moshtari
void customerPanel(Customer& customer, Airport& airport) {
    int choice;
    do {
        displayCustomerMenu();
        cout << "Entekhab konid: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: {
            int flightID;
            printWithDelay("Shenase Parvaz: ", 50);
            cin >> flightID;
            customer.buyTicket(flightID);
            break;
        }
        case 2: {
            double amount;
            printWithDelay("Mablagh: ", 50);
            cin >> amount;
            customer.setBalance(customer.getBalance() + amount);
            break;
        }
        case 3: {
            int flightID;
            printWithDelay("Shenase Parvaz: ", 50);
            cin >> flightID;
            customer.refundTicket(flightID);
            break;
        }
        case 4: {
            customer.displayBalance(); // نمایش موجودی حساب
            break;
        }
        case 5:
            for (int i = 0; i < customer.getPurchasedFlights().size(); ++i) {
                printWithDelay("Shenase Parvaz: " + to_string(customer.getPurchasedFlights()[i]), 50);
            }
            break;
        case 6:
            airport.displayFlights();
            break;
        case 7:
            printWithDelay("Khorouj az Panel Moshtari.", 50);
            break;
        default:
            printWithDelay("Entekhab Namotabar Ast.", 50);
            break;
        }
    } while (choice != 7);
}



// Khat ke Barname az anja Shoroo' Mishavad
int main() {
    setlocale(LC_ALL, "en_US.UTF-8");

    Admin admin(1, "admin", "1234");
    Customer customer(1, "John Doe", 500.0);
    Airport airport;

    airport.loadFlightsFromFile("flights.txt");
    customer.loadFromFile();  // بارگذاری مشخصات مشتریان از فایل
    customer.loadPurchasesFromFile();  // بارگذاری خریدهای مشتریان از فایل

    while (true) {  // Halqeye da'imi baraye entekhab panel
        int userType;
        cout << BGBLUE << WHITE << "1. Modir" << RESET << endl;
        cout << BGGREEN << WHITE << "2. Moshtari" << RESET << endl;
        cout << "Entekhab konid: ";
        cin >> userType;
        cin.ignore();

        if (userType == 1) {
            string username, password;
            printWithDelay("Nam Karbari: ", 50);
            getline(cin, username);
            printWithDelay("Ramz Obour: ", 50);
            getline(cin, password);

            if (admin.authenticate(username, password)) {
                adminPanel(admin, airport);
            }
            else {
                printWithDelay("Nam Karbari ya Ramz Obour Nadorost Ast.", 50);
            }
        }
        else if (userType == 2) {
            customerPanel(customer, airport);
        }
        else {
            printWithDelay("Entekhab Namotabar Ast.", 50);
        }

        // پاک کردن صفحهٔ خط فرمان
        system("cls");  // برای ویندوز
        // system("clear");  // برای لینوکس/مک
    }

    return 0;
}
