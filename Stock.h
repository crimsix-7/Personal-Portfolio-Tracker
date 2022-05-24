#pragma once
#include "Security.h"
#include "Security.h"

enum StockType { c, p };
class Stock :public Security {
private:
        string tickerSymbol;
        int parVal;
        StockType stockType;
        double dividentPerShare;
public:
        //Default constructor
        Stock();
        //Parameterized constructor
        Stock(Date pDate, double pPrice, int pQuantity, string tSym, int pVal, StockType s, double div);
        //Calculate divident income
        double dividentIncome();
        friend std::ostream& operator<<(std::ostream& out, Stock s);
        inline bool operator<(const Stock s) const {
                return tickerSymbol < s.tickerSymbol;
        }
};
//Default constructor
Stock::Stock() :Security() {
        tickerSymbol = "";
        parVal = 0;
        dividentPerShare = 0;
}
//Parameterized constructor
Stock::Stock(Date pDate, double pPrice, int pQuantity, string tSym, int pVal, StockType s, double div) :Security(pDate, pPrice, pQuantity) {
        tickerSymbol = tSym;
        parVal = pVal;
        stockType = s;
        dividentPerShare = div;
}
//Calculate divident income
double Stock::dividentIncome() {
        return dividentPerShare * getPurchaseQuantity();
}
ostream& operator<<(std::ostream& out, Stock s) {
        out << "Ticker symbol: " << "\t\t" << s.tickerSymbol << endl;
        out << fixed << setprecision(2);
        out << "Purchase date:" << "\t\t" << s.getDate() << endl;
        out << "Total price:" << "\t\t\t" << s.getPurchasePrice()
                << "\t\tPrice per share:\t" << s.getPurchasePrice() / s.getPurchaseQuantity() << endl;
        out << "Quantity purchased:" << "\t" << s.getPurchaseQuantity();
        if (s.stockType == c) {
                out << "\t\tType:\tCommon" << endl;
        }
        else {
                out << "\t\tType:\tPreffered" << endl;
        }
        out << "Par val:" << "\t\t\t\t" << s.parVal << endl;
        out << "Divident per share: " << "\t" << s.dividentPerShare << endl;
        out << "Divident income:" << "\t\t" << s.dividentIncome() << endl;
        return out;
}
