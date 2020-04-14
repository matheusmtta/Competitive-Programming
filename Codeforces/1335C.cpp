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
 
	int t; cin >> t;
 
	while (t--){
		int n; cin >> n;
 
		vector <int> a;
		map <int, int> mp;
 
		for (int i = 0; i < n; i++){
			int x; cin >> x;
			a.push_back(x);
			mp[x] += 1;
		}
 
		pair<int, int> mx = {-1, -1}; //quant & element
 
		for (auto l : mp){
			if (l.second > mx.second){
				mx.first = l.first;
				mx.second = l.second;
			}
		}
 
		mp.erase(mx.first);

		if (mx.second > mp.size()){
			int ans = mp.size()+1;
			mx.second--;
			cout << min(mx.second, ans) << endl;
		}
		else if (mx.second == mp.size())
			cout << mx.second << endl;
		else if (mx.second < mp.size())
			cout << mx.second << endl;

	}	
 
	return 0;
}