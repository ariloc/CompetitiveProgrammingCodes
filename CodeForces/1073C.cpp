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
const int typ[] = {20,3,17,11}; // U,D,R,L
const int INF = 1e9+5;

int dp[MAXN][4];

bool canFix (int l, int r, int x, int y, ii nd) {
    int cant[4] = {0,0,0,0};
    forn(k,4) cant[k] = dp[r][k]-dp[l][k];

    nd.fst -= cant[2], nd.fst += cant[3];
    nd.snd -= cant[0], nd.snd += cant[1];

    int need = 0;
    need += abs(x-nd.fst), nd.fst = x;
    need += abs(y-nd.snd), nd.snd = y;

    int s = cant[0]+cant[1]+cant[2]+cant[3];
    if (need > s || ((s-need)&1)) return false;
    return true;
}

int main() {
    FAST_IO;

    int n; cin >> n;
    string s; cin >> s;
    int x,y; cin >> x >> y;

    ii nd = {0,0};
    forn(j,s.size())
        switch (s[j]) {
            case 'L' : nd.fst--; break;
            case 'R' : nd.fst++; break;
            case 'U' : nd.snd++; break;
            case 'D' : nd.snd--; break;
        }

    forn(i,n) forn(k,4) dp[i+1][k] = dp[i][k] + (s[i]-'A' == typ[k]);

    int r = 0;
    int mini = INF;
    forn(l,n) {
        if (l >= r) r = l;
        while (r < n && !canFix(l,r,x,y,nd)) r++;
        if (canFix(l,r,x,y,nd)) mini = min(mini,r-l);
    }

    if (mini == INF) cout << -1;
    else cout << mini;

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
