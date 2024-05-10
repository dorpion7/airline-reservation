//
//  ECFlightItinerary.h
//  
//
//  Created by Yufeng Wu on 5/11/23.
//

#ifndef ECFlightItinerary_h
#define ECFlightItinerary_h

#include <vector>
#include <string>

class ECFlight;
class ECAirlineFinancial;

// ****************************************************************************
// Flight itineary: consisting segments of flights so to go from one airport to another airport

class ECFlightItinerary
{
public:
    ECFlightItinerary(){}
    ~ECFlightItinerary(){}
    
    // access/edit segments
    // Return the number of segments of the itineary
    int GetNumSegments() const;
    
    // Return a segment
    ECFlight *GetSegment(int segIndex) const;
    
    // Get flight time: from departure to arrival
    double GetFlightTime() const;
    
    // Get segment time: add the time of all segments
    // ignore this double GetTimeAllSegments() const;
    
    // Get departure time
    double GetDepartTime() const;
    
    // Get arrival time
    double GetArrivalTime() const;
    
    void AddFlight(ECFlight *flight);
    // Price 
    double GetPrice() const;
    
    std::string GetSource() const;

    std::string GetDest() const;

    // implemented by Justin Hasler
    void RemoveLastFlight();

    // implemented by Justin Hasler
    std::string Info(int i) const; // dumps itinerary stuff
    
private:
    // your code
    // implemented by Justin Hasler
    std::vector<ECFlight*> segments;
    ECAirlineFinancial *pAirlineFin;
    int numSegs; // is this redundant because numSegs would just be segments.size()? yes
    double flightTime;
    double price;

};

#endif /* ECFlightItinerary_h */
