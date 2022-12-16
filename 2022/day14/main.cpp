#include <fstream>
#include <iostream>
#include <vector>
#include "functions.h"

using namespace std;

int main()
{
    fstream fileIn("input.txt");

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

    // while sand not overflowing last layer of rock, keep adding sand
    coordinates newGrainSettledPosition;
    newGrainSettledPosition.x = 500;
    newGrainSettledPosition.y = 1;
    vector<coordinates> allSandCoordinates;
    int floorY = absoluteCoordinates(allRockCoordinates).at(1).y;
    cout << "floorY: " << floorY << endl;

    // Uncomment here to see the map with a specific number of grains (number in the for)
    /*
    for(int i=0; i<700; i++){
        newGrainSettledPosition = addNewGrain(allRockCoordinates, allSandCoordinates, floorY);
        allSandCoordinates.push_back(newGrainSettledPosition);
    }
    printMap(allRockCoordinates, allSandCoordinates);
    */

    int nGrains = 0;
    
    while(newGrainSettledPosition.y < floorY){
        newGrainSettledPosition = addNewGrain(allRockCoordinates, allSandCoordinates, floorY);
        allSandCoordinates.push_back(newGrainSettledPosition);
        nGrains++;
    }
    nGrains-1;

    printMap(allRockCoordinates, allSandCoordinates);
    
    // result of the challenge
    cout << "nGrains: " << nGrains << endl;
    

    return 0;
}

