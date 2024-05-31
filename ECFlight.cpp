//
//  ECFlight.cpp
//  
//
//  Created by Yufeng Wu on 5/11/23.
//

#include "ECFlight.h"
#include "ECAirport.h"

#include <iostream>
#include <vector>
using namespace std;

// declared in .h by prof but defined by me

//ECAirportInfo &airportInfo = ECAirportInfo::Instance();
// Get departure time
double ECFlight::GetDepartureTime() const
{
	return depTime;
}

// Get arrival time
double ECFlight::GetArrivalTime() const
{
	return depTime + GetFlightTime();
}

double ECFlight::GetFlightTime() const
{ // this seems right
	std::string src = GetSource();
	std::string dest = GetDest();
	int distBtw = ECAirportInfo::Instance().getDist(src, dest);
	double res = distBtw/500.0;

	
	// the getDist isnt updated yet
	return res;
}

// Set max passenger for this flight
void ECFlight::SetMaxNumPassengers(int m)
{
	maxPass = m;
}

// Get src airport code
std::string ECFlight::GetSource() const
{
	return src;
}

// Get destination code
std::string ECFlight::GetDest() const
{
	return dest;
}
