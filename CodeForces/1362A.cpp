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
        ll a,b,rta = 0,cnt = 0; cin >> a >> b;
        bool posib = true;
        if (b < a) {
            while (a != b and a) {
                if (a & 1) {posib = false; break;}
                a >>= 1;
                cnt++;
            }
        }
        else {
            while (a != b) {
                if (b & 1) {posib = false; break;}
                b >>= 1;
                cnt++;
            }
        }
        rta += cnt/3;
        cnt %= 3; rta += cnt/2;
        cnt %= 2; rta += cnt;
        if (!posib) cout << "-1\n";
        else cout << rta << '\n';
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!