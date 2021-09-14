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

const int MAXN = 5e5+5;

int arr[MAXN];
int nxt[MAXN], prv[MAXN];

int main() {
    FAST_IO;

    int n; cin >> n;

    priority_queue<ii,vector<ii>,greater<ii>> Q;
    forn(i,n) {
        nxt[i] = i+1;
        prv[i] = i-1;
        cin >> arr[i];
        Q.push({arr[i],i});
    }

    ll r = 0;

    vi toSkip;

    while (Q.size() > 2) { // cuando me quedaron dos extremos que les derivé todo, no puedo sacar más, y corto
        auto e = Q.top(); Q.pop();
        if (prv[e.snd] == -1 || nxt[e.snd] == n) r += arr[e.snd]; // quiera o no, este mínimo me va a contar -> me sumo y supongo que eliminé el que está a mi lado (cambio el orden pensando que se hace al revés)
        else r += min(arr[prv[e.snd]],arr[nxt[e.snd]]); // sacar el más chico de lo contrario es óptimo porque subo el mínimo número peor caso que puedo sacar en operaciones posteriores

        if (prv[e.snd] > -1) nxt[prv[e.snd]] = nxt[e.snd]; // me voy manteniendo el array en el orden con las eliminaciones
        if (nxt[e.snd] < n) prv[nxt[e.snd]] = prv[e.snd];
    }

    cout << r;

    return 0;
}