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

	int n;

	while (cin >> n){
		stack <int> st;
		queue <int> q;
		priority_queue<int> pq;
		int sz = 0;
		int a = 0, b = 0, c = 0;
		for (int i = 0; i < n; i++){
			int cmd, e; cin >> cmd >> e;
			if (cmd == 1){
				st.push(e);
				q.push(e);
				pq.push(e);
			}
			else {
				if (e ==   st.top()) a++;
				if (e ==  q.front()) b++;
				if (e == pq.top()) c++;
				st.pop(); q.pop(); pq.pop();
				sz++;
			}
		}
		bool A = false, B = false, C = false;
		if (a == sz) A = true;
		if (b == sz) B = true;
		if (c == sz) C = true;

		if (A && !B && !C) cout << "stack" << endl;
		else if (!A && B && !C) cout << "queue" << endl;
		else if (!A && !B && C) cout << "priority queue" << endl;
		else if (!A && !B && !C) cout << "impossible" << endl;
		else cout << "not sure" << endl;
	}

	return 0;
}