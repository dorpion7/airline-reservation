//
//  ECFlightItinerary.cpp
//  
//
//  Created by Yufeng Wu on 5/11/23.
//

#include "ECFlightItinerary.h"
#include "ECFlight.h"
#include <iostream>
#include <string>
#include <set>		// why do we need set tell me. tell me why we need <set>
#include <vector>
using namespace std;

// itinerary

// declared in .h by prof but defined by Justin 
// access/edit segments
// Return the number of segments of the itineary
int ECFlightItinerary::GetNumSegments() const
{
	return segments.size();
}

// Return a segment
ECFlight* ECFlightItinerary::GetSegment(int segIndex) const
{
	return segments.at(segIndex);
    // could try vector.at
}


// Get flight time: from departure to arrival
double ECFlightItinerary::GetFlightTime() const
{
	double res = 0;

	for(auto x : segments)
	{
		res += x->GetFlightTime();
	}

	return res;
}

// ignore this 
/*// Get segment time: add the time of all segments
double ECFlightItinerary::GetTimeAllSegments() const
{
	double res = 0;
	for (auto x : segments)
	{
		res += (x->GetArrivalTime() - x->GetDepartureTime()); // x is a flight object
	}

	return res;
}*/ 

// Get departure time
double ECFlightItinerary::GetDepartTime() const
{
	return segments.front()->GetDepartureTime();
}

// Get arrival time
double ECFlightItinerary::GetArrivalTime() const
{
	return segments.back()->GetArrivalTime();
}

// Price 
double ECFlightItinerary::GetPrice() const
{
	// does this just mean the constant of 120? 
	return GetFlightTime() * 120.0;
}

std::string ECFlightItinerary::GetSource() const
{
	return segments.front()->GetSource();
}

// Get arrival time
std::string ECFlightItinerary::GetDest() const
{
	return segments.back()->GetDest();
}

void ECFlightItinerary::AddFlight(ECFlight *flight)
{
	segments.push_back(flight);
}

void ECFlightItinerary::RemoveLastFlight()
{
    segments.pop_back();
}



std::string ECFlightItinerary::Info(int i) const 
{

    std::string flightInfo; // String to store flight information

    // get every source
    for (int i = 0; i < segments.size(); ++i) 
        flightInfo += segments[i]->GetSource() + " to "; 
    
    // then add the last dest
    flightInfo += segments.back()->GetDest();
    std::string departure = std::to_string(segments.front()->GetDepartureTime()).substr(0,4);
    std::string arrival = std::to_string(segments.back()->GetArrivalTime()).substr(0,4); // crop since the double has too many 0s
    std::string price = std::to_string(GetPrice()).substr(0,7);
    return flightInfo + " | D: " + departure + " | A: " + arrival + " | $: " + price;
    }
