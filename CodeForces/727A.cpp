#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")

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

bool dfs (ll a, int b, vi &path) {
    path.pb(a);
    if (a > b) {path.pop_back(); return 0;}
    if (a == b) return 1;

    if (!dfs(2*a,b,path) && !dfs(10*a+1,b,path)) {path.pop_back(); return 0;}
    return 1;
}

int main() {
    FAST_IO;

    int a,b; cin >> a >> b;
    vi path;
    dfs(a,b,path);

    if (path.empty()) cout << "NO";
    else {
        cout << "YES\n" << path.size() << '\n';
        for (auto &i : path) cout << i << ' ';
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
