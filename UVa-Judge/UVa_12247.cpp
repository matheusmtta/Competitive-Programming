#include <bits/stdc++.h>

using namespace std;

int main(){

	int m[3], f[3];

	while(1){
		vector <int> mem(53, 0);

		for (int i = 0; i < 3; i++){
			cin >> f[i];
			mem[f[i]] = 1;
		}

		for (int i = 0; i < 2; i++){
			cin >> m[i];
			mem[m[i]] = 1;
		}

		if (f[0] == 0) return 0;
		sort(f, f+3);

		int ans;
		int resp = -1;
		
		for (int i = 1; i <= 52; i++){
			if (!mem[i]){
				ans = 0;
				m[2] = i;
				int aux[3];

				for (int i = 0; i < 3; i++)
					aux[i] = m[i];

				sort(aux, aux+3);

				if (aux[2] > f[0])
					ans++;
				if (aux[0] > f[1])
					ans++;
				if (aux[1] > f[2])
					ans++;

				if (ans >= 2){
					resp = i;
					break;
				}
			}
		}

		cout << resp << endl;
	}

	return 0;
}