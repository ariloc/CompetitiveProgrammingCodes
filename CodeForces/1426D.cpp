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

const int INF = 1e9+5;
const int MAXN = 2e5+10;

ll TAd[MAXN];

int main() {
    FAST_IO;

    int n; cin >> n;
    forn(i,n) cin >> TAd[i+1];
    forsn(i,1,n+1) TAd[i] += TAd[i-1];

    set<pair<ll,int>> pref; int ind = 0, cnt = 0;
    forsn(i,1,n+1) {
        ll myPref = TAd[i]-TAd[ind];
        auto it = pref.lower_bound({myPref+1,-INF});
        if (!myPref || (it != pref.begin() && (*prev(it)).fst == myPref))
            {cnt++; pref.clear(); ind = i-1;}
        pref.insert({TAd[i]-TAd[ind],i});
    }

    cout << cnt;

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
