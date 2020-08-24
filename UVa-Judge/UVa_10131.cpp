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

	int a, b, c = 1;
	vector <pair<int, int>> arr;
	map<pair<int, int>, int> mp;
	while (cin >> a >> b){
		arr.push_back({a, b});	
		mp[{a, b}] = c;
		c++; 
	}

	sort(arr.begin(), arr.end());
	reverse(arr.begin(), arr.end());

	vector <int> dist(arr.size()+1, INF);
	vector <pair<int, int>> recover;
	vector <int> parent(arr.size()+1, -1);
	int end = 0;
	dist[0] = -INF;

	for (int i = 0; i < arr.size(); i++){
		int l = 0, r = arr.size(), idx;
		while (l <= r){
			int mid = (l+r)/2;
			if (dist[mid] < arr[i].second)
				l = mid+1;
			else {
				r = mid - 1;
				idx = mid;
			}
		} 
		if (dist[idx] > arr[i].second &&
			dist[idx-1] < arr[i].second){
			dist[idx] = arr[i].second;
			parent[i] = idx;
			end = max(idx, end);
		}
	}

	int rsp = arr.size();

	while (dist[rsp] == INF) rsp--;

	cout << rsp << endl;

	int lst = arr.size();

	while (lst--){
		while (parent[lst] == end){
			recover.push_back(arr[lst]);
			end--;
		}
	}

	for (auto k : recover){
		cout << mp[k] << endl;
	}

	return 0;
}