#include <bits/stdc++.h>

using namespace std;

vector <string> ana;
vector <pair <string, string>> ans;

int main(){
	string str;

	while (1){
		cin >> str;

		if (str == "#") break;

		string phr, aux;

		aux = str;

		for (int j = 0; j < aux.length(); j++){
			aux[j] = tolower(aux[j]);
		}

		sort(aux.begin(), aux.end());
		
		ans.push_back(make_pair(str, aux));

		ana.push_back(aux);
	}

	int count = 0;

	sort(ans.begin(), ans.end());
	
	for (int i = 0; i < ans.size(); i++){
		for (int j = 0; j < ana.size(); j++){
			if (ans[i].second == ana[j])
				count++;
		}

		if (count <= 1) cout << ans[i].first << endl;
		count = 0;
	}

	return 0;
}