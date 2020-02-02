#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;

    while (n--){
    	int m; cin >> m; 
    	float sum = 0;
    	double me;

    	vector <float> aluns;

    	for (int i = 0; i < m; i++){
    		float x; cin >> x;
    		aluns.push_back(x);
    		sum += x;
    	}

    	me = sum/m;

    	float ans = 0;

    	for (int i = 0; i < m; i++){
    		if (aluns[i] > me)
    			ans ++;
    	}

    	printf("%.3lf%c\n", (ans/(1.0*m))*100, '%');
    }
    
    return 0;
}