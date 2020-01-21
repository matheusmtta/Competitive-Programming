#include <bits/stdc++.h>

using namespace std;

struct liv {
    string tt;
    string aut;

    bool operator<(const liv &ot) const {
        if (aut != ot.aut)
            return aut < ot.aut;
        return tt < ot.tt;
    }
};

int main() {
    string str;
    char t[85], a[85];
    vector<liv> books;
    vector<liv> returned;
    map<string,int> position;
    map<int,bool> tk;
    string tt;

    while (getline(cin, str)) {
        if (str == "END") break;

        sscanf(str.c_str(), "\"%[^\"]\" by %[^\n\r]", t, a);
        liv tmp;
        tmp.aut = string(a);
        tmp.tt = string(t);
        books.push_back(tmp);
    }
    
    sort(books.begin(), books.end());

    for (int i = 0; i < books.size(); i++) {
        position[books[i].tt] = i;
        tk[i] = false;
    }

    while (getline(cin, str)) {
        if (str == "END") break;

        if (str[0] == 'S') { // shelve
            sort(returned.begin(), returned.end());

            for (int i = 0; i < returned.size(); i++) {
                int pos = position[returned[i].tt];

                bool found = false;
                int after = pos - 1;

                while (after >= 0) {
                    if (tk[after] == false) {
                        found = true;
                        break;
                    }
                    after--;
                }

                if (found) {
                    cout << "Put \"" << books[pos].tt << "\" after \"" << books[after].tt << "\"" << endl;
                } else {
                    cout << "Put \"" << books[pos].tt << "\" first" << endl;
                }

                tk[pos] = false;
            }

            cout << "END" << endl;

            returned.clear();
        } else if (str[0] == 'B') { // borrow
            sscanf(str.c_str(), "BORROW \"%[^\"]\"", t);
            tt = string(t);
            int pos = position[tt];
            tk[pos] = true;
        } else if (str[0] == 'R') { // return
            sscanf(str.c_str(), "RETURN \"%[^\"]\"", t);
            tt = string(t);
            int pos = position[tt];
            returned.push_back(books[pos]);
        }
    }

    return 0;
}

//solution from https://github.com/ksaveljev/UVa-online-judge/blob/master/230.cpp