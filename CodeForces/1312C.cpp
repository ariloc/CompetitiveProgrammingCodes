#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

const ll MAXN = 100;

int mark[MAXN];

int main() {
    FAST_IO;

    int t;
    cin >> t;

    forn(i,t) {
        int n,k; bool posib = true;
        cin >> n >> k;
        // representemos la secuencia de potencias necesarias como bitmask
        memset(mark,0,sizeof(mark));
        forn (j,n) {
            ll x, ind = 0; cin >> x;
            while (x)
                {mark[ind++] += (x % k); x /= k;} // floor en cada división -> módulo representa potencias para llegar
        }

        forn(j,MAXN) if (mark[j] > 1) posib = false; // si usé algún paso más de una vez, no es posible
        if (posib) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}