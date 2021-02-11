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

const int MAXN = 2e5+2;

ll arr[MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(i,t) {
        int n; cin >> n;
        forn(j,2*n) cin >> arr[j];

        sort(arr,arr+n+n);

        bool base = true;
        for (int j = 0; j < 2*n; j += 2) if (arr[j] != arr[j+1]) {base = false; break;}
        if (!base) {cout << "NO\n"; continue;}

        for (int j = 0; j < 2*n; j += 2) arr[j/2] = arr[j]; // los unifico

        ll toRest = 0;
        bool posib = true;
        set<ll> lst;
        dforn(j,n) {
            ll me = arr[j]-toRest;

            if ((me%(((ll)j+1)*2LL)) || me <= 0) {posib = false; break;}

            me /= (((ll)j+1)*2LL);

            if (me <= 0 || lst.count(me)) {posib = false; break;}
            lst.insert(me);

            toRest += me*2LL;
        }

        cout << (posib ? "YES" : "NO") << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
