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

multiset<int> ticket;

int main() {
    FAST_IO;

    int n,m; cin >> n >> m;
    forn(i,n) {int x; cin >> x; ticket.insert(x);}
    forn(i,m) {
        int x; cin >> x;
        auto it = ticket.upper_bound(x);
        if (it == ticket.begin()) {cout << "-1\n"; continue;} it--;
        if (*it <= x) {cout << *it << '\n'; ticket.erase(it);}
        else cout << "-1\n";
    }

    return 0;
}

/// ESCRIB� en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO B�SICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
