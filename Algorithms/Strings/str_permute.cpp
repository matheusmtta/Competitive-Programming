#include <bits/stdc++.h>

using namespace std;

//repetitions allowed 

vector <string> ans;

void permute(string str, int left, int right){
	if (left == right) ans.push_back(str);
	else {
		for (int i = left; i <= right; i++){
			swap(str[left], str[i]);
			permute(str, left+1, right);
			swap(str[left], str[i]);
		}
	} 
}

int main(){
	string str = "ABCD";
	permute(str, 0, str.length()-1);
	
	sort(ans.begin(), ans.end());

	for (int i  = 0; i < ans.size(); i++)
		cout << ans[i] << endl;

	return 0;
}