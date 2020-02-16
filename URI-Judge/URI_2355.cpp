#include <iostream>
#include <cmath>
using namespace std;
 
int main()
{
    unsigned long n;
    while(cin >> n and n != 0){
        double avg_g = n/90.0;
        int bra,gar;
        bra = floor(avg_g*1);
        gar = ceil(avg_g*7);
 
        cout << "Brasil " << bra << " x Alemanha " << gar << endl;
    }
    return 0;
}