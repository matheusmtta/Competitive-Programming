#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll
#define mp make_pair
#define pb push_back
#define MAX 20000100

typedef long long int int64;
typedef unsigned long long int  uint64;

vector <int64> primes;
bitset <MAX> is_prime;

void sieve(int64 num){
	is_prime.set();
	is_prime[0] = is_prime[1] = 0;
	for (int64 i = 2; i <= num; i++){
		if (is_prime[i]){
			primes.push_back(i);
			for (int64 j = i*i; j <= num; j += i)
				is_prime[j] = 0;
		}
	}
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int a, b; cin >> a >> b;

	if (a == b){
		cout << "?" << endl;
		return 0;
	}

	if (a > b)
		swap(a, b);

	sieve(b);
	int n = primes.size();

	int l = 0, r = n - 1, k;

	int lb = INF, ub = -INF;

	while (l <= r){
		int mid = (l + r)/2;
		if (primes[mid] < a)
			l = mid + 1;
		else {
			r = mid - 1;
			lb = min(mid, lb);
		}
	}


	l = 0, r = n - 1;

	while (l <= r){
		int mid = (l + r)/2;
		if (primes[mid] > b)
			r = mid - 1;
		else {
			l = mid + 1;
			ub = max(mid, ub);
		}
	}

	if (lb == INF || ub == -INF){
		cout << "Bob" << endl;
		return 0;
	}

	n = ub - lb + 1;
	k = abs(b - a);

	n = (k + (n - 1));

	string ans = "Bob";


	if ((n | k) == n)
		ans = "Alice";

	cout << ans << endl;

	return 0;
}