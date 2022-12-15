#include <fstream>
#include <iostream>
#include <vector>

int main()
{
    //namespace CurrentDay = AdventOfCode::Year2022::Day14;

    std::fstream fileIn("input_example.txt");

    std::string lineBuffer;
    std::vector<std::string> lines;
    while (std::getline(fileIn, lineBuffer))
    {   
        std::cout << lineBuffer << "\n";
        lines.push_back(std::move(lineBuffer));
    }
    return 0;
}