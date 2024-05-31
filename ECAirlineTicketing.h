//
//  ECAirlineTicketing.h
//  
//
//  Created by Yufeng Wu on 5/12/23.
//

#ifndef ECAirlineTicketing_h
#define ECAirlineTicketing_h
#include "ECFlightItinerary.h"
#include "ECAirlineOperation.h"
#include "ECAirport.h"
#include <vector>
// ****************************************************************************
// Airline ticketing: search for flights, issue tickets, etc
// search for flights

class ECAirlineFinancial;
class ECAirlineOperation;

class ECAirlineTicketing
{

public:
	ECAirlineTicketing(){}
	virtual ~ECAirlineTicketing(){}
	
	// implemented by Justin  
	void InitializeT(ECAirlineOperation *op, ECAirlineFinancial *financial);
	void FindFlightRecurse(const std::string &src, const std::string &dest, const std::string& currentAirport, ECFlightItinerary& currentItinerary, std::vector<ECFlightItinerary> &listItineraries) const;
	void SearchForItinerary(const std::string &src, const std::string &dest, std::vector<ECFlightItinerary> &listItineraries) const;
	bool CheckValidity(const ECFlightItinerary &currentItin, const ECFlight &PotentialFlight) const;
private:
	// implemented by Justin  
    ECAirlineOperation *pAirlineOp;
    ECAirlineFinancial *pAirlineFin;
};
// issue tickets

// etc.?
#endif /* ECAirlineTicketing_h */
