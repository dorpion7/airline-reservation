//
//  ECAirport.h
//  
//
//  Created by Yufeng Wu on 5/11/23.
//

#ifndef ECAirport_h
#define ECAirport_h

#include <string>
#include <set>
#include <map>
#include <vector>

// ****************************************************************************
// Airport: start/end point of a flight

class ECAirport 
{
public:
    // by default, airport is operating (except in default constructor)
    ECAirport()/* : operating(false)*/{}  
    virtual ~ECAirport(){}
    ECAirport(const std::string &nameAP, const std::string &codeIATA) : name(nameAP), code(codeIATA), operating(false){}

    ECAirport(const ECAirport &rhs);
    
    // Get the name of the airport
    std::string GetName() const;
    
    // Get IATA code
    std::string GetCode() const;
    
    // Operating status: is it operating normally?
    bool IsOperating();
    
    // Set operating status
    void SetOperating(bool f);
    
private:
    // your ocde
    // implemented by Justin 
    bool operating;
    std::string name;
    std::string code;
};

// ****************************************************************************
// Airport info: access airport information
// Use singleton pattern

class ECAirportInfo
{
public:
    // implemented by Justin 
    static ECAirportInfo& Instance()
    {
        static ECAirportInfo inst;
        return inst;
    }
    
    // Create a new airport in the system
    void CreateAirport(const std::string &name, const std::string &code);
    
    // Get airport by code
    // Throw exception (std::string) if there is no airport with the code
    ECAirport &GetAirport(const std::string &code);
    
    // Set distance (in miles) between airports
    void SetDistanceBtw(const std::string &ap1Code, const std::string &ap2Code, int dist);
    
    int getDist(const std::string &src, const std::string &dest);

private:
   // your code 
    ECAirportInfo(){}
    // implemented by Justin 
    //static ECAirportInfo *pInst;
    // static ECAirportInfo *pInst; dont need this if inst is initialized in Instance()
    std::map<std::string, ECAirport> ports; // set of airports 
    std::map<std::pair<std::string,std::string>, int> distancesBtw;

    // tuple of two airport codes then the dist btwn
};


#endif /* ECAirport_h */
