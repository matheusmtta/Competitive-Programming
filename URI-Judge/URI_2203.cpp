#include <bits/stdc++.h>

using namespace std;

int main(){
  double x0, y0, x1, y1, velocidade, r0, r1, deltaX, deltaY, distancia, ult;
  while(scanf("%lf %lf %lf %lf", &x0, &y0, &x1, &y1) != EOF){
    double velocidade, r0, r1;
    scanf("%lf %lf %lf", &velocidade, &r0, &r1);
    deltaX = pow((x1-x0), 2);
    deltaY = pow((y1-y0), 2);
    distancia = sqrt(deltaX+deltaY);
    distancia += velocidade*1.50;
    ult = r1+r0;
    distancia > ult ? cout << "N" << endl : cout << "Y" << endl;
  }
    return 0;
}
