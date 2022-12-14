//g++ -o a.out source.cpp
#include <iostream>
#include <fstream>
using namespace std;

void print_element(char s[], int length);
int num_of_nums(char s[], int length);
int compare_arrays(char s1[], int length1, char s2[], int length2);

int main(){

  ifstream ifs("input.txt");
  int index{0}; // index of the pair
  int index_sum{0}; // sum of the indexes of the pairs in the right order

  while(ifs.peek() != EOF){
    index++;
    int length1{0};
    char temp1[1000]; //temp string to copy chars to
    int length2{0};
    char temp2[1000]; //temp string to copy chars to

    for(int i=0; ifs.peek() != '\n'; i++){
      temp1[i] = ifs.get();
      length1++;
    }

    ifs.get(); //discard the "\n"

    for(int i=0; ifs.peek() != '\n'; i++){
      temp2[i] = ifs.get();
      length2++;
    }

    ifs.get(); //discard the "\n"
    ifs.get(); //discard the "\n"

    int smaller = compare_arrays(temp1, length1, temp2, length2);

    // 2 if they are equal look who has more characters
    if (smaller == 0 && length1 < length2){
      smaller = 1;
    }
    else if (smaller == 0 && length1 > length2){
      smaller = 2;
    }

    if(smaller == 1){
      index_sum = index_sum + index;
    }
    cout << "Smaller: " << smaller << "\n\n";

  }

  cout << "\nRESULT = " << index_sum << "\n";

  return 0;
}

void print_element(char s[], int length){
  for(int i=0; i<length; i++){
    cout << s[i];
  }
}

int num_of_nums(char s[], int length){
  int nc{0}; // # of number characters

  for (int i = 0; i<(length); i++){
    if (int(s[i]) <= 57 && int(s[i]) >= 48) nc++;// 48 = ascii(0), 57 = ascii(9)
  }

  return nc;
}

int compare_arrays(char s1[], int length1, char s2[], int length2){
  cout << "Compare ";
  print_element(s1,length1);
  cout << " vs ";
  print_element(s2,length2);
  cout << "\n";

  // compare them
  // 1 first remove the brackets and compare the numbers
  // 1.1 find the number of number characters
  int nc1 = num_of_nums(s1,length1);

  int s1_int[nc1];

  int j{0};
  for (int i = 0; i<length1; i++){ //copy the numbers of s1 to an int array
    if (int(s1[i]) <= 57 && int(s1[i]) >= 48){
      if(int(s1[i])==49 && int(s1[i+1])==48){
        // the number is 10 (2 chars)
        s1_int[j] = 10;
        i++; //to skip the next char (the 0 from 10)
      }
      else{
        s1_int[j] = int(s1[i])-48; // from ascii to int number
      }
      j++;
    }
  }
  int nc2 = num_of_nums(s2,length2);

  int s2_int[nc2];
  j=0;
  for (int i = 0; i<length2; i++){ //copy the numbers of s2 to an int array
    if (int(s2[i]) <= 57 && int(s2[i]) >= 48){
      if(int(s2[i])==49 && int(s2[i+1])==48){
        // the number is 10 (2 chars)
        s2_int[j] = 10;
        i++; //to skip the next char (the 0 from 10)
      }
      else{
        s2_int[j] = int(s2[i])-48; // from ascii to int number
      }
      j++;
    }
  }

  int shortestnc = nc1; // We only want to check for the shortest number of elements
  if(nc2<nc1) shortestnc = nc2;

  int smaller = 0;  // smaller = 1 if s1 < s2, else smaller = 2

  for(int i=0; i < shortestnc && smaller == 0; i++){
    if(s1_int[i]<s2_int[i]){
      smaller = 1;
    }
    else if(s1_int[i]>s2_int[i]){
      smaller = 2;
    }
  }

  return smaller;
}
