#include <bits/stdc++.h>

using namespace std;

int josephus(int n, int k) {
    return n > 1 ? (josephus(n-1, k) + k - 1) % n + 1 : 1;
}

int main(){
  int n, k, count = 1, cases;
  cin >> cases;
  while (count <= cases){
    cin >> n >> k;
    cout << "Case " << count << ": " << josephus(n, k) << endl;
    count ++;
  }
}
