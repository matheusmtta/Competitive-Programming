#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  string str;
  float notes[7], sum=0, mtx;
  for (int i = 0; i < n; i++){
    cin >> str;
    cin >> mtx;
    for (int j = 0; j < 7; j++){
      cin >> notes[j];
    }
    sort(notes, notes+7);
    for (int k = 1; k < 6; k++)
      sum+=notes[k];
    cout << str << " ";
    printf("%.2f\n", sum*mtx);
    sum =0;
  }
}
