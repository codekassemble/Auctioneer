#include "buyer.h"
#include "seller.h"

class simnew
{
public:
    simnew();
    
    void generateBuyer(int n); // generate list of buyer in vector buyerGen
    void generateSeller(int n); //generate list of buyer in vector sellerGen
    void generateBuyerBid(vector<buyer> &n);
    void generateSellerBid(vector<seller> &n);
    void start();
    string joinIntToString(string m ,int n);
     buyer genBuyer();
     seller genSeller();   

    const int minP = 50;
    const int maxP = 151;
    //const int maxP = rand() %151;
    const int minQ = 1;
    const int maxQ = 51;
    //const int maxQ = rand()% 51;

private:
     int tempRecursion; // used for counter in how many seller/buyer (& their corresponding bids) objects

    vector<buyer> buyerGen; //vector of buyers
    vector<seller> sellerGen; //vector of sellers

    vector<bid> buyerBid;   //Vector of buyers bid
    vector<bid> sellerBid;  //vector of sellers bid
};

simnew::simnew(){}

void simnew::generateSeller(int n)// function returns a list of buyer in vector
{
    for (int i = 0 ; i < n ; i++)
    {
        sellerGen.push_back(genSeller());
    }
}

 void simnew::generateBuyer(int n)// function returns a list of buyer in vector
 {
    for (int i = 0 ; i < n ; i++)
    {
        buyerGen.push_back(genBuyer());
    }
 }

 buyer simnew::genBuyer()
 {
    //int maxQ = rand()% 51;
    // int maxP = rand() %151;
    return buyer(minP,maxP,minQ,maxQ);
 }

seller simnew::genSeller()
 {
    // int maxP = rand() %151;
     //int maxQ = rand()% 51;
    return seller(minP,maxP,minQ,maxQ);
 }

 void simnew::generateBuyerBid(vector<buyer>& n)
{
    for( unsigned int i = 0 ; i < n.size() ; i++)
    {
        bid tempGenBid = n[i].generateBid(); //generate bid from current buyer in vector
        buyerBid.push_back(tempGenBid); // store bid to global bid vector
        tempGenBid.displayBid(); // show bid
    }
}

void simnew::generateSellerBid(vector<seller> &n)
{
    for( unsigned int i = 0 ; i < n.size() ; i++)
    {
      //buyer newbuyer(buyerName, 50, 150 ,1 ,50 );
        bid tempGenBid = n[i].generateBid(); //generate bid from current buyer in vector
        sellerBid.push_back(tempGenBid); // store bid to global bid vector
        tempGenBid.displayBid(); // show bid
    }
}

string simnew::joinIntToString(string m,int n)
{
    ostringstream join;
    join << m << n;
    return join.str();
}

void simnew::start()
{
    cout << "Enter the amount of buyers ";
    cin >> tempRecursion ;
    //tempRecursion = 10;
    generateBuyer(tempRecursion); // generates buyers and puts them into buyerGen
    generateBuyerBid(buyerGen); // takes buyerGen and generates bid , put bin into buyerBid
    cout<<endl;

    cout << "Enter the amount of sellers ";
    cin >> tempRecursion ;
    generateSeller(tempRecursion);
    generateSellerBid(sellerGen);
    cout<<endl;

   auctioneer auction;
   auction.start(buyerBid,sellerBid);
}

