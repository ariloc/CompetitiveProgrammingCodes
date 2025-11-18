#include<bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;

ll const MAXT = 1e12;

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(_,t) {
        ll x,y,k; cin >> x >> y >> k;

        if (k < y) {
            cout << k << '\n';
            continue;
        }

        if (k == 1) {
            cout << "-1\n";
            continue;
        }

        if (y == 1) {
            cout << "-1\n";
            continue;
        }

        while (x > 0 && k <= MAXT) {
            // acá YA ELIMINÉ los anteriores, entonces me imagino los que antes estaban, cada y-1 de los que tengo antes que el k ahora
            ll div = (k-1)/(y-1);  
            ll rest = (y-1) - (k-1)%(y-1) - 1;
            ll turns = min(x,rest/div+1);
            x -= turns;
            k += turns * div;
        }

        cout << (k <= MAXT ? k : -1) << '\n';
    }
}
