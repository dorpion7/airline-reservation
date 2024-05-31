//
//  ECAirlineSimulator.cpp
//  
//
//  Created by Yufeng Wu on 5/17/23.
//

#include "ECAirlineSimulator.h"
#include "ECAirlineOperation.h"
#include "ECAirlineTicketing.h"
#include "ECAirlineFinancial.h"
#include "ECAirport.h"
#include "ECFlight.h"

#include <iostream>
#include <vector>
using namespace std;


// Some methods were declared in the .h file by Professor
// but they were all fully defined in this file by Justin  
ECAirlineSimulator :: ECAirlineSimulator()
{
	pAirlineOp = new ECAirlineOperation;
    pAirlineFin = new ECAirlineFinancial;
    pAirlineTicket = new ECAirlineTicketing;
	Init();
}

ECAirlineSimulator :: ~ECAirlineSimulator()
{
	delete pAirlineOp;
    delete pAirlineFin;
    delete pAirlineTicket;
}
// implemented by Justin  
void ECAirlineSimulator ::Init()
{
	pAirlineOp->InitializeO(pAirlineFin);
	pAirlineFin->InitializeF(pAirlineOp);
	pAirlineTicket->InitializeT(pAirlineOp, pAirlineFin);
}


// Adding airport with name and IATA code
void ECAirlineSimulator::AddAirport(const std::string &name, const std::string &code)
{
	
	ECAirportInfo::Instance().CreateAirport(name, code);
	//listAirports.insert(ECAirport(name, code)); 
}

// Setup distaince between airport; note distance is symmetric: the distance from dest to src is the same as from src to dest
void ECAirlineSimulator::SetDistBtwAirports(const std::string &srcAirport, const std::string &destAirport, int dist)
{
	ECAirportInfo::Instance().SetDistanceBtw(srcAirport, destAirport, dist);
	// then we would simply access airlineInfo.distancesBtw[]

	// this may be wrong in some way
}

// Adding flights: src airport, dest airport, depart time, max number of passenger, operating cost
void ECAirlineSimulator::AddFlight(const std::string &srcAirport, const std::string &destAirport, double tmDepart, int maxPassengers, double costOperate )
{
//	pAirlineOp = GetAirlineOp();

	// layout of ECFlight is ECFlight(const std::string &srcIn, const std::string &destIn, double tmDepartIn, int maxPassengersIn) 
	pAirlineOp->addFlight(srcAirport, destAirport, tmDepart, maxPassengers, costOperate);
	// segfaulting so, try pAirlineOp.listflights.pushback

	// Would I have to call GetAirline

	// ignoring the cost to operate for now
}

// Called to indicate no more flights to add
void ECAirlineSimulator::DoneFlightAdding()
{
	//doneFlightAdding = true;

	// doesnt really seem like we need this all that much its not like flights are being added after the method call
}


// *****************************************************
// Flight search

// Searcch for flights; return all flights in listItineraries that go from src to dest
void ECAirlineSimulator::SearchForFlights(const std::string &src, const std::string &dest, std::vector<ECFlightItinerary> &listItineraries ) const
{ 
	pAirlineTicket->SearchForItinerary(src, dest, listItineraries);
}


