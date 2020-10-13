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
bitset <MAX> is_prime;

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

	sieve();

	vector <int> ans(MAX, 0);

	ans[1] = 0;

	for (int i = 2; i <= MAX; i++){
		ans[i] = ans[i - 1];
		if (is_prime[divisors[i]])
			ans[i]++;
	}

	int n;
	while (cin >> n)
		cout << ans[n] << endl;

	return 0;
}