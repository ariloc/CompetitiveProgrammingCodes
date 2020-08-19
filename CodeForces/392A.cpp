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

    ll n; cin >> n;
    if (!n) {cout << 1; return 0;}

    ll cnt = 0;
    ll x = n, y = 0;
    while (x >= 0 and y <= n) {
        //cerr << x << ' ' << y << endl;
        if ( ( (y+1)*(y+1) + (x*x) ) <= (n*n) ) y++;
        else if ( ( (y+1)*(y+1) + (x-1)*(x-1) ) <= (n*n) ) {y++; x--;}
        else x--;
        cnt++;
    }

    cout << cnt*4-4;

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!