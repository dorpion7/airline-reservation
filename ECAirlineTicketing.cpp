//
//  ECAirlineTicketing.cpp
//  
//
//  Created by Yufeng Wu on 5/12/23.
//

#include "ECAirlineTicketing.h"
#include "ECFlight.h"
#include <map>
#include <vector>


#include <iostream>
using namespace std;

// edges would be all flights
// so treat listofflights[] as adj[]
// all implemented by Justin  
void ECAirlineTicketing::InitializeT(ECAirlineOperation *op, ECAirlineFinancial *financial)
{
    pAirlineOp = op;
    pAirlineFin = financial;
}

void ECAirlineTicketing::SearchForItinerary(const std::string &src, const std::string &dest, std::vector<ECFlightItinerary> &listItineraries) const
{
    std::string currentAirport = src; // airport starts at src
	ECFlightItinerary itinerary; // default itin
    
    FindFlightRecurse(src, dest, currentAirport, itinerary, listItineraries);
}

void ECAirlineTicketing :: FindFlightRecurse(const std::string &src, const std::string &dest, const std::string& currentAirport, ECFlightItinerary& currentItinerary, std::vector<ECFlightItinerary> &listItineraries) const
{
    if(currentAirport == dest)
    { // if dest then we're done
        listItineraries.push_back(currentItinerary);
        return;
    }
    int sizeFlights = pAirlineOp->listFlights.size();
    for(int i = 0; i < sizeFlights; ++i)// i++ vs ++i?
    {
        ECFlight &checkFlight = pAirlineOp->listFlights.at(i);
        if(currentAirport == checkFlight.GetSource() && CheckValidity(currentItinerary, checkFlight))
        { 
            currentItinerary.AddFlight(&checkFlight);
            FindFlightRecurse(src, dest, checkFlight.GetDest(), currentItinerary, listItineraries);
            // find flight for for dest airport
            currentItinerary.RemoveLastFlight(); // pop_back
        }
    }
}


bool ECAirlineTicketing :: CheckValidity(const ECFlightItinerary &currentItinerary, const ECFlight &PotentialFlight) const
{
    if(currentItinerary.GetNumSegments()==0) // if == 0  can start adding to itinerary
        return true;

    int i = 0;
    while(i < currentItinerary.GetNumSegments())
    {
        std::string source = currentItinerary.GetSegment(i)->GetSource();
        std::string potentialDest = PotentialFlight.GetDest();

        if(potentialDest == source)/*currentItinerary.GetSegment(i)->GetSource()*/{
            return false; // if dest of the checked flight is the the source of i
        }
        i++;
    }
    double arrival = currentItinerary.GetSegment(currentItinerary.GetNumSegments()-1)->GetArrivalTime();
    double dep = PotentialFlight.GetDepartureTime();

    if(arrival > dep)
        return false;
         // if arrival > dep, invalid time
    else if(arrival <= dep)
        return true;
    return false;
}

