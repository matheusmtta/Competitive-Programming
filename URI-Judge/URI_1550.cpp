#include <bits/stdc++.h>
 
#define MOD 1000000007
#define endl "\n"
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll
#define MAX 10010

typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

using namespace std;

int main() {
	int t; cin >> t;
	
	while (t--) {
		int a, b; cin >> a >> b;

		if (a == b) {
			cout << 0 << endl;
			continue;
		}

		queue <int> q;

		vector <int> visited(MAX, -1);

		visited[a] = 0;

		q.push(a);

		while (!q.empty()) {
			int c = q.front(); q.pop();

			string cstr = to_string(c);
			reverse(cstr.begin(), cstr.end());

			int x = stoi(cstr); int y = c + 1;

			if (x == b || y == b) {
				cout << visited[c] + 1 << endl;
				break;
			}

			if (x <= MAX && visited[x] == -1) {
				visited[x] = visited[c] + 1;
				q.push(x);
			}
			if (y <= MAX && visited[y] == -1) {
				visited[y] = visited[c] + 1;
				q.push(y);
			}

		}
	}

	return 0;
}