#include <bits/stdc++.h>

using namespace std;

int main(){
  long long int a, b, c;
  cin >> a >> b >> c;
  long long int vec[3];
  vec[0] = a; vec[1] = b; vec[2] = c;
  if (a >= c+b || b >= a+c || c >= a+b) {cout << "Invalido" << endl; return 0;}
  if ((a==b && b !=c) || (a==c && b != c) || (b==c && b != a)) cout << "Valido-Isoceles" << endl;
  else if (a != b && b != c && a != c) cout << "Valido-Escaleno" << endl;
  else if (a == b && b == c && a == c) cout << "Valido-Equilatero" << endl;
  sort(vec, vec+3);
  if ((vec[2]*vec[2]) == (vec[1]*vec[1])+(vec[0]*vec[0])) cout << "Retangulo: S" << endl;
  else cout << "Retangulo: N" << endl;
  return 0;
}
