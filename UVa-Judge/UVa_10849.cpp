#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	while (n--){
		int k; cin >> k;
		int size; cin >> size;

		for (int i = 0; i < k; i++){
			int a, b; cin >> a >> b;
			int c, d; cin >> c >> d;

			if (a == c && b == d) cout << 0 << endl;
			else if ((c+d)%2 != (a+b)%2) cout << "no move" << endl;
			else if (abs(a-c) == abs(b-d)) cout << 1 << endl;
			else cout << 2 << endl;
		}
	}
	return 0;
}
