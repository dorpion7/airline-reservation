//
//  ECConsoleUIListBox.h
//  
//
//  Created by Yufeng Wu on 5/23/23.
//

#ifndef ECConsoleUIListBox_h
#define ECConsoleUIListBox_h

#include <string>
#include <vector>

#include "ECConsoleUIItem.h"
#include "ECConsoleUITextLabel.h"

//*****************************************************************************
// Console UI list box: several rows (items) to choose from

class ECConsoleUIListBox : public ECConsoleUIItem
{
public:
    // specifiy the portion of the view for this list box
    ECConsoleUIListBox(int xUL, int yUL, int xLR, int yLR );
    
    // Add a choice item
    void AddChoice(const std::string &text);
    
    // Choose an item
    void Choose(int rIndex);
    
    // Get the chosen one
    int GetChoice() const { return indexChoice; }
    
    // Get displayed text at a specific row
    // Text is relative to the item portion (i.e., relative to (xLR, yLR))
    virtual std::string GetTextAtRow(int r) const override ;
    
    // Get highlighted part (if any); return the row with highlight
    // if one, return -1; also store the highlightd portion (yLeft, yRight) of this row
    // Assume: at most a single row with highlighted part
    virtual int GetHighlightPosition(int &xLeft, int &xRight) const override ;

    // Are there any other function you might need to override?
    // ok this means override the function i get it you goober
    virtual void HdlKeyUp() override;
    // Handle down key
    virtual void HdlKeyDown() override;
    // Handle enter key
    //virtual void HdlKeyEnter() override;
    // Handle other keys
    //virtual void HdlOtherKey() override;

    virtual bool IsHandlingKeys() const override { return handlingKeys; }

    // implemented by Justin 
    virtual void rowInit(int &rows, int &firstRow) const;

    // implemented by Justin 
    int GetRowIndex() const;

    // implemented by Justin 
    void clear(){choices.clear();} // clear vector for if we click enter to show valid itineraries

private:
    // implemented by Justin 
    std::vector<std::string> choices;
    int indexChoice;
    int xUL, yUL, xLR, yLR;
    bool handlingKeys; 

};

#endif /* ECConsoleUIListBox_h */
