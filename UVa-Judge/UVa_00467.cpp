#include <bits/stdc++.h>

using namespace std;

int main(){

	string str;
	int q = 1;
	while(getline(cin, str)){
		vector <int> arr;
		stringstream ss(str);

		int mn = 1000000;

		int x;

		while(ss >> x){
			arr.push_back(x);
			mn = min(mn, x);
		}

		int sz = arr.size();

		int k;

		while (mn <= 3600 && k != sz){
			for (k = 0; k < sz; k++){
				if ((mn % (arr[k]*2)) >= arr[k]-5) break;
			}
			mn++;
		}

	    if (--mn <= 3600 && k == sz){
	    	int minu = mn/60;
	    	int sec = mn%60;
	    	cout << "Set " << q << " synchs again at " << minu << " minute(s) and " << sec << " second(s) after all turning green.\n";
	    }
	    
	    else
	    	cout << "Set " << q << " is unable to synch after one hour.\n";

		q++;
	}

	return 0;
}