// part two of the challenge
#include <fstream>
#include <iostream>

using namespace std;

int main(){
    fstream fileIn("input.txt");
    string lineBuffer;

    int calories{0};
    int FirstMostTotalCalories{0};
    int SecondMostTotalCalories{0};
    int ThirdMostTotalCalories{0};
    
    while (getline(fileIn, lineBuffer))
    {
        //cout << lineBuffer;
        if(lineBuffer.compare("") != 0){
            calories = calories + stoi(lineBuffer);
            //cout << "\n";
        }
        else{
            //cout << "Total: " << calories << "\n\nNew Elf!\n";
            if(calories > ThirdMostTotalCalories){
                if(calories > SecondMostTotalCalories){
                    if(calories > FirstMostTotalCalories){
                        ThirdMostTotalCalories = SecondMostTotalCalories;
                        SecondMostTotalCalories = FirstMostTotalCalories;
                        FirstMostTotalCalories = calories;
                        cout << "1MC: " << FirstMostTotalCalories << "\n";
                    }
                    else{
                        ThirdMostTotalCalories = SecondMostTotalCalories;
                        SecondMostTotalCalories = calories;
                        cout << "2MC: " << SecondMostTotalCalories << "\n";
                    }
                }
                else{
                    ThirdMostTotalCalories = calories;
                    cout << "3MC: " << ThirdMostTotalCalories << "\n";
                }
            }
            calories = 0;
        }
    }
    //cout << "Total: " << calories << "\n\nNew Elf!\n";
    if (calories > ThirdMostTotalCalories){
        if (calories > SecondMostTotalCalories){
            if (calories > FirstMostTotalCalories){
                FirstMostTotalCalories = calories;
            }
            else{
                SecondMostTotalCalories = calories;
            }
        }
        else{
            ThirdMostTotalCalories = calories;
        }
    }

    calories = FirstMostTotalCalories + SecondMostTotalCalories + ThirdMostTotalCalories;
    cout << "Most calories carried by three elves: " << calories << "\n";

    return 0;
}