#pragma once
class Tax {
public:
    double calculateTax(double price, double percentage) const {  // محاسبه مالیات
        return price + (price * percentage / 100);
    }
};

