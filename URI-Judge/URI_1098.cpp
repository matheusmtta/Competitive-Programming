#include <iostream>

using namespace std;

int main(){

        float i=0, j=1;
        int k=0;
        float save_j=1;

        while(i<2.1){
                j = save_j;
                for (k = 0; k < 3; k++) {
                        cout << "I=" << i << " J=" << j <<endl;
                        j+=1;
                }
                save_j+=0.2;
                i+=0.2;
        }
}
