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


    return 0;
}

