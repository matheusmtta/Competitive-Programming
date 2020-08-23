#include <bits/stdc++.h>
 
using namespace std;
 
#define MOD 11092019
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll
#define mp make_pair
#define pb push_back
 
typedef long long int int64;
typedef unsigned long long int  uint64;

bool comp(const pair<pair<int,int>, int> &a,
		  const pair<pair<int,int>, int> &b){
	if (a.first.first < b.first.first)
		return true;
	if (a.first.first == b.first.first &&
		a.first.second < b.first.second)
		return true;
	if (a.first.first == b.first.first &&
		a.first.second == b.first.second &&
		a.second < b.second)
		return true;
	return false;
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 	
 	int n, q = 1;

 	while (cin >> n){
 		if (n == 0) return 0;
 		vector <pair<pair<int,int>, int>> arr;
 		for (int i = 0; i < n; i++){
 			int x, y, z; cin >> x >> y >> z;
			arr.push_back({{x, y}, z});
			arr.push_back({{y, x}, z});
			arr.push_back({{x, z}, y});
			arr.push_back({{z, x}, y});
			arr.push_back({{y, z}, x});
			arr.push_back({{z, y}, x}); 			
 		}
 		
 		sort(arr.begin(), arr.end(), comp);

 		vector <int> ans(arr.size(), 1);

 		for (int i = 0; i < arr.size(); i++){
 			ans[i] = arr[i].second;
 			for (int j = 0; j < i; j++){
 				if (arr[i].first.first > arr[j].first.first &&
 					arr[i].first.second > arr[j].first.second &&
 					ans[j] + arr[i].second > ans[i])
 						ans[i] = ans[j] + arr[i].second;
 			}
 		}

 		int rsp = -INF;

 		for (auto k : ans)
 			rsp = max(rsp, k);

 		cout << "Case " << q++ << ": maximum height = " << rsp << endl;
 	}

	return 0;
}