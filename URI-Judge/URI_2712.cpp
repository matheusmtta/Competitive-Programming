/*
* Rodízio Veicular
* URI Online Judge 2712
* 27/09/2019
* matheusmtta (Matheus Motta)
*/

#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

int main(){
  int n =0, aux=0;
  cin >> n;
  cin.ignore();
  while(n--){
    string str;
    cin >> str;
    if (str.length() != 8) {cout << "FAILURE" << endl; continue;}
    else if (str[3] != '-') {cout << "FAILURE" << endl; continue;}
    for (int i = 0; i < 3; i++){
      if (str[i] < 65 || str[i] > 90) {cout << "FAILURE" << endl; aux=1; break;}
    }
    if (aux) {aux=0; continue;}
    for (int i = 4; i < 8; i++){
      if (str[i] < 48 || str[i] > 57) {cout << "FAILURE" << endl; aux=1; break;}
    }
    if (aux) {aux=0; continue;}
    if (str[7] == '1' || str[7] == '2') {cout << "MONDAY" << endl; continue;}
    else if (str[7] == '3' || str[7] == '4') {cout << "TUESDAY" << endl; continue;}
    else if (str[7] == '6' || str[7] == '5') {cout << "WEDNESDAY" << endl; continue;}
    else if (str[7] == '7' || str[7] == '8') {cout << "THURSDAY" << endl; continue;}
    else if (str[7] == '0' || str[7] == '9') {cout << "FRIDAY" << endl; continue;}
  }
  return 0;
}
