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
        cout << lineBuffer << "\n";
        lines.push_back(move(lineBuffer));
    }

    // Get all rock coordinates
    vector<coordinates> allRockCoordinates = parseRockCoordinates(lines);

    // printMap with rock only
    printMap(allRockCoordinates);

    // while sand not overflowing last layer of rock, keep adding sand
    coordinates newGrainSettledPosition;
    newGrainSettledPosition.x = 500;
    newGrainSettledPosition.y = 0;
    vector<coordinates> allSandCoordinates;

    int floorY = absoluteCoordinates(allRockCoordinates).at(1).y;
    while(newGrainSettledPosition.y < floorY){
        newGrainSettledPosition = addNewGrain(allRockCoordinates, allSandCoordinates);
    }

    return 0;
}

