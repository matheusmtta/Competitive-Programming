#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t, q = 1, s, k, l, x; cin >> t;
	while (t--){
		vector <int> f(10001, 0), s(10001, 0), t(10001, 0);
		vector <int> a, b, c;

		int mx = -1;

		int p; cin >> p;
		for (int i = 0; i < p; i++){
			cin >> x;
			mx = max(x, mx);
			f[x] = 1;
		}

		int k; cin >> k;
		for (int i = 0; i < k; i++){
			cin >> x;
			mx = max(x, mx);
			s[x] = 1;
		}

		int l; cin >> l;
		for (int i = 0; i < l; i++){
			cin >> x;
			mx = max(x, mx);
			t[x] = 1;
		}

		for (int i = 1; i <= mx; i++){
			if (f[i] && !s[i] && !t[i]) a.push_back(i);
			if (!f[i] && s[i] && !t[i]) b.push_back(i);
			if (!f[i] && !s[i] && t[i]) c.push_back(i);
		}

		sort(a.begin(), a.end()); sort(b.begin(), b.end()); sort(c.begin(), c.end());

		int sa = a.size();
		int sb = b.size();
		int sc = c.size();

		cout << "Case #" << q << ":" << endl;
		if (sa >= sb && sa >= sc){
			cout << 1 << " " << a.size();
			if (a.size() > 0) cout << " ";
			for (int i = 0; i < a.size(); i++){
				cout << a[i];
				if (i != a.size()-1) cout << " ";
			}
			cout << endl;
		}

		if (sb >= sa && sb >= sc){
			cout << 2 << " " << b.size();
			if (b.size() > 0) cout << " ";
			for (int i = 0; i < b.size(); i++){
				cout << b[i];
				if (i != b.size()-1) cout << " ";
			}
			cout << endl;
		}

		if (sc >= sa && sc >= sb){
			cout << 3 << " " << c.size();
			if (c.size() > 0) cout << " ";
			for (int i = 0; i < c.size(); i++){
				cout << c[i];
				if (i != c.size()-1) cout << " ";
			}
			cout << endl;
		}

		q++;   
	}
}