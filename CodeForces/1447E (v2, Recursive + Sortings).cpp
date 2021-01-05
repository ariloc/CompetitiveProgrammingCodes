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

const int MAXN = 2e5+2;
const int INF = 1e9+5;

int arr[MAXN];

int solve (int l, int r, int lvl) {
    if (r-l == 1) return 1;
    int mid = -1;
    dforsn(j,l,r) if (!(arr[j]&(1<<lvl))) {mid = j+1; break;}
    if (mid == -1 || mid == r) return solve(l,r,lvl-1);
    return max(solve(l,mid,lvl-1),solve(mid,r,lvl-1)) + 1;
}

int main() {
    FAST_IO;

    int n; cin >> n;
    forn(j,n) cin >> arr[j];
    sort(arr,arr+n);

    cout << n-solve(0,n,29);

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
