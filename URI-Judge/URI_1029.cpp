#include <iostream>

using namespace std;

int count=0;

int fibo(int num){
        count+=1;
        if (num == 0) return 0;
        if (num == 1) return 1;
        else  return fibo(num-1) + fibo(num-2);
}

int main(){

        int num=0, i = 0, n = 0;

        cin >> n;

        for (i = 0; i < n; i++) {
                cin >> num;
                count =0;
                cout << "fib(" << num << ") = " << count-1 << " calls = " << fibo(num) << endl;
        }

        return 0;
}
