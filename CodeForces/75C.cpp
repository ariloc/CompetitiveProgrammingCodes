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

vi getDiv (int x) {
    vi r;
    for (ll i = 1; i*i <= x; i++)
        if (!(x%i)) {r.pb(i); r.pb(x/i);}
    return r;
}

int main() {
    FAST_IO;

    int a,b; cin >> a >> b;
    vi divA  = getDiv(a), divB = getDiv(b);
    sort(all(divA)); sort(all(divB));
    vi commonDiv;

    int j = 0;
    forn(i,divA.size()) {
        while (j < (int)divB.size() && divB[j] < divA[i]) j++;
        if (j < (int)divB.size() && divB[j] == divA[i]) commonDiv.pb(divA[i]);
    }

    int q; cin >> q;
    forn(i,q) {
        int l,r; cin >> l >> r;
        int ind = upper_bound(all(commonDiv),r)-commonDiv.begin()-1;
        if (ind >= 0 && commonDiv[ind] >= l) cout << commonDiv[ind] << '\n';
        else cout << "-1\n";
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
