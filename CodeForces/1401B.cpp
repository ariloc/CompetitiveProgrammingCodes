
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
    forn(i,t) {
        int x1,y1,z1; cin >> x1 >> y1 >> z1;
        int x2,y2,z2; cin >> x2 >> y2 >> z2;
        ll sum = min(z1,y2);
        z1 -= sum; y2 -= sum; sum *= 2LL;
        int min2 = min(z1,z2); z1 -= min2; z2 -= min2;
        int min3 = min(y1,y2); y1 -= min3; y2 -= min3;
        int min4 = min(y1,x2); y1 -= min4; x2 -= min4;
        int min5 = min(z2,x1); z2 -= min5; x1 -= min5;
        sum -= min(z2,y1)*2LL;
        cout << sum << '\n';
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
