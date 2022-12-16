#include <fstream>
#include <iostream>
#include <vector>
#include "functions.h"

using namespace std;

int main()
{
    fstream fileIn("input_example.txt");

    string lineBuffer;
    vector<string> lines;
    while (getline(fileIn, lineBuffer))
    {
        //cout << lineBuffer << "\n";
        lines.push_back(move(lineBuffer));
    }

    // Get all rock coordinates
    vector<coordinates> allRockCoordinates = parseRockCoordinates(lines);

    // printMap with rock only
    //printMap(allRockCoordinates);

    coordinates newGrainSettledPosition;
    newGrainSettledPosition.x = 500;
    newGrainSettledPosition.y = 1;
    vector<coordinates> allSandCoordinates;
    int floorY = absoluteCoordinates(allRockCoordinates).at(1).y;   // get the coordinate y of the lowest rock
    //cout << "floorY: " << floorY << endl;

    // Uncomment here to see the map with a specific number of grains (number of iterations in the loop)
    /*
    for(int i=0; i<100; i++){
        newGrainSettledPosition = addNewGrain(allRockCoordinates, allSandCoordinates, floorY);
        allSandCoordinates.push_back(newGrainSettledPosition);
    }
    printMap(allRockCoordinates, allSandCoordinates);
    */

    int nGrains = 0;
    
    // while sand not overflowing last layer of rock, keep adding sand
    while(newGrainSettledPosition.y < floorY){
        newGrainSettledPosition = addNewGrain(allRockCoordinates, allSandCoordinates, floorY);
        allSandCoordinates.push_back(newGrainSettledPosition);
        nGrains++;
    }
    nGrains--;  // first grain to overflow

    printMap(allRockCoordinates, allSandCoordinates);
    
    // result of the challenge
    cout << "nGrains: " << nGrains << endl;
    

    return 0;
}

