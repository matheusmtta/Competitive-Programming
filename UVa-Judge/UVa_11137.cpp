#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll
#define mp make_pair
#define pb push_back

typedef long long int int64;
typedef unsigned long long int  uint64;

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector <int64> cubes;
	for (int i = 1; i <= 21; i++)
		cubes.push_back(i*i*i);

	vector <int64> memo(10010, 0);
	memo[0] = 1;
	
	for (int i = 0; i < cubes.size(); i++){
		for (int j = cubes[i]; j <= 10000; j++){
			memo[j] += memo[j - cubes[i]];
		}
	}

	int n; 
	while (cin >> n) cout << memo[n] << endl;

	return 0;
}