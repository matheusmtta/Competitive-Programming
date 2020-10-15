#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll
#define mp make_pair
#define pb push_back
#define MAX 2000010

typedef long long int int64;
typedef unsigned long long int  uint64;

vector <int> divisors(MAX, 0);
vector <int> primes;
bitset <MAX> is_prime;

//Extended version
int64 sieve_divisors(int64 n){
	int64 i = 0, ans = 1;
	
	while (primes[i]*primes[i] <= n){
		int64 exp = 0;
		while (n%primes[i] == 0){
			n /= primes[i];
			exp++;
		}
		ans *= (exp+1);
		i++;
	}

	if (n != 1) ans *= 2;
	return ans;
}

int64 sieve_divisors(int64 n, int fac){
	int64 exp = 0;
	
	while (n%fac == 0){
		n /= fac;
		exp++;
	}
	if (n != 1) exp *= 2;
	
	return exp;
}

void sieve(){
	is_prime.set();
	is_prime[0] = is_prime[1] = 0;

	for (int64 i = 2; i <= MAX; i++){
		if (is_prime[i]){
			divisors[i] = 2;
			primes.push_back(i);
			for (int64 j = i+i; j <= MAX; j += i){
				is_prime[j] = 0;
				int rsp = sieve_divisors(j, i);
				if (divisors[j] == 0)
					divisors[j] += rsp + 1;
				else
					divisors[j] *= (rsp + 1);
			}
		}
	}
}


int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	while (cin >> n)
		cout << divisors[n] << endl;

	return 0;
}