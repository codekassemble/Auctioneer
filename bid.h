
class bid
{
public:
		bid();
		bid(string name, char bType ,int price , int quantity);
		string getName();
		int getbID();
		char getbidType();
		double getPrice();
		int getQuantity();
		void setQuantity(int input);
	    void displayBid();
	    static int counter;

private:
		string bidName;
		int bidID;
		char bidType;
		double price;
		int quantity;

};
int bid::counter = 0;

bid::bid()
{
	cout<<"Bad default bid generated!"<<endl;
	displayBid();
}

void bid::displayBid()
{
    //cout <<"This is bid "<<endl;
    cout << "bid name : " << bidName<<" bidID : " << bidID << ","<<" Bid Type : "<<bidType<< " , "<<" Price is : "<<price<< " , "<<" Quantity is : *" << quantity <<endl;
}

bid::bid(string name, char bType ,int priceInput , int inputQuantity)
{	cout<<"Bid created"<<endl;
	bidName = name;
	counter++;
	bidID = counter;
	bidType = bType;
	price = priceInput;
	quantity = inputQuantity;
}

// Accessors
 string bid::getName()
{
	return bidName;
}
int bid::getbID()
{
	return bidID;
}
char bid::getbidType()
{
	return bidType;
}
double bid::getPrice()
{
	return price;
}
int bid::getQuantity()
{
	return quantity;
}

//Modifiers , update the quantity for bid matching

void bid::setQuantity(int input)
{
	quantity = input;
}


