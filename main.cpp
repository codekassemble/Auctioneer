#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>
#include <cstdlib>
#include <vector>
#include <fstream>
using namespace std;
#include "bid.h"
#include "auctioneer.h"
#include "simnew.h"




int main()
{
	//cout<<"Hello";
    srand(time(NULL));
	simnew sim;
	sim.start();

	return 0;
}
