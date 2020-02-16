#include <iostream>
#include <cstdlib>

using namespace std;

int main(){

        int days_t, taxes, i=0;

        while (cin >> days_t >> taxes){
                int lucronointervalo = 0;
                int maiorlucro = 0;

                for (i = 0; i < days_t; i++) {
                        int lucro, valor;

                        cin >> valor;
                        lucro = valor - taxes;

                        lucronointervalo = max(0, lucronointervalo + lucro);
                        maiorlucro = max(lucronointervalo, maiorlucro);
                }

                cout << maiorlucro << endl;
        }
}
