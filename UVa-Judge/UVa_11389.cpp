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

bool compare(const int &a, const int &b){
    return a > b;
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, d, r;
    
    while (cin >> n >> d >> r){
        if (n == 0 && d == 0 && r == 0) return 0;
        
        vector <int> mo, ev;
        
        for (int i = 0; i < n; i++){
            int x; cin >> x;
            mo.push_back(x);
        }        
        
        for (int i = 0; i < n; i++){
            int x; cin >> x;
            ev.push_back(x);
        }
        
        sort(mo.begin(), mo.end());
        sort(ev.begin(), ev.end(), compare);
        
        int ans = 0;
        
        for (int i = 0; i < n; i++){
            if (mo[i]+ev[i] > d){
                ans += r*(mo[i]+ev[i]-d);
            }
        }
        
        cout << ans << endl;
    }

	return 0;
}