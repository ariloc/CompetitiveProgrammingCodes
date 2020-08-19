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

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    priority_queue<ii> Q;
    int n,k; cin >> n >> k;
    int honey = 0;
    forn (i,n) {
        int x; cin >> x;
        Q.push({x,0});
    }

    while (not Q.empty()) {
        auto e = Q.top(); Q.pop();
        if (e.fst < k or e.snd >= 3) {honey += e.fst; continue;}
        Q.push({e.fst-k,e.snd+1});
    }

    cout << honey;

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!