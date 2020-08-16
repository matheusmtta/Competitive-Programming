#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll
#define mp make_pair
#define pb push_back

typedef long long int int64;
typedef unsigned long long int  uint64;

int getSum(vector <int> a){
	int sum = 0;
	for (int i = 1; i < a.size(); i++){
		sum += abs(a[i]-a[i-1]);
	}
	return sum;
}

void rotate(vector <int> &a){
	int tmp = a[0];
	int n = a.size();
	for (int i = 0; i < n-1; i++)
		a[i] = a[i+1];
	a[n-1] = tmp;
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	int q = 1;
	while (t--){
		int n; cin >> n;
		
		vector <int> arr(n);
		
		for (auto &x : arr)
			cin >> x;

		sort(arr.begin(), arr.end());

		vector <int> ans;

		reverse(arr.begin(), arr.begin());

		for (int i = 0; i < n/2; i++){
			ans.push_back(arr[n-1-i]);
			ans.push_back(arr[i]);
		}

		if (n & 1) ans.push_back(arr[n/2]);

		int rsp = 0;

		for (int i = 0; i <= n; i++){
			rsp = max(getSum(ans), rsp);
			rotate(ans);
		}

		vector <int> ans2;

		for (int i = 0; i < n/2; i++){
			ans2.push_back(arr[i]);
			ans2.push_back(arr[n-1-i]);
		}

		if (n & 1) ans2.push_back(arr[n/2]);

		for (int i = 0; i <= n; i++){
			rsp = max(getSum(ans2), rsp);
			rotate(ans2);
		}

		cout << "Case " << q++ << ": " << rsp << endl;
	}

	return 0;
}