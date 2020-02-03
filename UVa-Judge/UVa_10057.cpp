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
	int n;

	while (cin >> n){
		vector <int> arr(n);

		int freq[65540];

		for (int i = 0; i  < 65540; i++)
			freq[i] = 0;

		for (int i = 0; i < n; i++){
			cin >> arr[i];
			freq[arr[i]]++;
		}
		sort(arr.begin(), arr.end());

		int a, b, c;
		int high, low;

		if (n%2 == 0){
			low = arr[(n/2)-1];
			high = arr[n/2];

			b = freq[low] + freq[high];
			a = min(low, high);
			c = high - low + 1;

			if (low == high){
				c = 1;
				b = freq[low];
			}
		}
		else{
			a = arr[n/2];
			b = freq[a];
			c = 1;
		}

		cout << a << " " << b << " " << c << endl;
	}
	
	return 0;
}