// functions.h
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <vector>
using namespace std;

struct coordinates
{
    int x;
    int y;
};

vector<coordinates> parseRockCoordinates(vector<string> rockPathLines)
{

    vector<coordinates> allRockCoordinates;
    string rockPathLine;
    for (const auto &rockPathL : rockPathLines)
    {
        rockPathLine = rockPathL;
        // get only the coordinates in a vector
        string delimiter = " -> ";
        size_t pos = 0;
        vector<coordinates> oneLineRockCoordinates;
        string token,x,y;

        coordinates tmp;

        while ((pos = rockPathLine.find(delimiter)) != std::string::npos)
        {
            token = rockPathLine.substr(0, pos);                                            // copy
            std::cout << token << std::endl;
            rockPathLine.erase(pos-token.length(), delimiter.length()+token.length());      // remove delimiter 
            
            // Transform token to coordinates and push to the vector
            x = token.substr(0,token.find(","));
            tmp.x = stoi(x);
            cout << "x: " << tmp.x << "\n";
            y = token.substr(token.find(",")+1,token.length()-x.length());
            cout << "y: " << y << "\n";
            tmp.y = stoi(y);

            oneLineRockCoordinates.push_back(tmp);
        }
        token = rockPathLine;
        x = token.substr(0, token.find(","));
        tmp.x = stoi(x);
        cout << "x: " << tmp.x << "\n";
        y = token.substr(token.find(",") + 1, token.length() - x.length());
        cout << "y: " << y << "\n";
        tmp.y = stoi(y);

        oneLineRockCoordinates.push_back(tmp);

        // With the one line coordinates, create all the coordinates inbetween and copy to allRockCoordinates
    }

    return allRockCoordinates;
}

#endif