#include <bits/stdc++.h>
 
using namespace std;
 
#define MOD 998244353
#define INF (int)0x3f3f3f3f
#define MP make_pair
#define PB push_back
 
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;
 
bool compare(const pair<int, int> &a, const pair<int, int> &b){
	return a.first > b.first;
}
 
int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
	int n, k; cin >> n >> k;
	vector <pair<int, int>> a;
 
 
	for (int i = 1; i <= n; i++){
		int x; cin >> x; a.push_back(MP(x, i));
	}
 
	sort(a.begin(), a.end(), compare);
 
	int64 mx = 0;
 
	vector <int> p;
 
	for (int i = 0; i < k; i++){
		p.push_back(a[i].second);
		mx += a[i].first;
	}
 
	sort(p.begin(), p.end());
 
	int64 poss = 1;
 
	for (int i = 1; i < p.size(); i++){
		poss *= p[i]-p[i-1];
		poss %= MOD;
	}
 
	cout << mx << " " << poss%MOD << endl;
 
	return 0;
}