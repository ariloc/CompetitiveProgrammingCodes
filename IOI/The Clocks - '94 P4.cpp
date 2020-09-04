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

const int MAXN = 3e5+5;
const int MAXR = 9;
const int LSTATE = 262143;
const int POSIB[] = {27,7,54,73,186,292,216,448,432}; // posibles decimales

bool done[MAXN];
ii P[MAXN];

int main() {
    FAST_IO;

    int cnt = 0,mk = 0;
    forn(i,3) forn(j,3) {
        int x; cin >> x; x /= 3; x--;
        mk |= (x<<cnt);
        cnt+=2;
    }

    queue<int> Q;
    Q.push(mk); done[mk] = true; P[mk] = {-1,-1};

    while (not Q.empty()) {
        auto e = Q.front(); Q.pop();

        //assert(e != LSTATE);
        if (e == LSTATE) break;

        forn(i,MAXR) {
            int pos = 0, me = POSIB[i], prox = e;
            while (me) {
                if (me & 1) { // si el movimiento me lo permite
                    int aux = 0;
                    aux |= ((prox & (1<<pos)) > 0);
                    aux |= (((prox & (1<<(pos+1))) > 0)<<1); // obtengo num
                    prox &= ~(1<<pos); // vacío bits
                    prox &= ~(1<<(pos+1));
                    prox |= (((aux+1)%4)<<pos); // establezco nuevo
                }
                me >>= 1; pos += 2;
            }
            if (done[prox]) continue;
            done[prox] = true;
            P[prox] = {e,i};
            Q.push(prox);
        }
    }

    vi path;
    for (ii i = P[LSTATE]; i.fst != -1 and i.snd != -1; i = P[i.fst]) {
        //cerr << i.fst << "OK";
        path.pb(i.snd+1);
    }

    dforn (i,path.size()) cout << path[i] << ' ';

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
