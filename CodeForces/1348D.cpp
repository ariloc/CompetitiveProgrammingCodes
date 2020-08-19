#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define fst first
#define snd second
#define pb push_back
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

const int MAXN = 29;

int potS[MAXN], pot[MAXN];

void gen() {
    potS[0] = 1;
    pot[0] = 1;
    int act = 1;
    forsn (i,1,MAXN) {
        act <<= 1;
        potS[i] = potS[i-1]+act;
        pot[i] = act;
    }
}

int main() {
    FAST_IO;

    gen();

    int t; cin >> t;

    forn (i,t) {
        int x; cin >> x;

        /* me acerco todo lo posible hasta potencias de 2
         2^(x+1)-1 == 2^0+2^1+2^2...2^x
         me fijo hasta donde llego con binary search
         pero pensándolo mejor, conviene hacer eso con un array
         pregenerado, ya que total en mi rango las potencias van hasta 30 */
        auto it = upper_bound(potS,potS+MAXN,x);
        if (it-potS != 0) it--; // el anterior del upper_bound es menor o igual
        int ind = it - potS;
        vi nights;
        forn (j,ind+1) nights.pb(pot[j]);
        if (potS[ind] != x) nights.pb(x-potS[ind]);
        /* como dividiendo puedo llegar acualquier número
         puedo simplemente suponer que para llegar tengo ese
         punto intermedio según corresponda */
        sort(all(nights));

        cout << nights.size()-1 << '\n';
        forsn (j,1,nights.size()) cout << nights[j]-nights[j-1] << ' ';
        cout << '\n';
    }

    return 0;
}