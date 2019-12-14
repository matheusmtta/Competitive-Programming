#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, m;
	while (1){
		cin >> n >> m;
		int ans, aux;
		if (n == 0 && m == 0) return 0;
		if (n == 0 || m == 0) ans = 0;
		else if (n == 1 || m == 1) ans = n*m;
		else if (n == 2 && m == 2) ans = 4;
		else if (n == 2 || m == 2){
			aux = max(n, m);
			ans = (aux/4)*4;
			if (aux%4 == 1) ans += 2;
			else if (aux%4 > 1) ans += 4; 
		}
		else ans = ceil((n*m)/2.0);

		printf("%d knights may be placed on a %d row %d column board.\n", ans, n, m);
	}
}