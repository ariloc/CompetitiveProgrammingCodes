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

const int MAXN = 500;

int a[MAXN], b[MAXN], dp[MAXN];
vector< pair< char, int > > mov;

bool solve (int l, int r, int shift) {
    vi monst;
    forsn(i,l,r+1) monst.pb(a[i]);

    vi posibMax; int maxi = -1;
    while ((int)monst.size() > 1) {
        int actN = (int)monst.size();
        posibMax.clear();
        maxi = -1;

        forn(i,monst.size()) {
            if (monst[i] > maxi)
                posibMax.clear(), maxi = monst[i];
            if (monst[i] == maxi) posibMax.pb(i);
        }

        for (auto &i : posibMax) {
            bool okL = false, okR = false;
            if (i && monst[i-1] < monst[i]) okL = true;
            if (i+1 < (int)monst.size() && monst[i+1] < monst[i]) okR = true;

            //cerr << monst[i] << ' ' << monst[i+1] << ' ' << l << ' ' << i << endl;

            if (okL) {
                monst[i] += monst[i-1];
                monst.erase(monst.begin()+i-1);
                mov.pb({'L',shift+i});
            }
            else if (okR) {
                monst[i] += monst[i+1];
                monst.erase(monst.begin()+i+1);
                mov.pb({'R',shift+i});
            }
            if (okL || okR) break;
        }
        if (actN == (int)monst.size()) return false; // si no puedo moverme más
    }
    return true;
}

int main() {
    FAST_IO;

    int n; cin >> n;
    forn(i,n) cin >> a[i+1];
    forsn(i,1,n+1) dp[i] = a[i];
    forsn(i,1,n+1) dp[i] += dp[i-1];

    int m; cin >> m;
    forn(i,m) cin >> b[i];

    int l = 1, ind = 0;
    forsn(i,1,n+1) {
        if ((dp[i] - dp[l-1]) > b[ind]) return cout << "NO", 0;
        if ((dp[i] - dp[l-1]) == b[ind]) {
            if (!solve(l,i,ind+1)) return cout << "NO", 0;
            l = i+1; ind++;
        }
    }

    if (ind != m) cout << "NO";
    else {
        cout << "YES\n";
        for (auto &i : mov) cout << i.snd << ' ' << i.fst << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!