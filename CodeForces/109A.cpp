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

const int INF = 1e9+5;

int main() {
    FAST_IO;

    int n; cin >> n;

    int div = n/4;
    int cantA = 0, cantB = 0, tot = INF;
    while (true) {
        int c = div*4, rest = n-c;
        if (!(rest%7)) if (rest/7+div < tot) {cantA = div; cantB = rest/7; tot = cantA+cantB;}
        if (!div) break;
        div--;
    }

    if (tot != INF) cout << string(cantA,'4')+string(cantB,'7');
    else cout << -1;

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!