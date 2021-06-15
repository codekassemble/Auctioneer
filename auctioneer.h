#include <math.h>
#include <fstream>
#include <sstream>
using namespace std;

class auctioneer
{
private:
	ofstream outputObject;
	string tempBidObject;
    enum class optionFlag { buyerGreater , sellerGreater , bothEqual};

public:
	auctioneer();
	void displayOutput(bid &buyerbids , bid &sellerbids ); //Display matched individual bids
	void start(vector<bid>& sellerList , vector<bid>& buyerList);
	string returnBidIntoString (bid& inputBid);
	int subtractVector(bid bid1 , bid bid2);
	void printToFile(vector<bid> &input);
	void printToBidFile(bid &input , bid &input2);
	void printUnmatchedBids(vector<bid> &buyer1, vector<bid> &seller1);
	void printInitialBid(vector<bid> &buyer1, vector<bid> &seller1);
	void matchPrintUpdateBids(vector<bid>& buyerList , vector<bid>& sellerList);
	void displayPrintSet(bid& buyer , bid& seller  , string message ,optionFlag myEnum );
};

string auctioneer::returnBidIntoString(bid& inputBid)
{
    ostringstream join;
    join << "bid name : " << inputBid.getName()<<" bidID : " << inputBid.getbID()<<" Bid Type : "<<inputBid.getbidType()<<" Price is : "<<inputBid.getPrice()<<" Quantity is : " << inputBid.getQuantity() << endl;
    return join.str();
}

auctioneer::auctioneer()
{
    cout<<"New auctioneer"<<endl;
}

int auctioneer::subtractVector(bid bid1 , bid bid2)
{
	int temp1 = bid1.getQuantity();
	int temp2 = bid2.getQuantity();
	int temp3 = temp2 - temp1;
	return temp3;
}

void auctioneer::displayOutput(bid &buyerbids , bid &sellerbids )
{
    cout << "Match list is : ";

    buyerbids.displayBid();

    cout << " | with | ";

	sellerbids.displayBid();
    cout<<endl;
}

void auctioneer::printToFile(vector<bid> &input)
{
	for(unsigned int i= 0 ; i < input.size(); i++)
	{
		if(input[i].getQuantity() != 0)
		outputObject << "bid name : " << input[i].getName()<<" bidID : " << input[i].getbID() << ","<<" Bid Type : "<<input[i].getbidType()<< " , "<<" Price is : "<<input[i].getPrice()<< " , "<<" Quantity is : *" << input[i].getQuantity() <<endl;
	}
}

void auctioneer::printToBidFile(bid &input ,bid &input2  )
{
	double clearPrice = ((input.getPrice() + input2.getPrice())/2);
	outputObject <<"\n" << "bid name : " << input.getName()<<" bidID : " << input.getbID() << " , "<< " Bid Type : "<<input.getbidType()<< " , "<<" Price is : "<<input.getPrice()<< " , "<<" Quantity is : *" << input.getQuantity() << " With <==> " << "bid name : " << input2.getName()<<" bidID : " << input2.getbID() << ","<<" Bid Type : "<<input2.getbidType()<< " , "<<" Price is : "<<input2.getPrice()<< " , "<<" Quantity is : *" << input2.getQuantity() << " With clearing price " <<clearPrice <<"\n";
}

void auctioneer::start(vector<bid>& buyerList , vector<bid>& sellerList)
{
    cout<<"Auction Started!"<<endl;
    outputObject.open("auctionresults.txt");
    if(outputObject.fail())
    {
        cout<<"There was an error opening/modifying the file"<<endl;
    }

    printInitialBid(buyerList,sellerList);

    matchPrintUpdateBids(buyerList,sellerList);

	printUnmatchedBids(buyerList,sellerList);

	outputObject.close();
}


void auctioneer::printUnmatchedBids(vector<bid> &buyer1, vector<bid> &seller1)
{
	outputObject<<endl; //Write new line
	outputObject<<"Here starts the unmatched bids"<<endl; //Unmatched header
	printToFile(buyer1); //Print leftover bids
	printToFile(seller1); //Print leftover bids
	outputObject<<endl;
}

void auctioneer::printInitialBid(vector<bid> &buyer1, vector<bid> &seller1)
{
    outputObject <<" Here are the buyers"<<endl;
    printToFile(buyer1); //Print intial bids
    outputObject<< "\n"; //Print new line

    outputObject<< "Here are the sellers"<<endl;
    printToFile(seller1); //Print intial bids
    outputObject<<endl;
}

void auctioneer::matchPrintUpdateBids(vector<bid>& buyerList , vector<bid>& sellerList)
{
	outputObject<<"Here starts the matched bids"<<endl;

	for(unsigned int i = 0 ; i < buyerList.size() ; i++)
	{
		for (unsigned int j = 0 ; j < sellerList.size() ; j++)
		{
			double clearingPrice = 0;
			if( ( buyerList[i].getPrice() <  sellerList[j].getPrice() ) )
			{
				continue; //skip if condition
			}

			if( buyerList[i].getQuantity() > sellerList[j].getQuantity() && (sellerList[j].getQuantity() != 0) ) //If there is more buyer quantity than seller
				//update corresponding matched bid
			{
				displayPrintSet(buyerList[i] ,sellerList[j]  , "Match found , with buyer quantity update", optionFlag::buyerGreater);
           }

			else if(sellerList[j].getQuantity() > buyerList[j].getQuantity() && (buyerList[i].getQuantity() != 0)) // If there is less buyer than seller quantity
			{
				displayPrintSet(buyerList[i] ,sellerList[j]  , "Match found seller ask for more than buyer quantity", optionFlag::sellerGreater);
			}

			else if ((buyerList[i].getQuantity() == sellerList[j].getQuantity()) &&(sellerList[j].getQuantity() != 0) &&(buyerList[i].getQuantity() != 0) )
			{	//If equal quantity match and set quantity to 0
				displayPrintSet(buyerList[i] , sellerList[j]  , "Match found" , optionFlag::bothEqual );
			}

			else
			{
				//x = 0;
			}

			clearingPrice = ((buyerList[i].getPrice()+ sellerList[j].getPrice())/2);
			cout <<"clearing price is : "<< clearingPrice <<endl;
			cout<< "\n";

		}
	}
}



void auctioneer::displayPrintSet(bid& buyer , bid& seller  , string message , optionFlag myEnum)
{
	cout << message <<endl;
	displayOutput(buyer , seller);
	printToBidFile(buyer,seller);

	switch(myEnum)
	{
		case optionFlag::buyerGreater:
		{
			buyer.setQuantity(subtractVector(seller ,buyer));
			seller.setQuantity(0);
			cout<<buyer.getName()<< " remainder is : " << buyer.getQuantity()<<endl;
		}
		break;
		case optionFlag::sellerGreater:
		{
			seller.setQuantity(subtractVector(buyer,seller ));// Update seller quantity (all of buyer quantities subtracted)
			buyer.setQuantity(0);
			cout<<seller.getName()<< " remainder is : " << seller.getQuantity()<<endl;
		}
		break;
		case optionFlag::bothEqual:
		{
			seller.setQuantity(0);
			buyer.setQuantity(0);
		}
		break;
		default:
		{}
	}
}

