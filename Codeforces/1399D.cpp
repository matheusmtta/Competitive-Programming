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

	while (t--){
		int n; cin >> n;
		queue <int> zeros, ones;
		vector <pair<char, int>> arr;

		int ans = 0;

		for (int i = 0; i < n; i++){
			char x; cin >> x;
			if (x == '0'){
				if (ones.empty()){
					ans++;
					zeros.push(ans);
					arr.push_back({x, ans});
				}
				else {
					arr.push_back({x, ones.front()});
					zeros.push(ones.front());
					ones.pop();
				}
			}
			else {
				if (zeros.empty()){
					ans++;
					ones.push(ans);
					arr.push_back({x, ans});
				}
				else {
					arr.push_back({x, zeros.front()});
					ones.push(zeros.front());
					zeros.pop();
				}
			}
		}

		cout << ans << endl;
		for (auto k : arr)
			cout << k.second << " ";
		cout << endl;
	}

	return 0;
}