//
//  ECConsoleUIButton.cpp
//  
//
//  Created by Yufeng Wu on 3/6/24.
#include <iostream>
#include <set>


#include "ECConsoleUIButton.h"
#include "ECConsoleUIListBox.h"
#include "ECAirlineSimulator.h"
#include "ECFlightItinerary.h"


//*****************************************************************************
// Console UI button: 

// specifiy the portion of the view for this list box
ECConsoleUIButton :: ECConsoleUIButton(int xUL, int yUL, int xLR, int yLR, const std::string &strButIn, ECConsoleUIListBox &box1, ECConsoleUIListBox &box2,  ECConsoleUIListBox &box3, ECAirlineSimulator &sim ) : ECConsoleUIItem(xUL, yUL, xLR, yLR), strButton(strButIn), box1(box1), box2(box2), box3(box3),sim(sim)
{                                                                           // is strbutin just button name
}

// Get displayed text at a specific row
// Text is relative to the item portion (i.e., relative to (xLR, yLR))
std::string ECConsoleUIButton :: GetTextAtRow(int r) const
{
    // there is only one line
    std::string str;
    int rconv = r - GetYUL();

    if( rconv <0 || /*rconv >= 1 ||*/ rconv >= GetHeight() )
    {
        return str;
    }

    // add a row of '----' right above/below
    if( rconv == 0 || rconv == GetHeight()-1 )
    {
        str += '+';
        for( int i=1 ; i<GetWidth() - 1; ++i)
        {
            str += '-';
        }
        str += '+';
    }
    else
    {
        // begin with a '|'
        //str += '|';

        // align to the center
        if( strButton.size() < GetWidth())
        {
            str += '|';
            for(int i=1; i < (GetWidth()- strButton.size())/2; ++i )
            {
                str += ' ';
            }
        }

        str += strButton;
        for(int i=1; i < (GetWidth()- strButton.size())/2; ++i )
            {
                str += ' ';
            }
            str += '|';

        // end with a '|'
        //str += '|';
    }

    // ensure the str is not too long
    str = str.substr(0, GetWidth());
    return str;
}

// Get highlighted part (if any); return the row with highlight
// if one, return -1; also store the highlightd portion (yLeft, yRight) of this row
// Assume: at most a single row with highlighted part
int ECConsoleUIButton :: GetHighlightPosition(int &xLeft, int &xRight) const
{
    return -1;
    // i guess we dont addd anything to this
}

// handle enter key
// implemented by Justin Hasler
void ECConsoleUIButton :: HdlKeyEnter()
{
    box3.clear(); // clear last entry to create new itinerary
    // search for flights between the two choices
    int choice1 = box1.GetRowIndex() + box1.GetYUL();
    int choice2 = box2.GetRowIndex() + box2.GetYUL();

    std::string choice1_text = box1.GetTextAtRow(choice1);
    std::string choice2_text = box2.GetTextAtRow(choice2);

    if(choice1_text == choice2_text)
        box3.AddChoice("waste of money");

    std::vector<ECFlightItinerary> itinList;
    

    sim.SearchForFlights(choice1_text, choice2_text, itinList);

    if(!itinList.empty())
    {
        std::set<std::string> noDups; // need set so we dont havce duplicate entries
        for(auto itin : itinList)
            for(int i = 0; i < itin.GetNumSegments(); ++i)
                noDups.emplace(itin.Info(i));

        for(auto stuff : noDups)
            box3.AddChoice(stuff);
    }
    else
        box3.AddChoice("No flights found"); // no flights
}


