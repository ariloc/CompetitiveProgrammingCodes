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

int main() {
    FAST_IO;

    int t; cin >> t;
    forn (i,t) {
        ll p,f; cin >> p >> f;
        ll cntS,cntW; cin >> cntS >> cntW;
        ll s,w; cin >> s >> w;

        if (s > w) {swap(s,w); swap(cntS,cntW);}

        ll maxi = 0;
        forn(s1,min(cntS,p/s)+1) {
            if ((s1*s) > p) break; // me voy cuando ya no puedo más
            ll w1 = min(cntW,(p-(s1*s))/w);
            ll s2 = min(cntS-s1,f/s);
            ll w2 = min(cntW-w1,(f-(s2*s))/w);

            maxi = max(maxi,s1+w1+s2+w2);
        }

        cout << maxi << '\n';
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
