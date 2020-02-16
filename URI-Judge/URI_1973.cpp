#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base :: sync_with_stdio(0); cin.tie(0);
  long long int n;
  cin >> n;
  long long int sitios[n], visited[n], sum_total=0, sum=0, ovelhas=0;
  for (int i = 0; i < n; i++){
    cin >> sitios[i];
    visited[i] =0;
    sum_total+=sitios[i];
  }
  int i = 0;
  while(1){
    if (i == 0 && sitios[i]%2==0){
      visited[i]=1;
      if (sitios[i]> 0) {ovelhas++; sitios[i]--;}
      break;
    }
    else if (i == n-1 && sitios[i]%2 == 1){
      visited[i]=1;
      if (sitios[i] > 0) {sitios[i]--; ovelhas++;}
      break;
    }
    else if (sitios[i]%2==1){
      visited[i]=1;
      if (sitios[i] > 0) {sitios[i]--; ovelhas++;}
      i++;
    }
    else if (sitios[i]%2==0){
      visited[i]=1;
      if (sitios[i] > 0) {sitios[i]--; ovelhas++;}
      i--;
    }
  }
  for (int i = 0; i < n; i++)
    sum+=visited[i];
  cout << sum << " " << sum_total-ovelhas << endl;
  return 0;
}
