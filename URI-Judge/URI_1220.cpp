#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll
#define mp make_pair
#define pb push_back

typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

int main(){ 
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    int n;

    while (cin >> n){
        if (n == 0) return 0;
        vector <double> arr;
        
        double sum = 0, me = 0;

        for (int i = 0; i < n; i++){
            double x; cin >> x;
            arr.push_back(x);
            sum += x;
        }

        me = sum/n;

        double ans0 = 0, ans1 = 0;

        for (int i = 0; i < arr.size(); i++){
            double diff = (double)(int64)((arr[i]-me)*100.0);
            if (diff > 0)
                ans1 += diff;
            else
                ans0 -= diff;
        }

        printf("$%.2lf\n", (double)max(ans0, ans1)/100.0);
    }

    return 0;
}