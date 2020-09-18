
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

const int top = 40;

vector<ll> num;

int main() {
    FAST_IO;

    ll a = 1;
    forn(i,top) {
        ll b = 1;
        if (log10(a)+1 >= 16) continue;
        forn(j,top) {
            ll c = 1;
            if (log10(b)+1 >= 16) continue;
            forn(k,top) {
                if (log10(c)+1 >= 16) continue;

                if (log10(a)+log10(b)+log10(c)+3 >= 16) continue;
                ll v = a*b*c;
                num.pb(v);

                c*=5;
            }
            b*=3;
        }
        a*=2;
    }

    sort(all(num));
    cout << "The 1500'th ugly number is " << num[1499] << ".\n";

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
sss
