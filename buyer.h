//#include <iostream>
//#include <string>
//using namespace std;
// #include "trader.cpp"
#include "trader.h"
#include <sstream>
class buyer: public trader
{
public:
	buyer();
	buyer(int minPrice , int maxPrice , int minQuantity , int maxQuantity);
	void display();     
    string joinIntToString(string m);
 
private:
    string dynamicName;
    int minPrice;
    int maxPrice;
    int minQuantity;
    int maxQuantity;
    static char traderType;
    static int buyerCounter;
};

int buyer::buyerCounter = 0;
char buyer::traderType = 'b';

string buyer::joinIntToString(string m)
{
      ostringstream join;
      buyerCounter++;
    join << m << buyerCounter;
    return join.str();
}

buyer::buyer():trader("defaultBuyer",'b',-1,-1,-1,-1)
{
 cout<<"default buyer initialised , this is bad";
}

buyer::buyer(int minPrice ,int maxPrice ,int minQuantity , int maxQuantity):trader(joinIntToString("buyer"),traderType,minPrice,maxPrice,minQuantity,maxQuantity) {}


