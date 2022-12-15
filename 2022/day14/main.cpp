//g++ -o a.out source.cpp
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct pos{
  int x;
  int y;
};

bool isNumber(char c);

int main(){
  ifstream ifs("input_example.txt");

  int by{0};  // biggest y position
  int bx{0};  // x
  int sy{0};  // smallest
  int sx{0};
  char temp[10];
  string word;

  getline(ifs,word,',');
  bx = stoi(word);
  sx = stoi(word);

  getline(ifs,word,' ');
  by = stoi(word);
  sy = stoi(word);

  while(!isNumber(ifs.peek())){
    ifs.ignore();
  }

  cout << ifs.peek();

  /*
  while(ifs.peek() != EOF){
    //cout << ifs.peek();
    int i=0;
    while(ifs.peek() != ','){
      temp[i] = ifs.get();
      cout << temp[i];
      i++;
    }
  }
  */


  return 0;
}

bool isNumber(char c){
  return (c >= 48 && c <= 57);
}
