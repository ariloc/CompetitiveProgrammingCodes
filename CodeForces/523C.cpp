#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

const int MAXN = 1e5+2;


int main() {
    FAST_IO;

    string a,b; cin >> a >> b;

    int dpL = -1, dpR = -1, ind = 0;
    forn (i,b.size()) {
        if (b[i] == a[ind]) ind++;
        if (ind >= (int)a.size()) {dpL = i; break;}
    }

    ind = a.size()-1;
    dforn (i,b.size()) {
        if (b[i] == a[ind]) ind--;
        if (ind < 0) {dpR = i; break;}
    }

    cout << (dpR < dpL or dpL == -1 or dpR == -1 ? 0 : dpR-dpL);

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!