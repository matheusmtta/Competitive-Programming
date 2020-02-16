#include <bits/stdc++.h>

using namespace std;

int main(){
  int n, x;
  cin >> n;
  map <int, int> quant;
  while(n --){
    cin >> x;
    quant[x]++;
  }
  map<int,int>::iterator it;
  for (it = quant.begin(); it != quant.end(); it++){
    cout << it->first << " aparece " << quant[it->first] << " vez(es)" << endl;
  }
}
