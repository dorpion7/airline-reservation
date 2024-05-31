//
//  ECAirlineFinancial.h
//  
//
//  Created by Yufeng Wu on 5/16/23.
//

#ifndef ECAirlineFinancial_h
#define ECAirlineFinancial_h
#include "ECAirlineOperation.h"
#include <vector>
// ****************************************************************************
// Airline finanical: budgetting, pricing and money bookkeeping

// this is a class for pricing an itinerary


// implemented by me
class ECAirlineOperation; // Forward declaration

// implemented by me
class ECAirlineFinancial
{
public:
	void InitializeF(ECAirlineOperation *op);
private:
    ECAirlineOperation *pAirlineOp;

};

#endif
