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

const int MAX = 1000100;

vector <int64> basis;
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

int64 count_div(int64 n){
	int64 p = primes[0];
	int64 idx = 0, c = 0, ans = 1;

	while (p*p <= n){
		int i = 0;
		while (n%p == 0) {
			n/=p;
			i++;
		}
		ans *= (i+1);
		p = primes[idx++];
	}

	if (n != 1) ans*=2;

	return ans;
}

void build(int64 n){
	if (n > MAX) return;
	basis.push_back(n);
	build(n + count_div(n));	
}


int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	sieve();
	build(1);

	int t, q = 1; cin >> t;

	while (t--){
		int a, b; cin >> a >> b;

		int l = 0, r = basis.size();

		int left = 0, right = 0;

		while (l <= r){
			int mid = (l+r)/2;
			if (basis[mid] < a)
				l = mid + 1;
			else {
				left = mid;
				r = mid-1;
			}
		}

		l = 0, r = basis.size();

		while (l <= r){
			int mid = (l+r)/2;
			if (basis[mid] > b)
				r = mid-1;
			else {
				right = mid;
				l = mid+1;
			}
		}

		cout << "Case " << q << ": " << right-left+1 << endl;
		q++;
	}

	return 0;
}