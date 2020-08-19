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

    ll w,m,k; cin >> w >> m >> k;

    ll cnt = 0;
    ll dig = log10(m)+1;
    ll mult = 9;
    while ((log10(mult)+1) < dig) mult *= 10LL;
    //cerr << mult << endl;

    ll restC = (mult-m+(mult/9));
    if ((log10(restC)+log10(dig)+log10(k)+3) <= 18 and
        w >= restC*dig*k) {w -= (restC*dig*k); mult *= 10LL; dig++; cnt += restC;} // si puedo llegar a completar la serie
    else {cout << w/(dig*k); return 0;} // de lo contrario

    while (w >= (mult*k*dig)) {
        w -= (mult*k*dig);
        cnt += mult;
        mult *= 10LL; dig++;
    }

    cnt += w/(k*dig);

    cout << cnt;

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!