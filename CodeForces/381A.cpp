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

const int MAXN = 1005;

deque<int> Q;

int main() {
    FAST_IO;

    int n; cin >> n;
    forn(i,n) {
        int x; cin >> x;
        Q.pb(x);
    }

    bool t = false; int S = 0, D = 0;
    while (not Q.empty()) {
        if (Q.back() > Q.front()) {
            if (!t) S += Q.back();
            else D += Q.back();
            Q.pop_back();
        } else {
            if (!t) S += Q.front();
            else D += Q.front();
            Q.pop_front();
        }
        t = !t;
    }

    cout << S << ' ' << D;

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!