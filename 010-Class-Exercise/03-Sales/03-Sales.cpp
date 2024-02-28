#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <iomanip>
using namespace std;

class Sale {

    map<string, map<string, double> > Sales;
    
public:
   
    Sale(istream& istr) {
        int totalSales;
        istr >> totalSales;

        while (totalSales--) {
            string TownName;
            string product;
            double price;
            double quantity;
            istr >> TownName >> product >> price >> quantity;
            Sales[TownName][product] += price * quantity;
        }
    }

    void printCout(ostream& ostr);
};

void Sale::printCout(ostream& ostr) {
    ostr << fixed << setprecision(2);

    for (auto currentSale : Sales) {
        double temp = 0;
        for(auto mm : currentSale.second) 
            temp += mm.second;
        ostr << currentSale.first << " -> " << temp << endl;
    }
}

int main()
{
    Sale allSales(cin);
    
    allSales.printCout(cout);
}

