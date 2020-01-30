#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
  int n, k, l, c, d, p, nl, np, ans, total_mililiters, slices;
  cin >> n >> k >> l >> c >> d >> p >> nl >> np;
  slices =d*c;
  slices/=n;
  total_mililiters = k*l;
  total_mililiters/=n;
  p=p/n;
  total_mililiters/=nl;
  p/=np;
  ans = min(total_mililiters,min(slices, p));
  cout << ans << endl;
}