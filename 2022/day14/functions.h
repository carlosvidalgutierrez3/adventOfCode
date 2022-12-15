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

// returns all the cordinates that are rocks. Parameter: strings that describe a single path of rock each
vector<coordinates> parseRockCoordinates(vector<string> rockPathLines)
{

    vector<coordinates> allRockCoordinates;
    string rockPathLine;

    // iterate through each string describing rock path lines
    for (const auto &rockPathL : rockPathLines)                                         
    {
        // copy the value of the reference, to be able to edit it
        rockPathLine = rockPathL;           

        string delimiter = " -> ";
        size_t pos = 0;
        vector<coordinates> oneLineRockCoordinates;
        string token,x,y;

        coordinates tmpCoordinates;

        // iterate through each string describing a pair of coordinates and add to the vector of coordinates
        while ((pos = rockPathLine.find(delimiter)) != std::string::npos)
        {
            token = rockPathLine.substr(0, pos);                                            // copy
            rockPathLine.erase(pos-token.length(), delimiter.length()+token.length());      // remove copied part and delimiter 
            
            // Transform token to coordinates and push to the vector
            x = token.substr(0,token.find(","));                                            // copy x coordinate
            tmpCoordinates.x = stoi(x);                                                     // transform to int
            y = token.substr(token.find(",")+1,token.length()-x.length());                  // copy y coordinate
            tmpCoordinates.y = stoi(y);

            oneLineRockCoordinates.push_back(tmpCoordinates);
        }
        // remaining string describing the last pair of coordinates of the line
        token = rockPathLine;
        x = token.substr(0, token.find(","));
        tmpCoordinates.x = stoi(x);
        y = token.substr(token.find(",") + 1, token.length() - x.length());
        tmpCoordinates.y = stoi(y);

        oneLineRockCoordinates.push_back(tmpCoordinates);

        // With the one line coordinates, create all the coordinates in between and copy to allRockCoordinates
        coordinates previous = oneLineRockCoordinates.at(0);
        for(const auto coord : oneLineRockCoordinates){
            //cout << coord.x << "," << coord.y << "\n";
            // There is no diagonal lines (tested)

            if (coord.x != previous.x){
                cout << "Horizontal\n";     
                tmpCoordinates.y = coord.y;                                                   
                if(previous.x < coord.x){
                    for(int i=previous.x; i<=coord.x; i++){
                        tmpCoordinates.x = i;
                        allRockCoordinates.push_back(tmpCoordinates);
                        
                        cout << "new " << allRockCoordinates.at(allRockCoordinates.size()-1).x << "," << allRockCoordinates.at(allRockCoordinates.size()-1).y << "\n";
                    }
                }
                else{ // when previous is bigger than coord
                    for(int i=coord.x; i<=previous.x; i++){
                        tmpCoordinates.x = i;
                        allRockCoordinates.push_back(tmpCoordinates);
                        
                        cout << "new " << allRockCoordinates.at(allRockCoordinates.size()-1).x << "," << allRockCoordinates.at(allRockCoordinates.size()-1).y << "\n";
                    }

                }
            }
            if (coord.y != previous.y){
                cout << "Vertical\n";
                tmpCoordinates.x = coord.x;
                if(previous.y < coord.y){
                    for(int i=previous.y; i<=coord.y; i++){
                        tmpCoordinates.y = i;
                        allRockCoordinates.push_back(tmpCoordinates);
                        
                        cout << "new " << allRockCoordinates.at(allRockCoordinates.size()-1).x << "," << allRockCoordinates.at(allRockCoordinates.size()-1).y << "\n";
                    }
                }
                else{ // when previous is bigger than coord
                    for(int i=coord.y; i<=previous.y; i++){
                        tmpCoordinates.y = i;
                        allRockCoordinates.push_back(tmpCoordinates);
                        
                        cout << "new " << allRockCoordinates.at(allRockCoordinates.size()-1).x << "," << allRockCoordinates.at(allRockCoordinates.size()-1).y << "\n";
                    }

                }
            }

            previous = coord;
        }

    }

    return allRockCoordinates;
}

#endif