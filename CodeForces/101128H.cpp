#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast,unroll-loops")
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

const int MAXB = 63;

int main() {
    FAST_IO;

    ll a,b; cin >> a >> b;
    int rta = 0;
    set<ll> passed;
    forsn(i,1,MAXB) forsn(j,1,MAXB) {
        forn(meOp,2) {
            int st = 0; ll act = 0;
            bool op = meOp;
            while (st+(op ? j : i) <= MAXB) {
                if (!op) act |= (((1LL<<(op ? j : i))-1)<<st); // si !op, es porque suma bits 1s
                st += (op ? j : i); // el shifteo lo hago igual
                if (act >= a && act <= b && !passed.count(act)) rta++;
                passed.insert(act);
                op = !op;
            }
        }
    }
    cout << rta;

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
