#include <bits/stdc++.h>

using namespace std;

int main(){
    string bits;
    int sum=0;
    cin >> bits;
    for (int i = 0; i < bits.length(); i++)
      if (bits[i] == '1') sum++;
    (sum%2 == 0) ? cout << bits << "0" << endl : cout << bits << "1" << endl;
    return 0;
}
