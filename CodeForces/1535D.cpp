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

const int MAXK = 19;
const int MAXN = 1<<MAXK;

struct nodo {
    int v;
    char c;

    void sum(nodo &a, nodo &b) {
        v = c == '?' ? a.v+b.v : c != '0' ? a.v : b.v;
    }
};

nodo ST[2*MAXN];
int N;

void update (int p, char c) {
    p = N-p;
    ST[p].c = c;

    while (p >= 1) {
        ST[p].sum(ST[2*p],ST[2*p+1]);
        p /= 2;
    }
}
 
int main() {
    FAST_IO;

    int k; cin >> k;
    string s; cin >> s;
    N = 1<<k;

    reverse(all(s));

    forn(i,s.size()) ST[i+1].c = s[i];
    forn(i,N) ST[i+N].v = 1;
    dforsn(i,1,N) ST[i].sum(ST[2*i],ST[2*i+1]);

    int q; cin >> q;
    forn(i,q) {
        int v; char c; cin >> v >> c;
        update(v,c);
        cout << ST[1].v << '\n';
    }
 
    return 0;
}
 
/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!