/*
* Super Primos: Ativar!
* URI Online Judge 2674
* 23/09/2019
* matheusmtta (Matheus Motta)
*/

#include <bits/stdc++.h>

using namespace std;

int isPrime(int n){
	if (n <= 1) return 0;
  for (int i = 2; i <= (int)ceil(sqrt(n)); i++){
    if(n%i == 0 && n != i) return 0;
  }
  return 1;
}

int PrimeDigits(int n){
  int num = n, aux;
  while(num >= 1){
    aux=num%10;
    if (!isPrime(aux)) return 0;
    num/=10;
  }
  return 1;
}

int main(){
  int n;
  while(cin >> n){
  	if (n <= 1) {cout << "Nada" << endl; continue;}
    else if (isPrime(n) && PrimeDigits(n)) {cout << "Super" << endl; continue;}
    else if (isPrime(n)) {cout << "Primo" << endl; continue;}
    else cout << "Nada" << endl;
  }
  return 0;
}
