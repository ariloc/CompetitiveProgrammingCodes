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
const ll INF = 9e18;

vi G[MAXN];
int cit[MAXN];
ll maxi = 0;

struct state {
    ll maxi,chi,sum;
};

state dfs (int st) {
    if (G[st].empty()) return {cit[st],1,0};
    state me = {0,0,0};

    vector<state> lst;

    for (auto &i : G[st]) {
        state tmp = dfs(i);
        me.sum += tmp.sum;
        me.chi += tmp.chi;
        me.maxi = max(me.maxi,tmp.maxi);
        lst.pb(tmp);
    }

    for (auto &i : lst) me.sum += i.chi*(me.maxi-i.maxi);
    ll toRest = min(me.sum,(ll)cit[st]);
    cit[st] -= toRest; me.sum -= toRest;

    if (cit[st]) {
        ll toSum = cit[st]/me.chi, rest = (cit[st]%me.chi);
        me.maxi += toSum+(rest > 0);
        if (rest) me.sum += me.chi-rest;
    }

    return me;
}

int main() {
    FAST_IO;

    int n; cin >> n;
    forn(i,n-1) {
        int x; cin >> x; x--;
        G[x].pb(i+1);
    }
    forn(i,n) cin >> cit[i];
    cout << dfs(0).maxi;

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
