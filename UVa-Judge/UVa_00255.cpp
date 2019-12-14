#include <bits/stdc++.h>

using namespace std;

bool allow(int x, int d){
	if (x > 63 || x < 0) return false;
	return true;
}

int main(){
	int x, y, d;
	while(cin >> x >> y >> d){
		if (x == y) {cout << "Illegal state" << endl; continue;}
		else{
		 if ((y%8 != d%8 && y/8 != d/8) || (d == x) || (d == y)) 
		 	{cout << "Illegal move" << endl; continue;}
		 if (y%8 == d%8 && d%8 == x%8) {
				if (y > x && x > d) {cout << "Illegal move" << endl; continue;}
				else if (d > x && x > y) {cout << "Illegal move" << endl; continue;}
			}

			if (y/8 == d/8 && d/8 == x/8){
				if (y > x && x > d) {cout << "Illegal move" << endl; continue;}
				else if (d > x && x > y) {cout << "Illegal move" << endl; continue;}
			}
		}
		
		if (d%8 == x%8) {
			if (x+1 == d || x-1 == d || x+8 == d || x-8 == d) {cout << "Move not allowed" << endl; continue;}
		}
		
		if (d/8 == x/8) {
			if (x+1 == d || x-1 == d || x+8 == d || x-8 == d) {cout << "Move not allowed" << endl; continue;}
		}

		int ans = 0;
		if ((x == 56 && d == 49) || (x == 0 && d == 9) || (x == 7 && d == 14) || (x == 63 && d == 54)) ans=1;
		if (!ans) cout << "Continue" << endl;
		else cout << "Stop" << endl;
	}
}