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

bool compare(const pair<int, int> &a, const pair<int, int> &b){
    if (a.first == b.first){
        return a.second > b.second;
    }
    return a.first < b.first;
}

int main(){ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int L, G;
    
    while (cin >> L >> G){
        if (L == 0 && G == 0) return 0;
        vector <pair<int, int>> arr;
        
        for (int i = 0; i < G; i++){
            int x, r; cin >> x >> r;
            arr.push_back({x-r, x+r});
        }
        
        sort(arr.begin(), arr.end(), compare);
        
        int idx = 0;
        int cov = 0, ans = 0;
        bool rsp = true;
        
        while (idx < G && cov < L){
            pair <int, int> tmp;
            if (cov < arr[idx].first) rsp = false;
            tmp = arr[idx];
            int j = idx+1;
            while (j < G){
                if (arr[j].first > cov) break;
                if (arr[j].second > tmp.second){
                    tmp = arr[j];
                }
                j++;
            }
            ans++;
            cov = tmp.second;
            idx++;
        }
        
        if (cov < L) rsp = false;
        rsp ? cout << G-ans << endl : cout << -1 << endl;
    }

    return 0;
}