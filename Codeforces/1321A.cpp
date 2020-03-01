#include <bits/stdc++.h>
 
using namespace std;
 
#define MOD 1000000007
#define INF (int)1e9
#define MP make_pair
#define PB push_back
 
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;
 
int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
	int n; cin >> n;
	vector <int> a, b;
	int ans = -1;
 
	int sum_a = 0, sum_b = 0;
 
	for (int i = 0; i < n; i++){
		int x; cin >> x;
		a.push_back(x);
		sum_a += x;
	}
 
	for (int i = 0; i < n; i++){
		int x; cin >> x;
		b.push_back(x);
		sum_b += x;
	}
 
	int k = 0;
	int q = 0;
	int s = 0;
 
	for (int i = 0; i < n; i++){
		if (a[i] && !b[i]){
			k++;
		}
		if (b[i] && !a[i]){
			q++;
		}
		if (a[i] && b[i]){
			s++;
		}
	}
 
	if (sum_a > sum_b) cout << 1 << endl;

	if (sum_a <= sum_b && k == 0) cout << -1 << endl;
	else {
		if (sum_b >= sum_a){
			sum_a -= s;
			sum_b -= s;
			ans = ceil(((sum_b*1.0)+1)/k);
 
			cout << ans << endl;
		}
	}
 
	return 0;
}