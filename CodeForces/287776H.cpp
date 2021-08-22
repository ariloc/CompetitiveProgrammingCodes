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

map<ll,ll> F;
void fact(ll n) {
    F.clear();
    for (ll i = 2; i*i <= n; i++)
        while (!(n%i)) {F[i]++; n/=i;}
    if (n > 1) F[n]++;
}

int main() {
    FAST_IO;

    ll n; cin >> n;
    fact(n);

    bool posib = false;
    ll multDos = 0;
    for (auto &i : F) if (!(i.snd & 1)) multDos++;

    if ((multDos == (ll)F.size() or multDos+1 == (ll)F.size()) and (F.size() >= 2)) posib = true;
    if (F.size() == 1) posib = true;

    cout << (posib ? "YES" : "NO");

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!