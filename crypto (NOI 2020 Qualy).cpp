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

const int MAXN = 3e5+5;
const int MOD = 1e9+7;

int FT[MAXN];

int getFT (int p) {
    int r = 0;
    for (int i = p; i; i -= i & -i)
        r += FT[i];
    return r;
}

void setFT (int p, int v) {
    for (int i = p; i < MAXN; i += i & -i)
        FT[i] += v;
}

int arr[MAXN];
ii arr2[MAXN];

int main() {
    FAST_IO;

    int n; cin >> n;
    forn (i,n) {cin >> arr[i]; arr2[i] = {arr[i],i};}
    sort(arr2,arr2+n);

    int id = 1;
    arr[arr2[0].snd] = id;
    forsn(i,1,n) {
        if (arr2[i].fst != arr2[i-1].fst) id++;
        arr[arr2[i].snd] = id;
    }

    ll rta = 1,fact = 1,cnt = 1;
    dforn(i,n) {
        rta = (rta+getFT(arr[i])*fact)%MOD;
        fact = (cnt*fact)%MOD; cnt++;
        setFT(arr[i],1);
    }

    cout << rta << '\n';

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
