#include <bits/stdc++.h>
 
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
 
const int MAXN = 2e5+5;
 
int arr[MAXN],LIS[MAXN],lis = 0; ii refer[MAXN]; ll FT[MAXN];
bitset<MAXN> done;
 
void setFT (int p, int v) {
    for (int i = p; i < MAXN; i += i & -i)
        FT[i] += v;
}
 
ll getFT (int p) {
    ll r = 0;
    for (int i = p; i; i -= i & -i)
        r += FT[i];
    return r;
}
 
int dfs(int st) {
    done[st] = true;
 
    if (!done[refer[st].snd]) return dfs(refer[st].snd)+1;
    return 0;
}
 
int main() {
    FAST_IO;
 
    int n; cin >> n;
    forn (i,n) {cin >> arr[i]; refer[i].fst = arr[i]; refer[i].snd = i;}
 
    sort(refer,refer+n);
 
    ll a,b,c,d; a = b = c = d = 0;
 
    // SWAP SORT
    dforn (i,n) { // cuento inversiones
        if (arr[i] > 1) a += getFT(arr[i]-1);
        setFT(arr[i],1);
    }
 
    // CYCLE SORT
    forn (i,n) if (!done[i]) b += dfs(i); // resuelvo los ciclos
 
    // (?) SORT --> LIS
    forn (i,n) {
        auto ind = lower_bound(LIS,LIS+lis,arr[i]) - LIS;
        LIS[ind] = arr[i];
        if (ind+1 > lis) lis = ind+1;
    }
    c = n-lis;
 
    // FRONT(?) SORT
    d = n;
    dforn (i,n) if (arr[i] == d) d--;
    /* todos los menores al �ltimo que est�n atr�s los muevo. Cuando llego, lo mismo con el anterior
       a ese y as� continuamente. La cantidad de movimientos son la cant de elementos
       menos los que encontr� en buen orden */
 
    cout << a << ' ' << b << ' ' << c << ' ' << d;
 
    return 0;
}
 
/// ESCRIB� en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO B�SICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!