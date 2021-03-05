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

int boxes[MAXN], spec[MAXN], dp[MAXN];

int proc (int n, int m) {
    forn(i,n+2) dp[i] = 0; // reset

    dforn(i,n) {
        int ind = lower_bound(spec,spec+m,boxes[i])-spec;
        if (ind < m && spec[ind] == boxes[i]) dp[i]++;
        if (i+1 < n) dp[i] += dp[i+1];
    }

    int r = dp[0];
    forn(i,m) {
        int ind = upper_bound(boxes,boxes+n,spec[i])-boxes;
        if (!ind) continue;
        int indSpec = lower_bound(spec,spec+m,spec[i]-ind+1)-spec;
        int cntSpec = i-indSpec+1;
        r = max(r,cntSpec+dp[ind]);
    }

    return r;
}

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(o,t) {
        int n,m; cin >> n >> m;
        forn(i,n) cin >> boxes[i];
        forn(i,m) cin >> spec[i];

        int indn = n, indm = m;
        forn(i,n) if (boxes[i] > 0) {indn = i; break;}
        forn(i,m) if (spec[i] > 0) {indm = i; break;}

        reverse(boxes,boxes+indn);
        reverse(spec,spec+indm);

        forn(i,indn) boxes[i] *= -1;
        forn(i,indm) spec[i] *= -1;

        int rta = 0;
        rta += proc(indn,indm);
        int idx1 = 0, idx2 = 0;
        forsn(i,indn,n) boxes[idx1++] = boxes[i];
        forsn(i,indm,m) spec[idx2++] = spec[i];
        rta += proc(idx1,idx2);

        cout << rta << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
