// Test code for console UI
#include "ECTextViewImp.h"
#include "ECConsoleUIView.h"
#include "ECConsoleUITextLabel.h"
#include "ECConsoleUIListBox.h"
#include "ECConsoleUIButton.h"
#include "ECFlight.h"
#include "ECAirport.h"


#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace  std;

// implemented by Justin Hasler
void ReadAirportFlightData(const std::string &input, ECAirlineSimulator &sim, std::vector<std::string> &codes,std::vector<std::string>& descs,std::vector<std::tuple<std::string, std::string, double>>& distancesBtw,std::vector<std::tuple<std::string, std::string, double, int, int>>& flights)
{
    std::ifstream file(input);
    std::string line;
    while (std::getline(file, line)) 
    {
        if (line.empty() || line[0] == '#')  // ignore empty and # lines
            continue; 
        
        std::istringstream iss(line);
        int info;
        iss >> info;
        if (info == 1) 
        {
            // code and desc
            std::string code, desc; // airport code and desc

            iss >> code >> std::ws >> desc; // code first word, then whitespace, then desc is rest of line

            codes.push_back(code);
            descs.push_back(desc);
            sim.AddAirport(desc, code);
        } 
        else if (info == 2) 
        {
            // distance
            std::string src, dest;
            double dist;
            iss >> src >> dest >> dist;
            distancesBtw.emplace_back(src, dest, dist); // have to use emplace for multiple elements
            sim.SetDistBtwAirports(src, dest, dist);
        }
        else if (info == 3) {
            // flights
            std::string src, dest;
            double time;
            int maxPass, price;
            iss >> src >> dest >> time >> maxPass >> price;
            sim.AddFlight(src,dest,time,maxPass,price);
        }
    }
}
// construct a simple UI
static void Test1(ECConsoleUIView &viewUI, ECAirlineSimulator &sim, 
                    std::vector<std::string> codes,
                    std::vector<std::string> descs,
                    std::vector<std::tuple<std::string, std::string, double, int, int>> flights)
{
    // create several labels
    ECConsoleUITextLabel *pl1 = new ECConsoleUITextLabel(30, 1, "United Blue Spirit Delta Airlines");
    pl1->SetHighlight(true);
    viewUI.AddUIItem(pl1);
    ECConsoleUITextLabel *pl2 = new ECConsoleUITextLabel(15, 5, "FROM:");
    viewUI.AddUIItem(pl2);

    // Create a border
    string horizBar;
    for(int i=0; i<viewUI.GetColNumInView(); ++i)
    {
        horizBar += '~';
    }

    ECConsoleUITextLabel *pl4 = new ECConsoleUITextLabel(0, 0, horizBar);
    viewUI.AddUIItem(pl4);
    ECConsoleUITextLabel *pl5 = new ECConsoleUITextLabel(0, viewUI.GetRowNumInView()-1, horizBar);
    viewUI.AddUIItem(pl5);

    ECConsoleUIListBox *from_codesUI = new ECConsoleUIListBox(15, 7, 45, 9 );
    for (int i=0; i < codes.size(); ++i){
        from_codesUI->AddChoice(codes[i]);
    }
    from_codesUI->Choose(0);
    viewUI.AddUIItem(from_codesUI);

    ECConsoleUITextLabel *to = new ECConsoleUITextLabel(15, 13, "TO:");
    viewUI.AddUIItem(to);

    ECConsoleUIListBox *to_codesUI = new ECConsoleUIListBox(15, 15, 30, 17 );
    for (int i=0; i < codes.size(); ++i)
    {
        to_codesUI->AddChoice(codes[i]);
    }
    to_codesUI->Choose(0);
    viewUI.AddUIItem(to_codesUI);

    ECConsoleUITextLabel *pl7 = new ECConsoleUITextLabel(50, 13, "Possible Flights");
    viewUI.AddUIItem(pl7); //15, 7, 45, 9            // 50 

    ECConsoleUIListBox *itineraries = new ECConsoleUIListBox(50, 15, 110, 22);
    itineraries->Choose(0);
    
                               
    ECConsoleUIButton *book_button = new ECConsoleUIButton(50,7,65,9, "SEARCH", *from_codesUI, *to_codesUI, *itineraries, sim);
    viewUI.AddUIItem(book_button);
    viewUI.AddUIItem(itineraries); 

}

int main(int argc, char *argv[])
{
    // implemented by Justin Hasler (slightly modified from Prof's code)
    std::vector<std::string> codes;
    std::vector<std::string> descs;
    std::vector<std::tuple<std::string, std::string, double>> distancesBtw;
    std::vector<std::tuple<std::string, std::string, double, int, int>> flights;
    ECAirlineSimulator sim;

    ReadAirportFlightData(argv[1], sim, codes, descs, distancesBtw, flights);
    // argv[1] reads the file name 
    /* we build with 
     g++ ECConsoleUITextLabel.cpp ECTextViewImp.cpp ECConsoleUIView.cpp 
     ECConsoleUIListBox.cpp ECAirlineFinancial.cpp ECAirlineOperation.cpp 
     ECAirlineSimulator.cpp ECAirport.cpp ECFlight.cpp ECFlightItinerary.cpp 
     ECAirlineTicketing.cpp ECConsoleUIButton.cpp ECConsoleUITest.cpp -o test -std=c++11

     then run like ./test input.txt

    */
    ECTextViewImp wndTest;

    // add a status bar
    wndTest.AddStatusRow("UI test", "For demo only", true);
    
    // Create a console UI view
    ECConsoleUIView viewUI(&wndTest);
    
    // Add a few UI items
    Test1(viewUI, sim, codes, descs,flights);
    
    // Display it
    viewUI.Refresh();
    
    // Show the window
    try {
        wndTest.Show();
    }
    catch(std::string ex)
    {
        cout << "Exception: " << ex << endl;
    }
    return 0;
}
