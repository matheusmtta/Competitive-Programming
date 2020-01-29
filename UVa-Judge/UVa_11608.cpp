#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int q = 1;

	while (1){
		int b; cin >> b;
		if (b < 0) return 0;
		vector <int> d, n;

		for (int i = 0; i < 12; i++){
			int x; cin >> x;
			d.push_back(x);
		}

		for (int i = 0; i < 12; i++){
			int x; cin >> x;
			n.push_back(x);
		}


		cout << "Case " << q << ":" << endl;  
		for (int i = 0; i < 12; i++){
			if (b - n[i] >= 0){
				cout << "No problem! :D" << endl;
				b -= n[i];
			}
			else cout << "No problem. :(" << endl;
			b += d[i];
		}

		q++;
	}
}