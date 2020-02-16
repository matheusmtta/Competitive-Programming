#include <iostream>
#include <cmath>

using namespace std;

int main(){

  int xi, yi, xf, yf, i=0;
  int auxX, auxY;
  int steps;

  while(1){

    cin >> xi >> yi >> xf >> yf;

    if (xi == 0) break;

    auxX = abs(xf-xi);
    auxY = abs(yf-yi);

    if (xi == xf && yi != yf) steps = 1;
    else if (xi != xf && yi == yf) steps = 1;
    else if (xi == xf && yi == yf) steps = 0;
    else if (auxY == auxX) steps = 1;
    else steps = 2;

    cout << steps << endl;
  }


  return 0;
}