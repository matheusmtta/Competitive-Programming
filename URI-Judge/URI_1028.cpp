#include <iostream>
#include <cmath>

using namespace std;

int tioEuclides(int x, int y){
    int aux;
    int resto;
    if (y == 0) return x;
    if (y > x) {
        aux = y;
        y = x;
        x = aux;
    }
    if(y > 0) return tioEuclides(y, x%y);
    else return x;
}

int main (){

    int n=0, i=0, j=0, mdc=0, x, y;

    cin >> n;

    for (i = 0; i < n; i++) {
        cin >> x >> y;
        cout << tioEuclides(x, y) << endl;
    }
}