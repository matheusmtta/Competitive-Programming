#include <bits/stdc++.h>

using namespace std;

//Get all permutations of a given array
//Time complexity: O(n!)

vector <string> ans;

void permute(string str){
	do {
		ans.push_back(str);
	} while(next_permutation(str.begin(), str.end()));
}

int main(){
	string str = "ABCD";
	permute(str);
	
	sort(ans.begin(), ans.end());

	for (int i  = 0; i < ans.size(); i++)
		cout << ans[i] << endl;

	return 0;
}