#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define endl "\n"
#define f first
#define s second
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll

typedef long long int int64;
typedef unsigned long long int  uint64;

vector <int> isprime(1000010, 1);
vector <int64> p;
vector <int64> ans;

void sieve(){
	isprime[0] = isprime[1] = 0;
	for (int64 i = 2; i <= 1000000; i++){
		if (isprime[i]){
			p.push_back(i);
			ans.push_back(i*i);
			for (int64 j = i*i; j <= 1000000; j += i){
				isprime[j] = 0;
			}
		}
	}
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	sieve();
	int n; cin >> n;
	for (int i = 0; i < n; i++){
		int64 x; cin >> x;
		int l = 0, r = ans.size()-1;
		bool flag = false;
		while (l <= r){
			int mid = (l+r)/2;
			if (ans[mid] == x){
				flag = true;
				break;
			}
			else if (ans[mid] < x) 
				l = mid + 1;
			else
				r = mid - 1;
		}
		flag ? cout << "YES" << endl : cout << "NO" << endl;
	}

	return 0;
}