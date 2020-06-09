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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    int q = 1;

    while (t--){
        int n; cin >> n;
        string str; cin >> str;

        int ans = 0;

        str += "##";

        for (int i = 0; i < n; i++){
            if (str[i] == '.'){
                str[i] = str[i+1] = str[i+2] = '#';
                ans++;
            }
        }

        cout << "Case " << q << ": " << ans << endl;
        q++;        
    }

    return 0;
}