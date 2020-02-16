#include <bits/stdc++.h>

using namespace std;

int main(){
  int a, b, c;
  cin >> a >> b >> c;
  if ((b < a) && (c >= b)) cout << ":)" << endl;
  else if ((b > a) && (c <= b)) cout << ":(" << endl;
  else if ((b > a) && (c > b) && ((b-a) > (c-b))) cout << ":(" << endl;
  else if ((b > a) && (c > b) && ((b-a) <= (c-b))) cout << ":)" << endl;
  else if ((b < a) && (c < b) && ((a-b) > (b-c))) cout << ":)" << endl;
  else if ((b < a) && (c < b) && ((a-b) <= (b-c))) cout << ":(" << endl;
  else if ((a == b) && (c > b)) cout << ":)" << endl;
  else if ((a == b) && (c <= b)) cout << ":(" << endl;
  return 0;
}
