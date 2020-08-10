#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll
#define mp make_pair
#define pb push_back

typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k; cin >> n >> k;
	priority_queue <int, vector<int>, greater<int>> both, bob, alice;
	int aux1 = 0, aux2 = 0;
	for (int i = 0; i < n; i++){
		int m, a, b;
		cin >> m >> a >> b;
		if (a && b){
			both.push(m);
			aux1++;
			aux2++;
		}
		else if (a && !b){
			alice.push(m);
			aux1++;
		}
		else if (!a && b){
			bob.push(m);
			aux2++;
		}
	}

	if (aux1 < k || aux2 < k) {cout << -1 << endl; exit(0);}

	int read_alice = 0, read_bob = 0;
	int ans = 0;

	while (1){
		if (read_alice >= k && read_bob >= k) break;
		if (read_alice < k && read_bob < k){
			int a = -1, b = -1, c = -1;
			if (!both.empty())
				c = both.top();
			if (!alice.empty())
				a = alice.top();
			if (!bob.empty())
				b = bob.top();
			if (c == -1){
				ans += a+b;
				bob.pop(); alice.pop();
			}
			else if (a == -1 || b == -1){
				ans += c;
				both.pop();
			}
			else if (a != -1 && b != -1 && c != -1){
				if (c > a+b){
					ans += a+b;
					alice.pop();
					bob.pop();
				}
				else {
					ans += c;
					both.pop();
				}
			}
			read_alice++; read_bob++;
			continue;
		}
		if (read_alice < k){
			int a = -1, c = -1;
			if (!both.empty())
				c = both.top();
			if (!alice.empty())
				a = alice.top();

			if (a == -1){
				ans += c;
				both.pop();
			}
			else if (c == -1){
				ans += a;
			}
			else {
				ans += min(a, c);
				if (a < c) alice.pop();
				else both.pop();
			}
			read_alice++;
		}
		if (read_bob < k){
			int a = -1, c = -1;
			if (!both.empty())
				c = both.top();
			if (!bob.empty())
				a = bob.top();

			if (a == -1){
				ans += c;
				both.pop();
			}
			else if (c == -1){
				ans += a;
			}
			else {
				ans += min(a, c);
				if (a < c) bob.pop();
				else both.pop();
			}
			read_bob++;
		}
	}
	cout << ans << endl;

	return 0;
}