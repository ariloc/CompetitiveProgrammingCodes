#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i<int(n);i++)

using namespace std;

string comp,decomp;
string lin1, lin2;

void DECOMP() {
    bool action = false;
    char letra;
    string num;
    int NUM;

    for (auto i : decomp) {
        if (i == '(') {
            action = true;
            continue;
        }
        if (i == ')') {
            NUM = atoi(num.c_str());
            num = "";
            forn (j,NUM) lin2 += letra;
            action = false;
            continue;
        }
        if (isalpha(i)) {
            if (action) letra = i;
            else lin2+=i;
        }
        if (isdigit(i) and action) {
            num+=i;
        }
    }
}

void COMP() {
    char prev = comp[0];
    int cnt=0;

    for (int i = 1; i < comp.size(); i++) {
        char c = comp[i];

        if (prev == c) cnt++;
        if (prev != c or i == comp.size()-1) {
            if (cnt >= 4) {
                stringstream num;
                string NUM;
                cnt++;
                num << cnt;
                num >> NUM;

                lin1+='(';
                lin1+=prev;
                lin1+=NUM;
                lin1+=')';
                cnt = 0;
            }
            else if (not cnt) lin1+=prev;
            else {
                forn(i,cnt+1) lin1+=prev;
                cnt = 0;
            }
        }
        if (i == comp.size()-1 and prev != c) lin1+=c;
    prev = c;
    }
    if (not lin1.size()) lin1+=comp[0];
}


int main () {
    freopen("imagenes.in","r",stdin);
//    freopen("imagenes.out","w",stdout);

    getline(cin,comp);
    getline(cin,decomp);

    COMP();
    DECOMP();

    cout << lin1 << endl << lin2;
    return 0;
}
