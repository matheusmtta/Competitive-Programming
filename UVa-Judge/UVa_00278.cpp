#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	while (n--){
		char type;
		int n, m;
		cin >> type >> n >> m;
		if (type == 'r') cout << min(n, m) << endl;
		else if (type == 'k') cout << ceil(((float)n*(float)m)/2) << endl;
		else if (type == 'Q') cout << min(n, m) << endl;
		else if (type == 'K') cout << (int)(ceil(n/2.0)*ceil(m/2.0)) << endl;
	}
}