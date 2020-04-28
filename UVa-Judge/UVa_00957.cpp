#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll
#define MP make_pair
#define PB push_back

typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

int main(){ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int y;

    while (cin >> y){
        int64 n; cin >> n;
        vector <int64> popes;
        for (int i = 0; i < n; i++){
            int64 x; cin >> x;
            popes.push_back(x);
        }

        int64 ans = 0;
        pair <int64, int64> rsp;

        for (int i = 0; i < n; i++){
            int64 lb = popes[i] + y - 1;
            int64 cnt = 0;
            while (i+cnt < n && popes[i+cnt] <= lb) cnt++;
            if (cnt > ans){
                rsp.first = popes[i];
                rsp.second = popes[i+cnt-1];
                ans = cnt;
            }
        }

        cout << ans << " " << rsp.first << " " << rsp.second << endl;
    }

    return 0;
}