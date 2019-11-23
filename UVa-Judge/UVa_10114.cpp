/*
* Loansome Car Buyer
* Uva Online Judge 10114
* 11/07/2019
* matheusmtta (Matheus Motta)
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
  while(true){
    int months, dep, x;
    int count=0;
    double dp, total, y;
    float aux[101];
    cin >> months >> dp >> total >> dep;
    if (months < 0) return 0;
    for (int i = 0; i < 101; i++)
      aux[i]=-1;
    for (int i = 0; i < dep; i++){
      cin >> x >> y;
      aux[x]=y;
    }
    for (int i = 1; i < 101; i++)
      if (aux[i]==-1) aux[i]=aux[i-1];
    double parcel = total/months, amount = total+dp, tmp = total;
    while(true){
      amount*=(1-aux[count]);
      if (tmp < amount){
        if (count==1) cout << count << " month" << endl;
        else cout << count << " months" << endl;
        break;
      }
      count++;
      tmp-=parcel;
    }
  }
  return 0;
}
