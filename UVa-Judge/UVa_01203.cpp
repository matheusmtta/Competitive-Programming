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

	string str; int x, y;
	vector <pair <int, int>> vec;

	while (cin >> str){
		if (str == "#") break;
		cin >> x >> y;
		vec.PB(MP(y, x));
	}


	priority_queue <int> q;

	int K; cin >> K;

	int t = 0;

	while (K){
		for (auto i : vec){
			if (t%i.first == 0 && t != 0)
				q.push(i.second);
		}


		bool f = true;

		stack <int> st;

		while (!q.empty()){
			st.push(q.top());
			q.pop();
			if (f) K--;
		}

		while (!st.empty()){
			cout << st.top() << endl;
			st.pop();
		}

		t++;
	}

	return 0;
}