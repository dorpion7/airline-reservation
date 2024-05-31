//
//  ECAirlineFinancial.cpp
//  
//
//  Created by Yufeng Wu on 5/16/23.
//

#include "ECAirlineFinancial.h"
#include "ECAirlineOperation.h"
#include "ECFlightItinerary.h"

#include <string>
#include <vector>
#include <iostream>
using namespace std;


// implemented by Justin 
void ECAirlineFinancial::InitializeF(ECAirlineOperation *op)
{
	pAirlineOp = op;
}
