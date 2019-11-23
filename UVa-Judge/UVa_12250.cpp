/*
* Language Detection
* Uva Online Judge 12250
* 11/10/2019
* matheusmtta (Matheus Motta)
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
  int i = 1;
  while(1){
    string sample;
    cin >> sample;
    if (sample == "#") return 0;
    printf("Case %d: ", i);
    if (sample == "HELLO") cout << "ENGLISH" << endl;
    else if (sample == "HOLA") cout << "SPANISH" << endl;
    else if (sample == "HALLO") cout << "GERMAN" << endl;
    else if (sample == "BONJOUR") cout << "FRENCH" << endl;
    else if (sample == "CIAO") cout << "ITALIAN" << endl;
    else if (sample == "ZDRAVSTVUJTE") cout << "RUSSIAN" << endl;
    else cout << "UNKNOWN" << endl;
    i++;
  }
}
