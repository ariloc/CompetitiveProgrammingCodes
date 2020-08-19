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

const int MAXN = 21;

int bits[MAXN];

int main() {
    FAST_IO;

    int N; cin >> N;
    forn (i,N) {
        int x,cnt = 0; cin >> x;
        while (x) {
            if (x & 1) bits[cnt]++;
            x >>= 1; cnt++;
        }
    }

    ll rta = 0;
    while (true) {
        ll me = 0;
        forn (i,MAXN) if (bits[i]) {me |= (1<<i); bits[i]--;}
        if (!me) break;
        rta += me*me;
    }

    cout << rta;

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!