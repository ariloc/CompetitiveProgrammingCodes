#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)

using namespace std;
typedef vector<int> vi;

map<int,int> typ;
vi hem,mach;
int M,H;

bool valido(int &i) {
    if (i < min(M,H)) return true;
    else return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("zoo.in","r",stdin);
    freopen("zoo.out","w",stdout);

    int E;
    int kill=0,same=0,maxSeq=0;
    cin >> E >> M >> H;
    forn (i,E) {
        int a,b;
        cin >> a >> b;
        typ[a] = b;
    }
    forn (i,M) {
        int x;
        cin >> x;
        mach.push_back(x);
    }
    forn (i,H) {
        int x;
        cin >> x;
        hem.push_back(x);
    }
    int superv = 0;
    for (int i = 0;valido(i);i++) {
        int &m = mach[i], &h = hem[i];
        if (m == h) same++;
        if (abs(typ[m]-typ[h]) >= 4) {
            if (superv > maxSeq) maxSeq = superv;
            superv = 0;
            kill++;
        }
        else superv++;
    }
    if (superv > maxSeq) maxSeq = superv;
    cout << same << ' ' << kill << ' ' << maxSeq;
    return 0;
}
