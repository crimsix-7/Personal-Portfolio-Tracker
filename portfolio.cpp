// A portfolio is a conglomeration of various financial assets, such as stocks and bonds, that together create a balanced collection of investments. 
/*

I was inspired to do this project due to my passion and interest in the stock market i aim to follow this with a crypto portfolio application in the future.

For this project I created an object-oriented application that can allow yanyone to track financial investments in the stock market.
Five main classes will be adapted to create this portfolio: Security, Stock, Bond, Portfolio, and Date.

*/
#include <iostream>
#include<vector>
#include<algorithm>
#include "Bond.h"
#include "Security.h"
#include"Stock.h"
#include"Date.h"
using namespace std;

//Function prototypes
char menu();
void addStock(vector<Stock>& stocks);
void addBond(vector<Bond>& bonds);
void ListPortfolio(string pName, vector<Stock> stocks, vector<Bond> bonds);
void tokenizeDate(char* cDate, int& month, int& day, int& year);

//Main function
int main()
{
        //Declare vectors for storage of data
        vector<Bond> bonds;
        vector<Stock> stocks;
        string portfolioName;
        //Prompt for name of the portfolio
        cout << "Enter a name for your portfolio: ";
        getline(cin, portfolioName);
        cout << endl;
        //Get menu
        char ch = menu();
        //Loop repeat until quit
        while (ch != 'Q') {
                //Each option
                if (ch == 'S') {
                        addStock(stocks);
                }
                else if (ch == 'B') {
                        addBond(bonds);
                }
                else if (ch == 'L') {
                        ListPortfolio(portfolioName, stocks, bonds);
                }
                //Loop repetition
                cout << endl;
                ch = menu();
        }
        return 0;
}
//Display user choices and return choice
char menu() {
        char ch;
        cout << "\tMain Menu\nS -- Purchase stock\nB -- Purchase bonds\nL -- List portfolio securities\nQ -- Quit\n\nSelction: ";
        cin >> ch;
        return toupper(ch);
}
//Insert stock details into vector
void addStock(vector<Stock>& stocks) {
        string ts;
        char date[20];
        double price, div;
        int quantity, parVal, m, d, y;
        char stype;
        Date pd;
        cout << "\t\tPurchase stocks\n";
        cout << "\nPurchase date: (mm/dd/yyyy): ";
        cin >> date;
        cout << "\nTotal purchase price: ";
        cin >> price;
        cout << "\nQuantity purchased: ";
        cin >> quantity;
        cout << "\nTicker symbol: ";
        cin >> ts;
        cout << "\nPar val: ";
        cin >> parVal;
        cout << "\nStock type (c for Common or p for Preffered): ";
        cin >> stype;
        cout << "\nDivident per share: ";
        cin >> div;
        tokenizeDate(date, m, d, y);
        pd.setDate(m, d, y);
        if (stype == 'c') {
                stocks.push_back(Stock(pd, price, quantity, ts, parVal, c, div));
        }
        else {
                stocks.push_back(Stock(d, price, quantity, ts, parVal, p, div));
        }
}
//Split date into day,month and date
void tokenizeDate(char* cDate, int& month, int& day, int& year)

{

        char seps[] = "/";

        char* token = NULL;

        char* next_token = NULL;

        token = NULL;

        next_token = NULL;

        // Establish string and get the tokens:

        token = strtok_s(cDate, seps, &next_token);

        month = atoi(token);

        token = strtok_s(NULL, seps, &next_token);

        day = atoi(token);

        token = strtok_s(NULL, seps, &next_token);

        year = atoi(token);
}
//Add a bond into vector
void addBond(vector<Bond>& bonds) {
        string issuer;
        char date1[20], date2[20];
        double price, ir;
        int quantity, fVal, m, d, y;
        
        Date pd, md;
        cout << "\t\tPurchase bonds\n";
        cout << "\nPurchase date: (mm/dd/yyyy): ";
        cin >> date1;
        cout << "\nTotal purchase price: ";
        cin >> price;
        cout << "\nQuantity purchased: ";
        cin >> quantity;
        cin.ignore();
        cout << "\nIssuer: ";
        getline(cin, issuer);
        cout << "\nFace val: ";
        cin >> fVal;
        cout << "\nStated interest rate: ";
        cin >> ir;
        cin.ignore();
        cout << "\nMaturity date: (mm/dd/yyyy): ";
        cin >> date2;
        tokenizeDate(date1, m, d, y);
        pd.setDate(m, d, y);
        tokenizeDate(date2, m, d, y);
        md.setDate(m, d, y);
        bonds.push_back(Bond(pd, price, quantity, issuer, fVal, ir, md));
}
//List sorted port folio
void ListPortfolio(string pName, vector<Stock> stocks, vector<Bond> bonds) {
        cout << "\nThese are the STOCKS in your " << pName << " portfolio:\n";
        sort(stocks.begin(), stocks.end());
        for (int i = 0; i < stocks.size(); i++) {
                cout << stocks[i] << endl;
        }
        cout << "\nThese are the BONDS in your " << pName << " portfolio:\n";
        sort(bonds.begin(), bonds.end());
        for (int i = 0; i < bonds.size(); i++) {
                cout << bonds[i] << endl;
        }
}