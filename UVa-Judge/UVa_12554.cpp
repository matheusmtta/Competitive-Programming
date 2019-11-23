/*
* A Special "Happy Birthday" Song!!!
* UVa Online Judge 12554
* 13/10/2019
* matheusmtta (Matheus Motta)
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  string names[n+1];
  string song[16]={"Happy", "birthday", "to", "you", "Happy",
  "birthday", "to", "you", "Happy", "birthday", "to", "Rujia", "Happy", "birthday", "to", "you"};
  for (int i = 0; i < n; i++)
    cin >> names[i];
  int aux=ceil(n/16.0);
  //cout << aux << endl;
  int k=0;
  for (int i = 0; i < aux; i++){
    for (int j = 0; j < 16; j++){
      cout << names[k%n] << ": " << song[j] << endl;
      k++;
    }
  }
  return 0;
}
