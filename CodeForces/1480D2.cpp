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

const int MAXN = 1e5+5;
const int INF = 1e9+5;

int arr[MAXN],a[MAXN],b[MAXN],idx[MAXN],ind1 = 0, ind2 = 0;
vi pos[MAXN];

int main() {
    FAST_IO;

    int n; cin >> n;
    forn(i,n) cin >> arr[i];
    forn(i,n) pos[arr[i]].pb(i);
    forn(i,n+1) pos[i].pb(INF), pos[i].pb(INF); // dummys

    int topA = 0, topB = 0;
    forn(i,n) {
        if (arr[i] == topA) a[ind1++] = topA = arr[i];
        else if (arr[i] == topB) b[ind2++] = topB = arr[i];
        else {
            if (pos[topA][idx[topA]] > pos[topB][idx[topB]]) a[ind1++] = topA = arr[i];
            else b[ind2++] = topB = arr[i];
        }
        idx[arr[i]]++;
    }

    int seg = (ind1 > 0) + (ind2 > 0);
    forsn(i,1,ind1) seg += (a[i] != a[i-1]);
    forsn(i,1,ind2) seg += (b[i] != b[i-1]);

    cout << seg;

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
