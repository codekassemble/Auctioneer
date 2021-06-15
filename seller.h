class seller: public trader
{
public:
	seller();
	seller(int minPrice , int maxPrice , int minQuantity , int maxQuantity);
	string joinIntToString(string m);

private:
    string tempSellerName;
    static int sellerCounter;
};

int seller::sellerCounter = 0;

string seller::joinIntToString(string m)
{
    sellerCounter++;
    ostringstream join;
    join << m << sellerCounter;
    return join.str();
}

seller::seller():trader("defaultSeller",'a',900,900,900,900)
{
    cout<<"Bad default seller initialised"<<endl;
}

seller::seller(int minPrice ,int maxPrice ,int minQuantity , int maxQuantity):trader(joinIntToString("Seller "),'a',minPrice,maxPrice,minQuantity,maxQuantity){}

