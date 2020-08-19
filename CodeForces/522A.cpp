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

const int MAXN = 205;

map<string,int> usrs;
vi G[MAXN];
int prox_libre = 0;
bitset<MAXN> done;

int dfs (int st) {
    done[st] = true;

    int maxi = 0;
    for (auto &i : G[st])
        if (!done[i]) maxi = max(maxi,dfs(i));

    return maxi+1;
}

int main() {
    FAST_IO;

    int n; cin >> n;

    forn (i,n) {
        string a,discard,b; cin >> b >> discard >> a;
        forn (j,a.size()) a[j] = tolower(a[j]);
        forn (j,b.size()) b[j] = tolower(b[j]);

        if (!usrs.count(a)) usrs[a] = prox_libre++;
        if (!usrs.count(b)) usrs[b] = prox_libre++;
        //cerr << a << ' ' << b << ' ' << usrs[a] << ' ' << usrs[b] << endl;

        G[usrs[a]].pb(usrs[b]);
    }

    cout << dfs(0);

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!