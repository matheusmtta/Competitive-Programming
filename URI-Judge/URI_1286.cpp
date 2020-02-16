#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

int pizzas, limit;
int time_del[20], cost[20];
int mtx[20][20];

int DP(int idx, int wgt){
  if (wgt < 0) return -INF;
  if (idx == pizzas) return 0;
  int&delivery = mtx[idx][wgt];
  if (delivery != -1) return delivery;
  return max(DP(idx+1, wgt), time_del[idx] + DP(idx+1, wgt-cost[idx]));
}

int main(){
  int n;
  while (1){
    cin >> n;
    if (n == 0) break;
    pizzas = n;
    cin >> limit;
    for (int i = 0; i < pizzas; i++){
      cin >> time_del[i];
      cin >> cost[i];
    }
    for (int i = 0; i < 20; i++)
      for (int j = 0; j < 20; j++)
        mtx[i][j] = -1;
    int resp = DP(0, limit);
    cout << resp << " min." << endl;
  }
}
