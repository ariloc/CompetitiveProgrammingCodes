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

int arr[MAXN];
ll dpR[MAXN],dpL[MAXN];
map<int,int> histo;
int ord[MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(o,t) {
        int n; cin >> n;

        histo.clear(); // reset
        forn(i,n+2) dpL[i] = dpR[i] = 0;

        forn(i,n) cin >> arr[i];
        forn(i,n) histo[arr[i]]++;

        int idx = 0;
        for (auto &i : histo) ord[idx++] = i.snd;

        sort(ord,ord+idx);

        dforn(i,idx-1)
            dpR[i] += dpR[i+1]+(ord[i+1]-ord[i])*(idx-i-1); // tengo antes la cantidad para hacer todos iguales al anterior, ahora le sumo a este (dif por cant derecha)

        forsn(i,1,idx) dpL[i] += dpL[i-1]+ord[i-1]; // acá todos tiran a 0, así que directamente sumo lo que descartaré

        ll mini = INF;
        forn(i,idx) mini = min(mini,dpL[i]+dpR[i]);

        cout << mini << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
