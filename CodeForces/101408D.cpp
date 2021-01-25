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

const int MOD = 1e4+1;
const int PHI = 9792;

map<ii,int> votes;

int binExp (int a, int k) {
    int r = 1;
    while (k) {
        if (k&1) r = (r*(ll)a)%MOD;
        a = (a*(ll)a)%MOD; k >>= 1;
    }
    return r;
}

int main() {
    FAST_IO;

    int t; cin >> t;
    int prv, st;
    forn(i,t) {
        int x; cin >> x;

        if (i) {
            forn(a,MOD) {
                ll calc = (((x-(ll)a*a*prv)%MOD)+MOD)%MOD;
                if (__gcd(a+1,MOD) != 1) continue; // if they aren't coprime
                ll b = ((ll)calc*binExp(a+1,PHI-1))%MOD;

                votes[{a,b}]++;
            }
        } else st = x;

        prv = x;
    }

    ii choose = {-1,-1};
    for (auto &i : votes) if (i.snd == t-1) {choose = i.fst; break;}

    forn(i,2*t) {
        if (i&1) cout << st << '\n';
        st = (((ll)choose.fst*st) + choose.snd)%MOD;
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
