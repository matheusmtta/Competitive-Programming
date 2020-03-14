#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define MP make_pair
#define PB push_back

typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

int memo[1000100];
vector <int> a(30);
int N, M;

bool compare(const int &a, const int &b){
	return a > b;
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;

	while (T--){
		int N, M; cin >> N >> M;

		for (int i = 0; i < N; i++){
			cin >> a[i];
		}

		memset(memo, 1000100, sizeof(memo));

		sort(a.begin(), a.end(), compare);

		memo[0] = 0;

		for (int i = 1; i <= M; i++){
			memo[i] = INF;
			for (int j = 0; j < N; j++){
				if (a[j] <= i)
					memo[i] = min(memo[i], memo[i-a[j]]+1);
			}
		}

		cout << memo[M] << endl;
	}

	return 0;
}