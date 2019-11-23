/*
* Getline One
* URI Online Judge 1216
* 05/10/2019
* matheusmtta (Matheus Motta)
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
  char casa[1000];
  double ans=0;
  long long count = 0, n;
  while(scanf("%[^\n]",&casa) != EOF){
    scanf("%*c%lld%*c",&n);
    ans += n;
    count++;
  }
  printf("%.1lf\n", ans/(double)count);
}
