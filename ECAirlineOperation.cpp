//
//  ECAirlineOperation.cpp
//  
//
//  Created by Yufeng Wu on 5/11/23.
//

#include "ECAirlineOperation.h"
#include "ECFlightItinerary.h"
#include "ECAirlineFinancial.h"
#include "ECFlight.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;


// implemented by Justin Hasler
void ECAirlineOperation::addFlight(const std::string &srcAirport, const std::string &destAirport, double tmDepart, int maxPassengers, double costOperate)
{
	listFlights.push_back(ECFlight(srcAirport, destAirport, tmDepart, maxPassengers));
}

void ECAirlineOperation::InitializeO(ECAirlineFinancial *financial)
{
	pAirlineFin = financial;
}