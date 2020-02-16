#include <iostream>

using namespace std;

int maxGranizo(int num, int max){
        if (num > max) max = num;
        if (num == 1) return max;

        else if (num%2 == 0) {
                num = num/2;
                return maxGranizo(num, max);
        }

        else {
                num*=3;
                num+=1;
                return maxGranizo(num, max);
        }
}

int main (){
        int num = 100;
        int max = 0;

        while (1){
                cin >> num;
                if (num == 0) break;
                cout << maxGranizo(num, max) << endl;
        }
}
