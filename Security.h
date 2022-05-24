#pragma once
#include "Date.h"
#include<string>
#include<iomanip>

using namespace std;

class Security {
private:
        Date purchaseDate;
        double purchasePrice;
        int purchaseQuantity;
public:
        //Default constructor
        Security();
        //Parameterized constructor
        Security(Date pDate, double pPrice, int pQuantity);
        //Getter
        double getPurchasePrice();
        int getPurchaseQuantity();
        Date getDate();
        //Output details
        friend std::ostream& operator<<(std::ostream&, Security);
};
//Default constructor
Security::Security() {
        purchasePrice = 0;
        purchaseQuantity = 0;
}
//Parameterized constructor
Security::Security(Date pDate, double pPrice, int pQuantity) {
        purchaseDate = pDate;
        purchasePrice = pPrice;
        purchaseQuantity = pQuantity;
}
//Getter
double Security::getPurchasePrice() {
        return purchasePrice;
}
int Security::getPurchaseQuantity() {
        return purchaseQuantity;
}
Date Security::getDate() {
        return purchaseDate;
}
//Output details
std::ostream& operator<<(std::ostream& out, Security s) {
        out << fixed << setprecision(2);
        out << "Purchase date:" << "\t\t" << s.purchaseDate << endl;
        out << "Total price:" << "\t\t\t" << s.purchasePrice << endl;
        out << "Quantity purchased:" << "\t" << s.purchaseQuantity << endl;
        return out;
}
