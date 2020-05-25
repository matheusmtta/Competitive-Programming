#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll
#define MP make_pair
#define PB push_back

typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

		//F -> Fuel Consumption
		//L -> Leak
		//M -> Mechanic
		//G -> Gas Station
		//E -> END

vector <pair<double, string>> path;
vector <double> fuel;

int main(){	
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);

	string str;

	while (getline(cin, str)){
		double a, b;
		bool f = true;
		string curr;

		for (int i = 0; i < str.size(); i++){
			if (str[i] == ' ' && f){
				f = false;
				a = stoi(curr);
				curr = "";
				continue;
			}
			if (str[i] == ' ' && !f){
				curr = "";
				continue;
			}
			curr += str[i];
		}

		b = stoi(curr);

		if (a == 0 && b == 0) return 0;

		double lst = b;

		path.push_back(MP(a, "F"));
		fuel.push_back(lst/100.0);

		//F -> Fuel Consumption
		//L -> Leak
		//M -> Mechanic
		//G -> Gas Station
		//E -> END

		//beggining/fuel consumption ---- event
		while (getline(cin, str)){
			double x; curr = "";
			vector <string> aux;
			for (int i = 0; i < str.size(); i++){
				if (str[i] == ' '){
					aux.push_back(curr);
					curr = "";
					continue;
				}
				curr += str[i];
			}
			aux.push_back(curr);
			if (aux[1] == "Fuel"){
				path.push_back(MP(stoi(aux[0]), "F"));
				lst = stoi(aux[3]);
			}
			if (aux[1] == "Leak")
				path.push_back(MP(stoi(aux[0]), "L"));
			if (aux[1] == "Mechanic")
				path.push_back(MP(stoi(aux[0]), "M"));
			if (aux[1] == "Gas")
				path.push_back(MP(stoi(aux[0]), "G"));
			if (aux[1] == "Goal"){
				path.push_back(MP(stoi(aux[0]), "E"));		
				fuel.push_back(lst);
				break;
			}
			fuel.push_back(lst/100.0);
		}
		
		double gas = 0, ans = 0, cost = 0;
		int ult = 0, lk = 0;

		for (int i = 0; i < path.size(); i++){

			gas += cost*(path[i].first - ult);
			gas += lk*(path[i].first - ult);

			ans = max(ans, gas);

			if (path[i].second == "L")
				lk++;
			if (path[i].second == "M")
				lk = 0;
			if (path[i].second == "G")
				gas = 0;
			if (path[i].second == "F")
				cost = fuel[i];

			ult = path[i].first;
		}

		printf("%.3lf\n", ans);

		fuel.clear();
		path.clear();
	}	

	return 0;
}