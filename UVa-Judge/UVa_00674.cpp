#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll
#define mp make_pair
#define pb push_back

typedef long long int int64;
typedef unsigned long long int  uint64;

vector <int> basis = {1, 5, 10, 25, 50};
int obj;

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector <int> memo(10000, 0);
	memo[0] = 1;

	for (int i = 0; i < 5; i++)
		for (int j = basis[i]; j < 10000; j++)
			memo[j] += memo[j - basis[i]];
	
	while (cin >> obj){

		cout << memo[obj] << endl;
	}

	return 0;
}