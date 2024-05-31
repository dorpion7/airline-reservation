//
//  ECFlight.h
//  
//
//  Created by Yufeng Wu on 5/11/23.
//

#ifndef ECFlight_h
#define ECFlight_h

#include <string>
#include <vector>

// ****************************************************************************
// Flight: service between two airports at a specific time;

class ECFlight 
{
public:
    ECFlight(const std::string &srcIn, const std::string &destIn, double tmDepartIn, int maxPassengersIn) :src(srcIn),dest(destIn),depTime(tmDepartIn), maxPass(maxPassengersIn)
    {
    }
    virtual ~ECFlight()
    {
    }
    
    // Get departure time
    double GetDepartureTime() const;
    
    // Get arrival time
    double GetArrivalTime() const;
    
    // Set max passenger for this flight
    void SetMaxNumPassengers(int m);
    
    // Get src airport code
    std::string GetSource() const;
    
    // Get destination code
    std::string GetDest() const;

    double GetFlightTime() const;


private:
    // your code
    // implemented by Justin 
    double depTime;
    double arrTime;
    int maxPass;
    std::string src;
    std::string dest;
};

#endif /* ECFlight_h */
