//
//  ECConsoleUIListBox.cpp
//  
//
//  Created by Yufeng Wu on 5/23/23.
//

#include "ECConsoleUIListBox.h"
#include "ECConsoleUITextLabel.h"


// declared in .h file by prof, but fully defined by Justin Hasler
ECConsoleUIListBox :: ECConsoleUIListBox(int xUL, int yUL, int xLR, int yLR ) 
: ECConsoleUIItem(xUL, yUL, xLR, yLR),
indexChoice(0), handlingKeys(1)
{} 



void ECConsoleUIListBox::AddChoice(const std::string &text)
{
	choices.push_back(text);
	// is dis correcto?
	// yes
}

bool inBounds(int idxChoice, int size)
{
	if(idxChoice >= 0 && idxChoice < size)
		return true;
	return false;
}

// Choose an item
void ECConsoleUIListBox::Choose(int rIndex)
{
	if(inBounds(rIndex, choices.size()))
		indexChoice = rIndex;
}

void ECConsoleUIListBox::rowInit(int &rows, int &firstRow) const
{
	if(rows < choices.size())
	{
			
		firstRow = indexChoice - rows/ 2; 
	
		if(firstRow < 0)
		{
			firstRow = 0; // set to 0 if it goes too far
		}
		
			//
		else if(firstRow + rows > choices.size())
		{
			firstRow = choices.size() - rows;
		}
		
		// say we're at [2], we want [0] to be top and we're selecting [1]
		// 0 = 1 + (3/2) - ((rows-1)/2)

		// new eq
		// 0 = 1 + (2/2) - 
			// i cant do it scroll is just a little weird
	}
}

int ECConsoleUIListBox::GetRowIndex() const
{
    if (indexChoice != -1) {
        // Calculate the number of rows that can be displayed in the list box
        int rows = GetYLR() - GetYUL() + 1;

        int firstRow = 0;
        rowInit(rows, firstRow);
        // Check if the indexChoice is within the visible range
        if (indexChoice >= firstRow && indexChoice < firstRow + rows) 
        {
            // Calculate the row index of the highlighted choice
            int rowIndex = indexChoice - firstRow;
            return rowIndex;
        }
    }
    return -1;
}
// So we need to override the function from the ECConsoleUIItem
// Get displayed text at a specific row
// Text is relative to the item portion (i.e., relative to (xLR, yLR))
std::string ECConsoleUIListBox::GetTextAtRow(int r) const
{
	std::string res;

	int rows  = GetHeight();
	int firstRow = 0;

	rowInit(rows, firstRow);

	if(IsIntersectingRow(r))
	{
		int offset = r - GetYUL();
		int idxChoice = firstRow + offset;
		if(inBounds(idxChoice, choices.size()))
		{
			res = choices[idxChoice];
		}
	}	
	return res;
}
// Get highlighted part (if any); return the row with highlight
// if one, return -1; also store the highlightd portion (yLeft, yRight) of this row
// Assume: at most a single row with highlighted part


int ECConsoleUIListBox::GetHighlightPosition(int &xLeft, int &xRight) const
{
	if(indexChoice != -1)
	{
		int rows = GetHeight();
		int firstRow = 0;

		rowInit(rows, firstRow);

		if(indexChoice >= firstRow && indexChoice < firstRow + rows)
		{
			int rowIndex = indexChoice - firstRow; // find offset

			xLeft = 0; // left is always 0
			xRight = GetXUL() + 1; // idk why xright = getxul but it works
			// i would get to know how XUL and XLR work better, but
			// im lazy
			return rowIndex;
		}
	}
	return -1; // we return highlight but also return -1?


}



void ECConsoleUIListBox::HdlKeyUp() {
	if(indexChoice > 0)
	{
		indexChoice--;
	}
}
// Handle down key
void ECConsoleUIListBox::HdlKeyDown() {
	if(indexChoice < choices.size() - 1)
	{
		indexChoice++;
	}
}

