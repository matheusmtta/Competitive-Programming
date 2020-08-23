#include <bits/stdc++.h>
 
using namespace std;
 
#define MOD 11092019
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll
#define mp make_pair
#define pb push_back
 
typedef long long int int64;
typedef unsigned long long int  uint64;

// vector<int> recover_lis(vector <int> arr, vector <int> parent, int end){
// 	vector <int> ans;
	
// }

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 	
 	int n; 
 	vector <int> arr;
 	while (cin >> n)
 		arr.push_back(n);

 	n = arr.size();

 	vector <int> ans(n+1);

 	for (auto &x : ans) x = INF;

 	ans[0] = -INF;

 	vector <int> recover_id(n+1);
 	vector <int> parent(n+1, -1);
 	int recover_end;

 	for (int i = 0; i < n; i++){
 		int idx, l = 0, r = n;
 		while (l <= r){
 			int mid = (l+r)/2;
 			if (ans[mid] < arr[i])
 				l = mid+1;
 			else {
 				r = mid-1;
 				idx = mid;
 			}
 		}
 		if (ans[idx-1] < arr[i] && arr[i] < ans[idx]){
 			ans[idx] = arr[i];
 			parent[i] = idx;
 			recover_end = max(recover_end, idx);
 		}
 	}

 	int rsp = n, idx = n;

 	while (ans[rsp] == INF) rsp--;

 	vector <int> recover_lis;
 
 	while (idx--){
 		if (parent[idx] == recover_end){
 			recover_lis.push_back(arr[idx]);
 			recover_end--;
 		}
 	}
 	reverse(recover_lis.begin(), recover_lis.end());

 	cout << rsp << endl << "-" << endl;

 	for (auto x : recover_lis)
 		cout << x << endl;

	return 0;
}