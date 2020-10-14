#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll
#define mp make_pair
#define pb push_back

typedef long long int int64;
typedef unsigned long long int  uint64;

const int MAX = 1e7+100;

vector <int64> primes;
bitset <MAX> is_prime;

void sieve(){
	is_prime.set();
	is_prime[0] = is_prime[1] = 0;
	for (int64 i = 2; i <= MAX; i++){
		if (is_prime[i]){
			primes.push_back(i);
			for (int64 j = i*i; j <= MAX; j += i)
				is_prime[j] = 0;
		}
	}
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;

	primes.push_back(1);
	sieve();

	while (t--){
		int n; cin >> n;
		vector <int> arr(n);

		bool flag = false;

		for (int &x : arr){
			cin >> x;
			if (x == 1)
				flag = true;
		}

		if (!flag){
			cout << "0" << endl;
			continue;
		}

		sort(arr.begin(), arr.end());

		int ans = 0;

		for (int i = 0; i < primes.size(); i++){
			int l = 0, r = n - 1;
			flag = false;
			while (l <= r){
				int mid = (l + r)/2;
				if (arr[mid] == primes[i]){
					flag = true;
					ans = max(ans, i);
					break;
				}
				else if (arr[mid] > primes[i])
					r = mid - 1;
				else
					l = mid + 1;
			}
			if (!flag)
				break;
		}

		cout << primes[ans+1]-1 << endl;
	}

	return 0;
}