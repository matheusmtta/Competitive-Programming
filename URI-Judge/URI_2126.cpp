#include <bits/stdc++.h>

using namespace std;

int main(){
    string sbstr, str;
    int i, j, cnt = 0, cnt2, k, l;
    while(cin >> sbstr >> str){
        int sum = 0, pos, init;
        for(i=0, cnt++; i <= str.length()-sbstr.length(); i++){
            if(str[i] == sbstr[0]){
                cnt2 = 1; init = i + 1;
                for(k = i+1, l = 1; sbstr[l]; l++, k++){
                    if(str[k] == sbstr[l]) cnt2++;
                    else break;
                }
                if(cnt2 == sbstr.length()){
                    sum++;
                    pos = init;
                }
            }
        }
        printf("Caso #%d:\n", cnt);
        if(sum == 0) printf("Nao existe subsequencia\n\n");
        else{
            printf("Qtd.Subsequencias: %d\n", sum);
            printf("Pos: %d\n\n", pos);
        }
    }
    return 0;
}
