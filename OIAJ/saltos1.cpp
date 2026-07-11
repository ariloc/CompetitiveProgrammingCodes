#include<bits/stdc++.h>
#include<cassert>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define sz(c) ((int)c.size())
#define all(c) (c).begin(),(c).end()
#define forall(it,v) for(auto it=v.begin();it!=v.end();++it)
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)
 
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;

int const MAXN = 1005;

int tab[2][MAXN];

int saltos(int f, int c, vector<int> &fila1, vector<int> &fila2) {
    --f, --c;
    int bp = 0, bs = 0;
    int n = (int)fila1.size();

    forn(i,n) tab[0][i] = fila1[i], tab[1][i] = fila2[i];

    int r = tab[f][c];
    tab[f][c] = 0;

    int fil = f, acc = 0;
    for (int i = c; i < n; i += 2, fil = 1-fil) {
        acc += tab[fil][i];
        bs = max(bs,acc);
    }
    acc = 0; fil = f;
    for (int i = c; i >= 0; i -= 2, fil = 1-fil) {
        acc += tab[fil][i];
        bp = max(bp,acc);
    }

    return r + bs + bp;
}
