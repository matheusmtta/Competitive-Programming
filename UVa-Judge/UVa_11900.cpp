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

vector <pair<int, int>> arr;

bool comp(const pair<int, int> &a, const pair<int, int> &b){
	return a.second > b.second;
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, q = 1;

	int t; cin >> t;

	while (q <= t){
		int n, P, Q; cin >> n >> P >> Q;
		vector <int> arr; 
		for (int i = 0; i < n; i++){
			int x; cin >> x;
			arr.push_back(x);
		}
		sort(arr.begin(), arr.end());
		int ans = 0, count = 0;
		for (int i = 0; i < arr.size(); i++){
			if (ans + arr[i] <= Q && count < P){
				count++;
				ans += arr[i];
			}
			else break;
		}
		cout << "Case " << q << ": ";
		cout << count << endl; 
		q++;
	}

	return 0;
}