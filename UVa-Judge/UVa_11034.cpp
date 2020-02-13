#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)1e9
#define MP make_pair
#define PB push_back

typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;

	while (t--){
		int l, m; cin >> l >> m;
		l *= 100;

		queue <int> left, right;

		string str;
		int x;

		for (int i = 0; i < m; i++){
			cin >> x >> str;
			if (str == "left")
				left.push(x);
			else 
				right.push(x);
		}

		int side = 0;
		//left  ----> 0
		//right ----> 1 
		int ans = 0;

		while (!left.empty() || !right.empty()){

			int lim = 0;
			bool flag = false;

			if (side && right.empty() && !left.empty()) ans++;
			if (!side && left.empty() && !right.empty()) ans++;

			if (side){
				while (!right.empty() &&
					   lim + right.front() <= l){
					if (!flag) ans ++;
					flag = true;
					lim += right.front();
					right.pop();
				}
			}
			else{
				while (!left.empty() &&
					   lim + left.front() <= l){
					if (!flag) ans++;
					flag = true;
					lim += left.front();
					left.pop();
				}
			}

			side ^= 1;
		}

		cout << ans << endl;
	}

	return 0;
}