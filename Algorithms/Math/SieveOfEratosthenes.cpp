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

//Time complexity : O(n*log(log(n)))

const int MAX = 1000100;

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

	sieve();

	for (auto k : primes){
		cout << k << endl;
	}

	return 0;
}