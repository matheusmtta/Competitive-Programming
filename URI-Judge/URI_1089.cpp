#include <iostream>

using namespace std;

int main(){

  int n, i = 0, saveInflexion=0;

  while(1){

    cin >> n;

    if (n == 0) break;

    saveInflexion = 0;
    
    n+=1;

    int vector[n+1];

    for (i = 0; i < n; ++i){
      if (i == (n-1)) {
        vector[n-1] = vector[0];
        break;
      }

      cin >> vector[i];
    }

    for (i = 0; i < (n-1); ++i){
      if (i==0){
        if (vector[i] > vector[i+1] && vector[i] > vector[n-2]) saveInflexion++;
        else if (vector[i] < vector[i+1] && vector[i] < vector[n-2]) saveInflexion++;
      }

      else{
        if (vector[i] > vector[i+1] && vector[i] > vector[i-1]) saveInflexion++;
        else if (vector[i] < vector[i+1] && vector[i] < vector[i-1]) saveInflexion++;
      }
    }

    cout << saveInflexion << endl;
  }

  return 0;
}
