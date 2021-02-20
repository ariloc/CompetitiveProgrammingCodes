#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define dbg(x) cerr << #x << " = " << x << endl;
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

const int MAXN = 2e5+5;
const ll INF = 9e18;

pair<int,bool> prob[MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(o,t) {
        int n,T,a,b; cin >> n >> T >> a >> b;

        int ez = 0, hd = 0;
        forn(i,n) {
            int x; cin >> x;
            prob[i].snd = x;
            if (prob[i].snd) hd++; else ez++;
        }
        forn(i,n) cin >> prob[i].fst;
        prob[n++] = {T+1,1}; // dummy

        sort(prob,prob+n);

        int maxi = 0; ll acc = 0;
        forn(i,n) { // probemos que nos vamos justo antes que sea obligatorio el nuevo, y resolvamos todo lo que podamos
            if (acc <= prob[i].fst-1) { // si llego a resolver todo lo obligatorio para este punto
                int rest = (prob[i].fst-1-acc), rta = i; // los i resueltos seguro
                int ezS = min(rest/a,ez);
                rest -= ezS*a, rta += ezS;
                int hdS = min(rest/b,hd);
                rta += hdS;

                maxi = max(maxi,rta);
            }
            acc += (prob[i].snd ? b : a);
            ez -= (!prob[i].snd), hd -= prob[i].snd;
        }

        cout << maxi << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
