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

	int n; 

	while (cin >> n){
		vector <int> arr; 
	
		for (int i = 0; i < n; i++){
			int x; cin >> x;
			arr.push_back(x);
		}

		sort(arr.begin(), arr.end());

		int l = 0, r = arr.size()-1;

		int k = 0;

		cin >> k;

		pair <int, int> ans;
		int diff = INF;

		for (int i = 0; i < n; i++){
			int l = i+1, r = n-1;

			int s = k - arr[i];

			if (s < arr[i]) break;

			while (l <= r){
				int mid = (l+r+1)/2;
				if (arr[mid] == s){
					if (arr[mid]-arr[i] < diff){
						ans.first = arr[i];
						ans.second = arr[mid];
						diff = arr[mid]-arr[i];
					}
					break;
				}
				else if (arr[mid] > s){
					r = mid-1;
				}
				else if (arr[mid] < s){
					l = mid+1;
				}
			}
		}

		cout << "Peter should buy books whose prices are " << ans.first << " and " << ans.second << "." << endl;
		cout << endl;
	}

	return 0;
}