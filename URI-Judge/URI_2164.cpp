#include <bits/stdc++.h>

using namespace std;

int main(){
  double n;
  cin >> n;
  double result = (pow(((1+sqrt(5))/2),n)-pow(((1-sqrt(5))/2),n))/sqrt(5);
  printf("%.1lf\n", result);
}
