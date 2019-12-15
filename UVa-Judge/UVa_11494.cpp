#include <bits/stdc++.h>

using namespace std;

int main(){
	int a, b, c, d;
	while (1){
		cin >> a >> b >> c >> d;
		if (a == 0 && b == 0 && c == 0 && d == 0) return 0;
		if (a == c && b == d) {cout << 0 << endl;}
		else if ((abs(a-c) == abs(b-d)) || a-c == 0 || b - d == 0)  {cout << 1 << endl;}
		else cout << 2 << endl;
	}
	return 0;
}
