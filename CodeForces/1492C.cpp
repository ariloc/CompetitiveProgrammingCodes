#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define dbg(x) cerr << #x << " = " << x << endl;
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

const int MAXN = 2e5+5;
const int MAXA = 26;
const int INF = 1e9+5;

int dpL[MAXN], dpR[MAXN]; // últ indice (exclusivo) que pude reconstruir hasta acá
ii posic[MAXN];

int main() {
    FAST_IO;

    forn(i,MAXN) posic[i] = {INF,-INF};

    int n,m; cin >> n >> m;
    string s,t; cin >> s >> t;

    int idx = -1;
    forn(i,n) {
        if (idx+1 < m && s[i] == t[idx+1]) idx++;
        dpL[i] = idx;
    }
    idx = m;
    dforn(i,n) {
        if (idx-1 >= 0 && s[i] == t[idx-1]) idx--;
        dpR[i] = idx;
    }

    forn(i,n) if (dpL[i] >= 0 && s[i] == t[dpL[i]]) posic[dpL[i]].fst = min(posic[dpL[i]].fst,i);
    dforn(i,n) if (dpR[i] < n && s[i] == t[dpR[i]]) posic[dpR[i]].snd = max(posic[dpR[i]].snd,i);

    int maxi = 0;
    forn(i,m-1) maxi = max(maxi,posic[i+1].snd-posic[i].fst);

    cout << maxi;

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
