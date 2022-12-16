// functions.h
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <vector>
#include <algorithm>    // for "count_if()"
using namespace std;

struct coordinates
{
    int x;
    int y;
};

vector<coordinates> parseRockCoordinates(vector<string> rockPathLines);

vector<coordinates> stringLineToCoordinates(string rockPathLine, string delimiter);

coordinates smallestCoordinates(vector<coordinates> rockCoordinates);
void printMap(vector<coordinates> rockCoordinates);
void printMap(vector<coordinates> rockCoordinates, vector<coordinates> sandCoordinates);

coordinates addNewGrain(vector<coordinates> allRockCoordinates, vector<coordinates> allSandCoordinates, int floorY);

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
        vector<coordinates> oneLineRockCoordinates = stringLineToCoordinates(rockPathLine, " -> ");

        coordinates tmpCoordinates;

        // With the one line coordinates, create all the coordinates in between and copy to allRockCoordinates
        coordinates previous = oneLineRockCoordinates.at(0);
        for(const auto coord : oneLineRockCoordinates){
            //cout << coord.x << "," << coord.y << "\n";
            // There is no diagonal lines (tested)

            if (coord.x != previous.x){    
                tmpCoordinates.y = coord.y;                                                   
                if(previous.x < coord.x){
                    for(int i=previous.x; i<=coord.x; i++){
                        tmpCoordinates.x = i;
                        allRockCoordinates.push_back(tmpCoordinates);
                    }
                }
                else{ // when previous is bigger than coord
                    for(int i=coord.x; i<=previous.x; i++){
                        tmpCoordinates.x = i;
                        allRockCoordinates.push_back(tmpCoordinates);
                    }

                }
            }
            if (coord.y != previous.y){
                tmpCoordinates.x = coord.x;
                if(previous.y < coord.y){
                    for(int i=previous.y; i<=coord.y; i++){
                        tmpCoordinates.y = i;
                        allRockCoordinates.push_back(tmpCoordinates);
                    }
                }
                else{ // when previous is bigger than coord
                    for(int i=coord.y; i<=previous.y; i++){
                        tmpCoordinates.y = i;
                        allRockCoordinates.push_back(tmpCoordinates);
                    }

                }
            }

            previous = coord;
        }

    }

    return allRockCoordinates;
}

vector<coordinates> stringLineToCoordinates(string rockPathLine, string delimiter){

    vector<coordinates> oneLineCoordinates;
    size_t pos = 0;
    string token, x, y;

    coordinates tmpCoordinates;

    // iterate through each string describing a pair of coordinates and add to the vector of coordinates
    while ((pos = rockPathLine.find(delimiter)) != std::string::npos)
    {
        token = rockPathLine.substr(0, pos);                                           // copy
        rockPathLine.erase(pos - token.length(), delimiter.length() + token.length()); // remove copied part and delimiter

        // Transform token to coordinates and push to the vector
        x = token.substr(0, token.find(","));                               // copy x coordinate
        tmpCoordinates.x = stoi(x);                                         // transform to int
        y = token.substr(token.find(",") + 1, token.length() - x.length()); // copy y coordinate
        tmpCoordinates.y = stoi(y);

        oneLineCoordinates.push_back(tmpCoordinates);
    }
    // remaining string describing the last pair of coordinates of the line
    token = rockPathLine;
    x = token.substr(0, token.find(","));
    tmpCoordinates.x = stoi(x);
    y = token.substr(token.find(",") + 1, token.length() - x.length());
    tmpCoordinates.y = stoi(y);

    oneLineCoordinates.push_back(tmpCoordinates);

    return oneLineCoordinates;
}

// returns the smallest and biggest coordinates
vector<coordinates> absoluteCoordinates(vector<coordinates> rockCoordinates){
    vector<coordinates> absolute;
    absolute.push_back(rockCoordinates.at(0)); //smallest
    absolute.push_back(rockCoordinates.at(0)); //biggest

    for (auto rockC : rockCoordinates){
        if(rockC.x < absolute.at(0).x) absolute.at(0).x = rockC.x;
        else if(rockC.x > absolute.at(1).x) absolute.at(1).x = rockC.x;
        if(rockC.y < absolute.at(0).y) absolute.at(0).y = rockC.y;
        else if(rockC.y > absolute.at(1).y) absolute.at(1).y = rockC.y;
    }

    return absolute;
}

void printMap(vector<coordinates> rockCoordinates){
    
    // find the biggest and smallest x and y
    coordinates smallest, biggest;
    vector<coordinates> absoluteCoords = absoluteCoordinates(rockCoordinates);
    
    smallest = absoluteCoords.at(0);
    biggest = absoluteCoords.at(1);

    cout << "Smallest (x,y): (" << smallest.x << "," << smallest.y << ")\n";
    cout << "Biggest (x,y): (" << biggest.x << "," << biggest.y << ")\n";

    // print the source of sand (in x=500)
    cout << "0 ";
    for(int x = smallest.x; x <= biggest.x; x++){
        if(x == 500){
            cout << "+";
        }
        else{
            cout << ".";
        }
    }
    cout << "\n";

    // go from smallest y (then from smallest x and print rock or air)
    for (int y = 1; y <= biggest.y; y++){
        cout << y << " ";
        for (int x = smallest.x; x <= biggest.x; x++){
            // use lambda expression to check coordinates type
            if(count_if(rockCoordinates.begin(), rockCoordinates.end(),[&](const coordinates& c){
                return (c.x == x && c.y == y);
            })){
                cout << "#";
            }
            else{
                cout << ".";
            }
        }
        cout << "\n";
    }

}

void printMap(vector<coordinates> rockCoordinates, vector<coordinates> sandCoordinates){
    //cout << "printMap" << " with sand\n";
    // find the biggest and smallest x and y
    coordinates smallest, biggest;
    vector<coordinates> absoluteCoords = absoluteCoordinates(rockCoordinates);
    
    smallest = absoluteCoords.at(0);
    biggest = absoluteCoords.at(1);

    //cout << "Smallest (x,y): (" << smallest.x << "," << smallest.y << ")\n";
    //cout << "Biggest (x,y): (" << biggest.x << "," << biggest.y << ")\n";

    // print the source of sand (in x=500)
    cout << "0 ";
    for(int x = smallest.x; x <= biggest.x; x++){
        if(x == 500){
            cout << "+";
        }
        else{
            cout << ".";
        }
    }
    cout << "\n";

    // go from smallest y (then from smallest x and print rock or air)
    for (int y = 1; y <= biggest.y; y++){
        cout << y << " ";
        for (int x = smallest.x; x <= biggest.x; x++){
            // use lambda expression to check coordinates type
            if(count_if(rockCoordinates.begin(), rockCoordinates.end(),[&](const coordinates& c){
                return (c.x == x && c.y == y);
            })){
                cout << "#";
            }
            else if(count_if(sandCoordinates.begin(), sandCoordinates.end(),[&](const coordinates& c){
                return (c.x == x && c.y == y);
            })){
                cout << "O";
            }
            else{
                cout << ".";
            }
        }
        cout << "\n";
    }

}

coordinates addNewGrain(vector<coordinates> allRockCoordinates, vector<coordinates> allSandCoordinates, int floorY)
{
    coordinates newGrain;
    newGrain.x = 500;
    newGrain.y = 0;
    bool settled{false};

    // while it doesn't settle, let it fall
    for (newGrain.y = 0; !settled && newGrain.y <= floorY; newGrain.y++)
    {

        // if something under (else do nothing, y position increases with the loop)
        if (count_if(allRockCoordinates.begin(), allRockCoordinates.end(), [&](const coordinates &c) { // a
                return (c.y == newGrain.y + 1 && c.x == newGrain.x);                                   // very
            }) ||
            count_if(allSandCoordinates.begin(), allSandCoordinates.end(), [&](const coordinates &c) { // long
                return (c.y == newGrain.y + 1 && c.x == newGrain.x);                                   // if statement
            }))
        {

            // and if something under and to the left (else move left)
            if (count_if(allRockCoordinates.begin(), allRockCoordinates.end(), [&](const coordinates &c)
                         { return (c.y == newGrain.y + 1 && c.x == newGrain.x - 1); }) ||
                count_if(allSandCoordinates.begin(), allSandCoordinates.end(), [&](const coordinates &c)
                         { return (c.y == newGrain.y + 1 && c.x == newGrain.x - 1); }))
            {

                // and if somehing under and to the right (else move right)
                if (count_if(allRockCoordinates.begin(), allRockCoordinates.end(), [&](const coordinates &c)
                             { return (c.y == newGrain.y + 1 && c.x == newGrain.x + 1); }) ||
                    count_if(allSandCoordinates.begin(), allSandCoordinates.end(), [&](const coordinates &c)
                             { return (c.y == newGrain.y + 1 && c.x == newGrain.x + 1); }))
                {

                    // Settle
                    settled = true;
                }
                else
                {
                    newGrain.x++;
                }
            }
            else
            {
                newGrain.x--;
            }
        }
    }
    
    newGrain.y--;
    return newGrain;
}

#endif