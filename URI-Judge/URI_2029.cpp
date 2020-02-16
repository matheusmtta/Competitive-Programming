#include <bits/stdc++.h>

using namespace std;

int main(){
  //ios_base :: sync_with_stdio(0); cin.tie(0);
  double diametro, area, volume, pi=3.14, altura;
  while(scanf("%lf %lf", &volume, &diametro) != EOF){
    area = ((diametro/2)*(diametro/2))*pi;
    altura = volume/area;
    printf("ALTURA = %.2lf\nAREA = %.2lf\n", altura, area);
  }
  return 0;
}
