#include <bits/stdc++.h>

#define forn(i,n) for(int i=0;i<int(n);i++)

using namespace std;
typedef pair<int, char> ic;

map<char, int> pri;
ic p[3];
int r = 0;

void lineal (int n, int pos, string &baldosas) {
    for (int i = pos; i < pos+n; i++) {
        forn (j,3) {
            if ((i-1 >= 0 ? baldosas[i-1] != p[j].second : true) and (i+1 < baldosas.size() ? baldosas[i+1] != p[j].second : true)) {
                baldosas[i] = p[j].second;
                r+=p[j].first;
                break;
            }
        }
    }
}

void simetrico (int n, int pos, string &baldosas) {
    int st;
    if (pri[baldosas[pos-1]] > pri[baldosas[pos+n]]) {
        for (int i = pos+n-1; i > pos-1; i--) {
            forn (j,3) {
                if ((i-1 >= 0 ? baldosas[i-1] != p[j].second : true) and (i+1 < baldosas.size() ? baldosas[i+1] != p[j].second : true)) {
                    baldosas[i] = p[j].second;
                    r+=p[j].first;
                    break;
                }
            }
        }
    }
    else {
        for (int i = pos; i < pos+n; i++) {
            forn (j,3) {
                if ((i-1 >= 0 ? baldosas[i-1] != p[j].second : true) and (i+1 < baldosas.size() ? baldosas[i+1] != p[j].second : true)) {
                    baldosas[i] = p[j].second;
                    r+=p[j].first;
                    break;
                }
            }
        }
    }
}

int sendero(int B, int G, int N, string &baldosas)
{
    p[0] = {B,'B'};
    p[1] = {G,'G'};
    p[2] = {N,'N'};
    int cnt = 0;
    bool bl = false;
    sort(p,p+3);
    forn (i,3) {
        pri[p[i].second] = p[i].first;
    }
    forn (i, baldosas.size()+1) {
        char b = baldosas[i];
        if (b == 'R' and i != baldosas.size()) {
            bl = true;
            cnt++;
        }
        else if (bl) {
            if (cnt%2) {
                pair <char,char> desc = {b,baldosas[i-cnt-1]};
                if (pri[desc.first] - pri[desc.second] == 1 or cnt == 1 or baldosas[i-cnt-1] == baldosas[i]) {
                    lineal(cnt, i-cnt, baldosas);
                }
                else simetrico(cnt, i-cnt, baldosas);

            }
            else {
                lineal(cnt, i-cnt, baldosas);
            }
            cnt = 0;
            bl = false;
        }
    }
    return r;
}
