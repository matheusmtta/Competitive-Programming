#include <bits/stdc++.h>

using namespace std;

int main(){
  int n, x, correct = 0;
  char side;
  while(scanf("%d", &n) != EOF){
    map <int, pair<int, int> > quant;
    while(n--){
      cin >> x >> side;
      if (side == 'D') quant[x].first++;
      else quant[x].second++;
    }
    map <int, pair<int, int>>::iterator it;
    for (it = quant.begin(); it != quant.end(); it++){
      correct += min(quant[it->first].first, quant[it->first].second);
    }
    cout << correct << endl;
    correct=0;
  }
}
