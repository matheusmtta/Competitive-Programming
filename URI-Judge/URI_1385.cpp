#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define MP make_pair
#define PB push_back

typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

void print_ans(vector <vector<int>> mtx, vector <int> ans, vector <string> name, int P){
	if (P == 1) cout << "P1 Totals" << endl;
	if (P == 2) cout << "P1 P2 Totals" << endl;
	if (P == 3) cout << "P1 P2 P3 Totals" << endl;
	if (P == 4) cout << "P1 P2 P3 P4 Totals" << endl;
	if (P == 5) cout << "P1 P2 P3 P4 P5 Totals" << endl;	

	for (int i = 0; i < mtx.size(); i++){
		cout << name[i];
		for (int j = 0; j < mtx[i].size(); j++){
			cout << " " << mtx[i][j];
		}
		cout << endl;
	}

	cout << "TP";
	for (int i = 0; i < ans.size(); i++)
		cout << " " << ans[i];
	cout << endl;
}

void get_ans(vector <pair <string, vector <int>> > mtx, vector <vector <int>> ans, int P){
		map <string, int> q;

		for (int i = 0; i < mtx.size(); i++){
			q[mtx[i].first]++;
		}

		int a = 0, b = 0, c = 0, d = 0, e = 0;
		int count = 0, lst = 0;
		set <string> used;
		vector <string> names;

		for (int i = 0; i < mtx.size(); i++){
			if (used.find(mtx[i].first) == used.end()){
				if (count == 0) a = q[mtx[i].first];
				if (count == 1) b = q[mtx[i].first];
				if (count == 2) c = q[mtx[i].first];
				if (count == 3) d = q[mtx[i].first];
				if (count == 4) e = q[mtx[i].first];
				count++;
				used.insert(mtx[i].first);
				names.push_back(mtx[i].first);
			}
		}

		vector <pair <vector<vector <int>>, vector <int>>> choices;

		if (q.size() == 1){
			for (int i = a-1; i >= 0; i--){
				vector <int> tmp;
				tmp = mtx[i].second;

				for (int s = 0; s < ans.size(); s++){
					pair <vector<vector <int>>, vector <int>> rsp;
					if (tmp == ans[s]){
						rsp.first.push_back(mtx[i].second);
						rsp.second = ans[s];
						print_ans(rsp.first, rsp.second, names, P);
						return;	
					}
				}
			}
		}
		if (q.size() == 2){
			for (int i = a-1; i >= 0; i++){
				for (int j = a+b-1; j >= a; j++){
					vector <int> tmp(P+1, 0);

					for (int u = 0; u < P+1; u++)
						tmp[u] += mtx[i].second[u];

					for (int u = 0; u < P+1; u++)
						tmp[u] += mtx[j].second[u];

					for (int s = 0; s < ans.size(); s++){
						pair <vector<vector <int>>, vector <int>> rsp;
						if (tmp == ans[s]){
							rsp.first.push_back(mtx[i].second);
							rsp.first.push_back(mtx[j].second);
							rsp.second = ans[s];
							print_ans(rsp.first, rsp.second, names, P);
							return;
						}
					}
				}
			}
		}
		if (q.size() == 3){
			for (int i = a-1; i >= 0; i--){
				for (int j = a+b-1; j >= a; j--){
					for (int k = a+b+c-1; k >= a+b; k--){
						vector <int> tmp(P+1, 0);

						for (int u = 0; u < P+1; u++)
							tmp[u] += mtx[i].second[u];

						for (int u = 0; u < P+1; u++)
							tmp[u] += mtx[j].second[u];

						for (int u = 0; u < P+1; u++)
							tmp[u] += mtx[k].second[u];

						for (int s = 0; s < ans.size(); s++){
							pair <vector<vector <int>>, vector <int>> rsp;
							if (tmp == ans[s]){
								rsp.first.push_back(mtx[i].second);
								rsp.first.push_back(mtx[j].second);
								rsp.first.push_back(mtx[k].second);
								rsp.second = ans[s];
								print_ans(rsp.first, rsp.second, names, P);
								return;
							}
						}
					}
				}
			}
		}
		if (q.size() == 4){
			for (int i = a-1; i >= 0; i--){
				for (int j = a+b-1; j >= a; j--){
					for (int k = a+b+c-1; k >= a+b; k--){
						for (int w = a+b+c+d-1; w >= a+b+c; w--){
							vector <int> tmp(P+1, 0);

							for (int u = 0; u < P+1; u++)
								tmp[u] += mtx[i].second[u];

							for (int u = 0; u < P+1; u++)
								tmp[u] += mtx[j].second[u];

							for (int u = 0; u < P+1; u++)
								tmp[u] += mtx[k].second[u];

							for (int u = 0; u < P+1; u++)
								tmp[u] += mtx[w].second[u];

							for (int s = 0; s < ans.size(); s++){
								pair <vector<vector <int>>, vector <int>> rsp;
								if (tmp == ans[s]){
									rsp.first.push_back(mtx[i].second);
									rsp.first.push_back(mtx[j].second);
									rsp.first.push_back(mtx[k].second);
									rsp.first.push_back(mtx[w].second);
									rsp.second = ans[s];									
									print_ans(rsp.first, rsp.second, names, P);
									return;	
								}
							}
						}
					}
				}
			}
		}
		if (q.size() == 5){
			for (int i = a-1; i >= 0; i--){
				for (int j = a+b-1; j >= a; j--){
					for (int k = a+b+c-1; k >= a+b; k--){
						for (int w = a+b+c+d-1; w >= a+b+c; w--){
							for (int z = a+b+c+d+e-1; z >= a+b+c+d; z--){
								vector <int> tmp(P+1, 0);

								for (int u = 0; u < P+1; u++)
									tmp[u] += mtx[i].second[u];

								for (int u = 0; u < P+1; u++)
									tmp[u] += mtx[j].second[u];

								for (int u = 0; u < P+1; u++)
									tmp[u] += mtx[k].second[u];

								for (int u = 0; u < P+1; u++)
									tmp[u] += mtx[w].second[u];

								for (int u = 0; u < P+1; u++)
									tmp[u] += mtx[z].second[u];

								for (int s = 0; s < ans.size(); s++){
									pair <vector<vector <int>>, vector <int>> rsp;
									if (tmp == ans[s]){
										rsp.first.push_back(mtx[i].second);
										rsp.first.push_back(mtx[j].second);
										rsp.first.push_back(mtx[k].second);
										rsp.first.push_back(mtx[w].second);
										rsp.first.push_back(mtx[z].second);
										rsp.second = ans[s];
										print_ans(rsp.first, rsp.second, names, P);
										return;
									}
								}
							}
						}
					}
				}
			}
		}		
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;

	while (t--){
		string b; cin >> b;

		int p = 0;

		for (int i = 0; i < b.length(); i++){
			if (b[i] == 'P') p++;
		}

		if (p == 1){
			vector <pair <string, vector <int>> > mtx;
			vector <string> pes;
			string str;
			while (true){
				cin >> str;
				if (str[0] == 'T' && str[1] == 'P') break;

				string num, name;

				for (int i = 0; i < str.length(); i++){
					if (str[i] <= '9' && str[i] >= '0')
						num += str[i];
					else
						name += str[i];
				}

				for (int i = 3; i > 0; i--){
					pair <string, vector <int>> tmp;
					if (i > num.length()) continue;

					string a = num.substr(0, i);

					if (a[0] == '0' && a != "0") continue;

					string b = num.substr(i, num.length()-i);

					if (b == "" || b.length() >= 5 || (b[0] == '0' && b != "0")) continue;

					int x = stoi(a);
					int y = stoi(b);

					if (x == y){
						tmp.first = name;
						tmp.second.push_back(x);
						tmp.second.push_back(y);
						mtx.push_back(tmp);
					}
				}
			}

			vector <vector <int>> ans;
			string num;

			for (int i = 0; i < str.length(); i++){
				if (str[i] <= '9' && str[i] >= '0')
					num += str[i];
			}

			for (int i = 4; i > 0; i--){
				vector <int> tmp;
				if (i > num.length()) continue;

				string a = num.substr(0, i);

				if (a[0] == '0' && a != "0") continue;

				string b = num.substr(i, num.length()-i);

				if (b == "" || b.length() >= 5 || (b[0] == '0' && b != "0")) continue;

				int x = stoi(a);
				int y = stoi(b);

				if (x == y){
					tmp.push_back(x);
					tmp.push_back(y);
					ans.push_back(tmp);
				}
			}

			
				get_ans(mtx, ans, 1);
		}

		else if (p == 2){
			vector <pair <string, vector <int>> > mtx;
			vector <string> pes;
			string str;
			while (true){
				cin >> str;
				if (str[0] == 'T' && str[1] == 'P') break;

				string num, name;

				for (int i = 0; i < str.length(); i++){
					if (str[i] <= '9' && str[i] >= '0')
						num += str[i];
					else
						name += str[i];
				}

				for (int i = 3; i > 0; i--){
					if (i > num.length()) continue;

					string a = num.substr(0, i);

					if (a[0] == '0' && a != "0") continue;

					for (int j = 3; j > 0; j--){
						pair <string, vector <int>> tmp;
						if (i + j > num.size()) continue;

						string b = num.substr(i, j);

						if (b[0] == '0' && b != "0") continue;

						string c = num.substr(i+j, num.length()-i-j);

						if (c == "" || c.size() >= 6 || (c[0] == '0' && c != "0")) continue;

						int x = stoi(a);
						int y = stoi(b);
						int z = stoi(c);

						if (x + y == z){
							tmp.first = name;
							tmp.second.push_back(x);
							tmp.second.push_back(y);
							tmp.second.push_back(z);
							mtx.push_back(tmp);
						}
					}
				}
			}

			string num;

			for (int i = 0; i < str.length(); i++){
				if (str[i] <= '9' && str[i] >= '0')
					num += str[i];
			}

			vector <vector <int>> ans;

			for (int i = 4; i > 0; i--){
				if (i > num.length()) continue;

				string a = num.substr(0, i);

				if (a[0] == '0' && a != "0") continue;

				for (int j = 4; j > 0; j--){
					vector <int> tmp;
					if (i + j > num.size()) continue;

					string b = num.substr(i, j);

					if (b[0] == '0' && b != "0") continue;

					string c = num.substr(i+j, num.length()-i-j);

					if (c == "" || c.size() >= 6 || (c[0] == '0' && c != "0")) continue;

					int x = stoi(a);
					int y = stoi(b);
					int z = stoi(c);

					if (x + y == z){
						tmp.push_back(x);
						tmp.push_back(y);
						tmp.push_back(z);
						ans.push_back(tmp);
					}
				}
			}

			
				get_ans(mtx, ans, 2);
		}

		else if (p == 3){
			vector <pair <string, vector <int>>> mtx;
			vector <string> pes;
			string str;
			while (true){
				cin >> str;
				if (str[0] == 'T' && str[1] == 'P') break;

				string num, name;

				for (int i = 0; i < str.length(); i++){
					if (str[i] <= '9' && str[i] >= '0')
						num += str[i];
					else
						name += str[i];
				}

				for (int i = 3; i > 0; i--){
					if (i > num.length()) continue;

					string a = num.substr(0, i);

					if (a[0] == '0' && a != "0") continue;

					for (int j = 3; j > 0; j--){
						if (i + j > num.length()) continue;

						string b = num.substr(i, j);

						if (b[0] == '0' && b != "0") continue;

						for (int k = 3; k > 0; k--){
							pair <string, vector <int>> tmp;
							if (i + j + k > num.size()) continue;

							string c = num.substr(i+j, k);

							if (c[0] == '0' && c != "0") continue;

							string d = num.substr(i+j+k, num.length()-i-j-k);

							if (d == "" || d.size() >= 9 || (d[0] == '0' && d != "0")) continue;
						
							int x = stoi(a), y = stoi(b), z = stoi(c), w = stoi(d);

							if (x + y + z == w) {
								tmp.first = name;
								tmp.second.push_back(x); 
								tmp.second.push_back(y);
								tmp.second.push_back(z);
								tmp.second.push_back(w);
								mtx.push_back(tmp);
							}
						}
					}
				}
			}

			string num;

			for (int i = 0; i < str.length(); i++){
				if (str[i] >= '0' && str[i] <= '9')
					num += str[i];
			}

			vector <vector<int>> ans;

			for (int i = 4; i > 0; i--){
					if (i > num.length()) continue;

					string a = num.substr(0, i);

					if (a[0] == '0' && a != "0") continue;

					for (int j = 4; j > 0; j--){
						if (i + j > num.length()) continue;

						string b = num.substr(i, j);

						if (b[0] == '0' && a != "0") continue;

						for (int k = 4; k > 0; k--){
							vector <int> tmp;
							if (i + j + k > num.size()) continue;

							string c = num.substr(i+j, k);

							if (c[0] == '0' && c != "0") continue;

							string d = num.substr(i+j+k, num.length()-i-j-k);

							if (d == "" || d.size() >= 9 || (c[0] == '0' && c != "0")) continue;
						
							int x = stoi(a), y = stoi(b), z = stoi(c), w = stoi(d);

							if (x + y + z == w) {
								tmp.push_back(x); 
								tmp.push_back(y);
								tmp.push_back(z);
								tmp.push_back(w);
								ans.push_back(tmp);
							}
						}
					}
				}

				
					get_ans(mtx, ans, 3);
		}
		else if (p == 4){
			vector <pair <string, vector <int>>> mtx;
			vector <string> pes;
			string str;
			while (true){
				cin >> str;
				if (str[0] == 'T' && str[1] == 'P') break;

				string num, name;

				for (int i = 0; i < str.length(); i++){
					if (str[i] <= '9' && str[i] >= '0')
						num += str[i];
					else
						name += str[i];
				}

				for (int i = 3; i > 0; i--){
					if (i > num.length()) continue;

					string a = num.substr(0, i);

					if (a[0] == '0' && a != "0") continue;

					for (int j = 3; j > 0; j--){
						if (i + j > num.length()) continue;

						string b = num.substr(i, j);

						if (b[0] == '0' && b != "0") continue;

						for (int k = 3; k > 0; k--){
							if (i + j + k > num.size()) continue;

							string c = num.substr(i+j, k);

							if (c[0] == '0' && c != "0") continue;

							for (int l = 3; l > 0; l--){
								pair <string, vector <int>> tmp;
								if (i + j + k + l > num.size()) continue;

								string d = num.substr(i+j+k, l);

								if (d[0] == '0' && d != "0") continue;

								string e = num.substr(i+j+k+l, num.size()-i-j-k-l);

								if (e == "" || e.size() >= 9 || (e[0] == '0' && e != "0")) continue;

								int x = stoi(a);
								int y = stoi(b);
								int z = stoi(c);
								int w = stoi(d);
								int v = stoi(e);

								if (x+y+z+w == v){
									tmp.first = name;
									tmp.second.push_back(x);
									tmp.second.push_back(y);
									tmp.second.push_back(z);
									tmp.second.push_back(w);
									tmp.second.push_back(v);
									mtx.push_back(tmp);
								}
							}
						}
					}
				}
			}

			string num;

			for (int i = 0; i < str.length(); i++){
				if (str[i] >= '0' && str[i] <= '9')
					num += str[i];
			}

			vector <vector<int>> ans;

			for (int i = 4; i > 0; i--){
					if (i > num.length()) continue;

					string a = num.substr(0, i);

					if (a[0] == '0' && a != "0") continue;

					for (int j = 4; j > 0; j--){
						if (i + j > num.length()) continue;

						string b = num.substr(i, j);

						if (b[0] == '0' && b != "0") continue;

						for (int k = 4; k > 0; k--){
							if (i + j + k > num.size()) continue;

							string c = num.substr(i+j, k);

							if (c[0] == '0' && c != "0") continue;

							for (int l = 4; l > 0; l--){
								vector <int> tmp;
								if (i + j + k + l > num.size()) continue;

								string d = num.substr(i+j+k, l);

								if (d[0] == '0' && d != "0") continue;

								string e = num.substr(i+j+k+l, num.size()-i-j-k-l);

								if (e == "" || e.size() >= 9 || (e[0] == '0' && e != "0")) continue;

								int x = stoi(a);
								int y = stoi(b);
								int z = stoi(c);
								int w = stoi(d);
								int v = stoi(e);

								if (x+y+z+w == v){
									tmp.push_back(x);
									tmp.push_back(y);
									tmp.push_back(z);
									tmp.push_back(w);
									tmp.push_back(v);
									ans.push_back(tmp);
								}
							}
						}
					}
				}

				
					get_ans(mtx, ans, 4);

		}
		else if (p == 5){
			vector <pair <string, vector <int>>> mtx;
			vector <string> pes;
			string str;
			while (true){
				cin >> str;
				if (str[0] == 'T' && str[1] == 'P') break;

				string num, name;

				for (int i = 0; i < str.length(); i++){
					if (str[i] <= '9' && str[i] >= '0')
						num += str[i];
					else
						name += str[i];
				}

				for (int i = 3; i > 0; i--){
					if (i > num.length()) continue;

					string a = num.substr(0, i);

					if (a[0] == '0' && a != "0") continue;

					for (int j = 3; j > 0; j--){
						if (i + j > num.length()) continue;

						string b = num.substr(i, j);

						if (b[0] == '0' && b != "0") continue;

						for (int k = 3; k > 0; k--){
							if (i + j + k > num.size()) continue;

							string c = num.substr(i+j, k);

							if (c[0] == '0' && c != "0") continue;

							for (int l = 3; l > 0; l--){
								if (i + j + k + l > num.size()) continue;

								string d = num.substr(i+j+k, l);

								if (d[0] == '0' && d != "0") continue;

								for (int r = 3; r > 0; r--){
									pair <string, vector <int>> tmp;

									if (i+j+k+l+r > num.size()) continue;

									string e = num.substr(i+j+k+l, r);

									if (e[0] == '0' && e != "0") continue;

									string f = num.substr(i+j+k+l+r, num.size()-i-j-k-l-r);

									if (f == "" || f.size() >= 9 || (f[0] == '0' && f != "0")) continue;

									int x = stoi(a);
									int y = stoi(b);
									int z = stoi(c);
									int w = stoi(d);
									int v = stoi(e);
									int u = stoi(f);

									if (x+y+z+w+v == u){
										tmp.first = name;
										tmp.second.push_back(x);
										tmp.second.push_back(y);
										tmp.second.push_back(z);
										tmp.second.push_back(w);
										tmp.second.push_back(v);
										tmp.second.push_back(u);
										mtx.push_back(tmp);
									}
								}
							}
						}
					}
				}
			}

			string num;

			for (int i = 0; i < str.length(); i++){
				if (str[i] >= '0' && str[i] <= '9')
					num += str[i];
			}

			vector <vector<int>> ans;

			for (int i = 4; i > 0; i--){
					if (i > num.length()) continue;

					string a = num.substr(0, i);

					if (a[0] == '0' && a != "0") continue;

					for (int j = 4; j > 0; j--){
						if (i + j > num.length()) continue;

						string b = num.substr(i, j);

						if (b[0] == '0' && b != "0") continue;

						for (int k = 4; k > 0; k--){
							if (i + j + k > num.size()) continue;

							string c = num.substr(i+j, k);

							if (c[0] == '0' && c != "0") continue;

							for (int l = 4; l > 0; l--){
								if (i + j + k + l > num.size()) continue;

								string d = num.substr(i+j+k, l);

								if (d[0] == '0' && d != "0") continue;

								for (int r = 4; r > 0; r--){
									vector <int> tmp;

									if (i+j+k+l+r > num.size()) continue;

									string e = num.substr(i+j+k+l, r);

									if (e[0] == '0' && e != "0") continue;

									string f = num.substr(i+j+k+l+r, num.size()-i-j-k-l-r);

									if (f == "" || f.size() >= 9 || (f[0] == '0' && f != "0")) continue;

									int x = stoi(a);
									int y = stoi(b);
									int z = stoi(c);
									int w = stoi(d);
									int v = stoi(e);
									int u = stoi(f);

									if (x+y+z+w+v == u){
										tmp.push_back(x);
										tmp.push_back(y);
										tmp.push_back(z);
										tmp.push_back(w);
										tmp.push_back(v);
										tmp.push_back(u);
										ans.push_back(tmp);
									}
								}
							}
						}
					}
				}

				get_ans(mtx, ans, 5);
		}
	}	

	return 0;
}