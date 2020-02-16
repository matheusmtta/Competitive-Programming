#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

string centena[10] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
string dezena[10] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
string unidade[10] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};

int main(){
  int n;
  cin >> n;
  cout << centena[n/100] + dezena[(n%100)/10] + unidade[n%10] << endl;
  return 0;
}
