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

const double e = 1e-9;

double sqrtd(double a, double b){
	return sqrt(a*a - b*b);
}

bool compare(const pair <double, double> &a,
			 const pair <double, double> &b){
	if (abs(a.first-b.first) <= e){
		return a.second > b.second;
	}
	return a.first < b.first;
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	double n, l, w;

	while (cin >> n >> l >> w){
		vector <pair<double, double>> arr;
		for (int i = 0; i < n; i++){
			double x, r; cin >> x >> r;
			if (r <= w/2) continue;
			arr.push_back({x-sqrtd(r, w/2), x+sqrtd(r, w/2)});
		}

		sort(arr.begin(), arr.end(), compare);

		int sz = arr.size();

		int idx = 0, ans = 0;
        bool rsp = true;
        double lst = 0, cov = 0;

		while (idx < sz && cov < l){
            if (arr[idx].first > cov) {
                rsp = false;
                break;
            }
            lst = arr[idx].second;
            int j = idx+1;
            while (j < sz){
                if (arr[j].first > cov) break;
                if (arr[j].second > lst){
                    lst = arr[j].second;
                }
                j++;
            }
            ans++;
            idx++;
            cov = lst;
		}
        
        if (lst < l) rsp = false;
        if (!rsp) cout << -1 << endl;
        else cout << ans << endl;
	}

	return 0;
}