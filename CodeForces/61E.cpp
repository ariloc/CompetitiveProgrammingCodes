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

const int MAXN = 1e6+5;

int FTL[MAXN], FTR[MAXN], arr[MAXN];
ii arr2[MAXN];

void compressStrength(int n) {
    sort(arr2,arr2+n);
    int str = 2; // para no sobrecargar Fenwick
    arr[arr2[0].snd] = str;
    forsn(i,1,n) {
        if (arr2[i].fst != arr2[i-1].fst) str++;
        arr[arr2[i].snd] = str;
    }
}

void setFT (int p, int v, int FT[]) {
    for (int i = p; i < MAXN; i += i & -i)
        FT[i] += v;
}

int getFT (int p, int FT[]) {
    int r = 0;
    for (int i = p; i; i -= i & -i)
        r += FT[i];
    return r;
}

int main() {
    FAST_IO;

    int n; cin >> n;
    forn(i,n) {cin >> arr[i]; arr2[i] = {arr[i],i};}

    compressStrength(n);

    dforn(i,n) setFT(arr[i],1,FTR);

    ll rta = 0;
    forn(i,n) {
        setFT(arr[i],-1,FTR);
        rta += (ll)(getFT(MAXN-1,FTL)-getFT(arr[i],FTL))*getFT(arr[i]-1,FTR);
        setFT(arr[i],1,FTL);
    }

    cout << rta;

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
