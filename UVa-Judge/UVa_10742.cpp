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

const int MAX = 1000000;

bitset <MAX+10> is_coin;
vector <int64> primes;

void sieve(){
	is_coin.set();
	is_coin[0] = 0;
	is_coin[1] = 0;
	int64 p = 2;
	while (p <= MAX){
		if (is_coin[p]){
			primes.push_back(p);
			for (int64 i = p*p; i <= MAX; i += p){
				is_coin[i] = 0;
			}
		}
		p++;
	}
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, q = 1;

	sieve();

	while (cin >> n){
		if (n == 0) break;
		int l = 0, r = primes.size()-1;
		int b;
		while (l <= r){
			int mid = (l+r)/2;
			if (primes[mid] >= n)
				r = mid - 1;
			else {
				b = mid;
				l = mid + 1;
			}
		}

		int64 ans = 0;

		for (int i = 0; primes[i] < n; i++){
			int64 mx = n - primes[i] + 1;
			int64 s = 0;

			int l = i, r = primes.size()-1;

			while (l <= r){
				int mid = (l+r)/2;
				if (primes[mid] >= mx)
					r = mid - 1;
				else {
					s = mid;
					l = mid + 1;
				}
			}

			while (s > i && primes[i] + primes[s] > n) s--;

			if (s) ans += s - i;
		}

		cout << "Case " << q << ": " << ans << endl;
		q++;	
	}

	return 0;
}