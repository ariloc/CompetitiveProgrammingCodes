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

const int MAXN = 6e6+2;
const int MOD = 998244353;

int binExp (int a, int k) {
    int r = 1;
    while (k) {
        if (k&1) r=(r*(ll)a)%MOD;
        a = (a*(ll)a)%MOD; k >>= 1;
    }
    return r;
}

pair<int,bool> lamps[MAXN];
int fact[MAXN];

int main() {
    FAST_IO;

    fact[0] = 1; // precomp
    forsn(i,1,MAXN) fact[i] = (fact[i-1]*(ll)i)%MOD;

    int n,k; cin >> n >> k;
    forn(i,n) {int l,r; cin >> l >> r; lamps[2*i] = {l,0}; lamps[2*i+1] = {r,1};}

    sort(lamps,lamps+n+n);

    int cnt = 0, cntAct = 0, rta = 0;
    forn(i,2*n) {
        if (lamps[i].snd) {
            if (cnt && cntAct >= k)
                forsn(j,(cntAct-cnt-k < 0 ? abs(cntAct-cnt-k) : 1),min(k,cnt)+1)
                    rta = (rta + (((((ll)fact[cnt]*binExp(((ll)fact[j]*fact[cnt-j])%MOD,MOD-2))%MOD)%MOD) *
                                 (((ll)fact[cntAct-cnt] * binExp(((ll)fact[k-j]*fact[cntAct-cnt-k+j])%MOD,MOD-2))%MOD))%MOD)%MOD;
            cntAct--; cnt = 0;
        } else cnt++, cntAct++;
    }

    cout << rta;

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
