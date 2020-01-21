#include <bits/stdc++.h>

using namespace std;


int main(){
	string str;
	while(getline(cin, str)){
		vector <int> arr;
		stringstream ss(str);

		int x;

		while(ss >> x) arr.push_back(x);

		bool ans = true;

		bool count[arr.size()+1];

		for (int i = 0; i < arr.size()+1; i++)
			count[i] = false;

		for (int i = 0; i < arr.size()-1; i++){
			int x = abs(arr[i]-arr[i+1]);
			if (x > 0 && x <= arr.size()-1)
				count[x] = true;
		}

		for (int i = 1; i < arr.size()-1; i++){
			if (!count[i]) ans = false;
		}

		ans ? cout << "Jolly" << endl : cout << "Not jolly" << endl;
	}

	return 0;
}