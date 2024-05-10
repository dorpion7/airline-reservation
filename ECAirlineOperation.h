//
//  ECAirlineOperation.h
//  
//
//  Created by Yufeng Wu on 5/11/23.
//  About operation of an airline: especially flights management

#ifndef ECAirlineOperation_h
#define ECAirlineOperation_h

#include <iostream>
#include "ECFlight.h"
#include "ECAirlineFinancial.h"
#include <vector>
using namespace std;
// put your code about airline operation here...

// what flights the airline is operating

class ECAirlineFinancial;

class ECAirlineOperation
{

	
public:
	ECAirlineOperation(){}
	//ECAirlineOperation(std::vector<ECFlight>  input);
	virtual ~ECAirlineOperation(){}

	void addFlight(const std::string &srcAirport, const std::string &destAirport, double tmDepart, int maxPassengers, double costOperate);
	
	// implemented by Justin Hasler
	void InitializeO(ECAirlineFinancial *financial);
	friend class ECAirlineTicketing;
private:
	// implemented by Justin Hasler
	std::vector<ECFlight> listFlights;
	ECAirlineFinancial *pAirlineFin;



};
#endif


// im gonna just skip this for now