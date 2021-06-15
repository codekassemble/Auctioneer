//#include <iostream>
#include <string>
//#include <cstdlib>
//#include <cstdio>
//#include <ctime>
using namespace std;

class trader
{
public:
	trader();
	trader(string name,char traderType , int minP , int maxP , int minQ , int maxQ );
	bid generateBid();

private:
	string traderName;
	char traderType;
	int minPriceRange;
	int maxPriceRange;
	int maxQuantityRange;
	int minQuantityRange;
};

trader::trader()
{
	cout<<"Default trader , this is bad!"<<endl;
}

trader::trader(string name,char type , int minP , int maxP , int minQ , int maxQ )
{
	traderName = name;
	traderType = type;
	minPriceRange = minP;
	maxPriceRange = maxP;
	minQuantityRange = minQ;
	maxQuantityRange = maxQ;
	cout<<"name : "<<name<<" Created"<<endl;
}

bid trader::generateBid()
{	//srand(time(NULL));
    //cout<<"trader"<<endl;
	int absoluteDistancePrice = maxPriceRange - minPriceRange;
	//cout<<"Absolute Dist price "<<absoluteDistancePrice<<endl;
	int absoluteDistanceQuantity = maxQuantityRange - minQuantityRange;
	//cout<<"Absolute Dist quant " << absoluteDistanceQuantity<<endl;
	int randPrice = minPriceRange + rand()% absoluteDistancePrice ;
	//cout << "randPrice " << randPrice<<endl;
	int randQuantity = minQuantityRange + rand() % absoluteDistanceQuantity;
	//cout << "randQuant "<< randQuantity<<endl;
	//bid(string name,int bID , char bType ,int priceInput , int inputQuantity)
	return 	bid(traderName, traderType ,randPrice ,randQuantity);
}

