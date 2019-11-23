/*
* Love Calculator
* UVa Online Judge 10424
* 18/10/2019
* matheusmtta (Matheus Motta)
*/
#include <bits/stdc++.h>

using namespace std;

int find(int x){
  int sum=0;
  while(x >= 1){
    sum+=(x%10);
    x/=10;
  }
  if (sum > 9) return find(sum);
  return sum;
}

int main(){
  string c1, c2;
  while(getline(cin, c1)){
    getline(cin, c2);
    double sum1=0, sum2=0;
    for (int i = 0; i < c1.length(); i++){
      if ((c1[i] >= 97 && c1[i] <= 122)
       || (c1[i] >= 65 && c1[i] <= 90)){
        if (isupper(c1[i])) sum1+=(c1[i]-'A'+1);
        else if (islower(c1[i])) sum1+=(c1[i]-'a'+1);
      }
    }
    for (int i = 0; i < c2.length(); i++){
      if ((c2[i] >= 97 && c2[i] <= 122)
       || (c2[i] >= 65 && c2[i] <= 90)){
        if (isupper(c2[i])) sum2+=(c2[i]-'A'+1);
        else if (islower(c2[i])) sum2+=(c2[i]-'a'+1);
      }
    }
    double l = (double)find(sum1);
    double s = (double)find(sum2);
    if (l >= s) printf("%.2lf \%%\n", 100*(s/l));
    else  printf("%.2lf \%%\n", 100*(l/s));
  }
}
