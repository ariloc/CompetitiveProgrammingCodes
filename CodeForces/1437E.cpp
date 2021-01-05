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

const int MAXN = 5e5+2;
const int INF = 2e9+5;

int arr[MAXN],ind[MAXN];
ii LIS[MAXN];

int binSrch (int l, int r, int j) {
    int low = l-1, high = r;
    while (high-low > 1) {
        int mid = (high+low)/2;
        if ((LIS[mid].fst-LIS[mid].snd+j) > arr[j])
            high = mid;
        else low = mid;
    }
    return high;
}

int maxLIS (int l, int r) {
    int lis_nd = 0;
    forsn(i,l+1,r) {
        if (arr[i]-i+l < arr[l] || arr[i]+r-i > arr[r]) continue;
        int pos = binSrch(0,lis_nd,i);
        LIS[pos] = {arr[i],i};
        if (pos+1 > lis_nd) lis_nd = pos+1;
    }
    return r-l-1-lis_nd;
}

int main() {
    FAST_IO;

    int n,k; cin >> n >> k;
    forn(i,n) cin >> arr[i+1];
    forn(i,k) cin >> ind[i];

    arr[0] = -INF; arr[n+1] = INF; // bordes

    forsn(j,1,k)
        if (arr[ind[j]]-arr[ind[j-1]] < ind[j]-ind[j-1]) return cout << -1, 0;

    int s = 0;
    if (!k) s += maxLIS(0,n+1);
    else {
        s += maxLIS(0,ind[0]);
        forsn(j,1,k) s += maxLIS(ind[j-1],ind[j]);
        s += maxLIS(ind[k-1],n+1);
    }

    cout << s;

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
