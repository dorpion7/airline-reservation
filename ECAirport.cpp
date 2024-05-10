
//  ECAirport.cpp
//  
//
//  Created by Yufeng Wu on 5/11/23.
//

#include "ECAirport.h"
#include <set>
#include <vector>
#include <iostream>
// ECAirport
using namespace std;

// all declared in .h but fully defined by Justin Hasler
// should an airport be running by default?
ECAirport::ECAirport(const ECAirport &rhs)
{
	name = rhs.name;
	operating = rhs.operating;
	code = rhs.code;
}
// Get the name of the airport
std::string ECAirport :: GetName() const
{
	return name;
}

// Get IATA code
std::string ECAirport :: GetCode() const
{
	return code;
}

// Operating status: is it operating normally?
bool ECAirport :: IsOperating()
{
	return operating;
}

// Set operating status
void ECAirport :: SetOperating(bool f)
{
	operating = f;
}
  
// ECAirportInfo
void ECAirportInfo :: CreateAirport(const std::string &name, const std::string &code)
{
	ports[code] = ECAirport(name, code);
}
    
// Get airport by code
// Throw exception (std::string) if there is no airport with the code
ECAirport& ECAirportInfo::GetAirport(const std::string &code)
{
	//ECAirportInfo& airportInfo = ECAirportInfo::Instance();
	map<std::string, ECAirport>::iterator itr;
    for (itr = ports.begin(); itr != ports.end(); ++itr) {
        if (itr->first == code)
        	return itr->second;
    }
    	throw ("Airport not found");
}

// Set distance (in miles) between airports
void ECAirportInfo :: SetDistanceBtw(const std::string &ap1Code, const std::string &ap2Code, int dist)
{
	
	distancesBtw[std::make_pair(ap1Code, ap2Code)] = dist;
	distancesBtw[std::make_pair(ap2Code, ap1Code)] = dist;
}

int ECAirportInfo :: getDist(const std::string &src, const std::string &dest)
{
	return distancesBtw[(std::make_pair(src, dest))];
}



