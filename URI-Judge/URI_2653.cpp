#include <bits/stdc++.h>

using namespace std;

set <string> jews;

int main(){
  string str;
  while (cin >> str)
    jews.insert(str);
  cout << jews.size() << endl;
}
