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

	int t = 1;

	while (true){
		int n, q;
		cin >> n >> q;
		deque <int64> arr;

		if (n == 0 && q == 0) return 0;

		for (int64 i = 1; i <= n && i <= 1000; i++){
			arr.push_back(i);
		}

		cout << "Case " << t << ":" << endl;

		while (q--){
			string cmd; cin >> cmd;
			if (cmd == "N"){
				int64 tmp = arr.front();
				cout << tmp << endl;
				arr.pop_front();
				arr.push_back(tmp);
			}
			else {
				int64 x; cin >> x;
				deque<int64>::iterator it; 
				for (it = arr.begin(); it != arr.end(); it++){
					if (*it == x){
						arr.erase(it);
						break;
					}
				}
				arr.push_front(x);
			}
		}
		t++;
	}

	return 0;
}