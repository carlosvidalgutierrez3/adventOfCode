#include <fstream>
#include <iostream>

using namespace std;

int main(){
    fstream fileIn("input.txt");
    string lineBuffer;

    int calories{0};
    int mostTotalCalories{0};

    while (getline(fileIn, lineBuffer))
    {
        //cout << lineBuffer;
        if(lineBuffer.compare("") != 0){
            calories = calories + stoi(lineBuffer);
            //cout << "\n";
        }
        else{
            //cout << "Total: " << calories << "\n\nNew Elf!\n";
            if(calories > mostTotalCalories){
                mostTotalCalories = calories;
            }
            calories = 0;
        }
    }
    //cout << "Total: " << calories << "\n\nNew Elf!\n";
    if (calories > mostTotalCalories){
        mostTotalCalories = calories;
    }

    cout << "Most calories carried by one elf: " << mostTotalCalories << "\n";

    return 0;
}