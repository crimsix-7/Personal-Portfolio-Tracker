#pragma once
#include "Security.h"
#include<string>

using namespace std;

class Bond :public Security {
private:
        string issuer;
        int faceVal;
        double interestRate;
        Date maturityDate;
public:
        //Default constructor
        Bond();
        //Parameterized constructor
        Bond(Date pDate, double pPrice, int pQuantity, string iss, int fVal, double ir, Date mDate);
        double calculateIncome();
        friend std::ostream& operator<<(std::ostream& out, Bond b);
        inline bool operator<(const Bond b) const {
                return issuer < b.issuer;
        }
};
//Default constructor
Bond::Bond() :Security() {
        issuer = "";
        faceVal = 0;
        interestRate = 0;
}
//Parameterized constructor
Bond::Bond(Date pDate, double pPrice, int pQuantity, string iss, int fVal, double ir, Date mDate) :Security(pDate, pPrice, pQuantity) {
        issuer = iss;
        faceVal = fVal;
        interestRate = ir;
        maturityDate = mDate;
}
double Bond::calculateIncome() {
        return getPurchaseQuantity()*faceVal*interestRate;
}
ostream& operator<<(std::ostream& out, Bond b) {
        out << "Issuer: " << "\t\t\t" << b.issuer << endl;
        out << fixed << setprecision(2);
        out << "Purchase date:" << "\t\t" << b.getDate() << endl;
        out << "Quantity purchased:" << "\t" << b.getPurchaseQuantity()
                << "\t\tFace value:\t" << b.faceVal << endl;
        out << "Total Purchase price::" << "\t\t" << b.getPurchasePrice() << endl;
        out << "StatedInterest Rate: " << "\t" << b.interestRate
                << "\t\tMaturity Date:\t" << b.maturityDate << endl;
        out << "Interest income:" << "\t\t" << b.calculateIncome() << endl;
        return out;
}
