#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll
#define mp make_pair
#define pb push_back

typedef long long int int64;
typedef unsigned long long int  uint64;

int main(){ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;

    while (cin >> N){
        if (N == 0) return 0;
        
        vector <int> arr(N);

        for (auto &x : arr)
            cin >> x;

        int ans = 0, sum = 0;

        for (int i = 0; i < N; i++){
            sum += arr[i];
            ans = max(sum, ans);
            if (sum < 0) sum = 0;
        }
        ans <= 0 ? cout << "Losing streak." << endl : cout << "The maximum winning streak is " << ans << "." << endl;
    }

    return 0;
}