#include <bits/stdc++.h>

using namespace std;

int main(){
  int total=0;
  string eye;
  int noise=3;
  while(noise){
    cin >> eye;
    if (eye == "caw") {
      cin >> eye;
      cout << total << endl;
      total = 0;
      noise--;
      continue;
    }
    else if (eye == "--*") total+=1;
    else if (eye == "-*-") total+=2;
    else if (eye == "-**") total+=3;
    else if (eye == "*--") total+=4;
    else if (eye == "*-*") total+=5;
    else if (eye == "**-") total+=6;
    else if (eye == "***") total+=7;
  }
  return 0;
}
