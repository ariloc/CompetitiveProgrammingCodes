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

int main() {
    FAST_IO;

    int t; cin >> t;

    forn (i,t) {
        ll r,g,b,w; cin >> r >> g >> b >> w;
        ll v = min({r,g,b});

        int cnt = 0;
        if (r & 1) cnt++; if (g & 1) cnt++; if (b & 1) cnt++; if (w & 1) cnt++;
        if (cnt <= 1) {cout << "Yes\n"; continue;}

        cnt = 0;
        if (v) {v = 1; w += 3;}
        r -= v; g -= v; b -= v;
        if (r & 1) cnt++; if (g & 1) cnt++; if (b & 1) cnt++; if (w & 1) cnt++;
        if (cnt <= 1) {cout << "Yes\n"; continue;}
        cout << "No\n";
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!