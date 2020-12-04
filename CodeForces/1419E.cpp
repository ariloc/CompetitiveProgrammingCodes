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

vi rta;
vector<ii> FF;

void solve(int i, int ap, int mult) {
    rta.pb(mult); //cerr <<i << ' ' << ap << ' ' << mult << endl;
    if (ap+1 < FF[i].snd) solve(i,ap+1,mult*FF[i].fst);
    dforsn(j,i+1,FF.size()) solve(j,0,mult*FF[j].fst); // para atrás así el último que queda conecta con el siguiente
}


int main() {
    FAST_IO;

    int t; cin >> t;
    forn(i,t) {
        int n; cin >> n;

        FF.clear(); rta.clear();
        map<int,int> F;
        for (int j = 2; j*j <= n; j++)
            while (!(n%j)) {F[j]++; n /= j;}
        if (n > 1) F[n]++;

        int sDiv = 0;
        for (auto &j : F) {FF.pb({j.fst,j.snd}); sDiv += j.snd;}
        forn(j,FF.size()) solve(j,0,FF[j].fst);
        if (FF.size() > 1) rta.pb(FF[0].fst*FF.back().fst);
        forn(j,rta.size()-1) if (rta[j] == rta.back()) {rta.erase(rta.begin()+j); break;}
        for (auto &j : rta) cout << j << ' '; cout << '\n';
        cout << 0+(sDiv == 2 && (int)FF.size() == 2) << '\n';
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
