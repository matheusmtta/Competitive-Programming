#include <iostream>

using namespace std;

int main(){

        int i=1, j=60;
        int k=0;
        float save_j=1;

        for (j = 60; j >= 0; j-=5) {
                cout << "I=" << i << " J=" << j << endl;
                i+=3;
        }
}
