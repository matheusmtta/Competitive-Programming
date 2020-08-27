#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll
#define mp make_pair
#define pb push_back

typedef long long int int64;
typedef unsigned long long int  uint64;

int n, k, sz; 
int64 memo[200][1120][20];
vector <int64> primes;
bitset <10000> is_prime;

void sieve(){
	is_prime.set();
	is_prime[0] = is_prime[1] = 0;

	for (int i = 2; i <= 1200; i++){
		if (is_prime[i]){
			primes.push_back(i);
			for (int j = i*i; j <= 1200; j += i)
				is_prime[j] = 0;
		}
	}
}

int64 dp(int idx, int sum, int num){
	if (num == k && sum == n)
		return 1;
	//cout << n << " " << k << endl;
	//cout << sum << " " << num << " " << idx << endl;
	if (sum > n || num > k || idx >= sz)
		return 0;


	int64 &curr = memo[idx][sum][num];

	if (curr != -1)
		return curr;

	curr = dp(idx+1, sum, num) + dp(idx+1, sum+primes[idx], num+1); 

	return curr;
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	sieve();

	sz = primes.size();

	while (cin >> n >> k){
		if (n == 0 && k == 0) return 0;
		memset(memo, -1, sizeof memo);
		cout << dp(0, 0, 0) << endl;
	}

	return 0;
}