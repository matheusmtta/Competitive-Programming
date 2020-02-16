#include <bits/stdc++.h>

using namespace std;

int main(){
  int x, z, sum=0, count=1;
  cin >> x >> z;
  while (z <= x)
    cin >> z;
  sum = x;
  while (sum < z){
    x++;
    sum+=x;
    count++;
  }
  cout << count << endl;
}
