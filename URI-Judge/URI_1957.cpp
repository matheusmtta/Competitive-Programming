#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

int main(){
  long long int n, m, j=0;
  vector <char> hexa;
  char hexa_x;
  cin >> n;
  while (n > 0){
    m= n % 16;
    n/=16;
    if(m<=9){
      hexa_x = m+48;
      hexa.push_back(hexa_x);
    }
    else if(m==10){
      hexa_x = 'A';
      hexa.push_back(hexa_x);
    }
    else if(m==11){
      hexa_x = 'B';
      hexa.push_back(hexa_x);
    }
    else if(m==12){
      hexa_x = 'C';
      hexa.push_back(hexa_x);
    }
    else if(m==13){
      hexa_x = 'D';
      hexa.push_back(hexa_x);
    }
    else if(m==14){
      hexa_x = 'E';
      hexa.push_back(hexa_x);
    }
    else if(m==15){
      hexa_x = 'F';
      hexa.push_back(hexa_x);
    }
    j++;
  }
  for (int i = hexa.size()-1; i >= 0; i--)
    cout << hexa[i];
  cout << endl;
}
