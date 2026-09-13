#include<bits/stdc++.h>
#include<cassert>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define sz(c) ((int)c.size())
#define all(c) (c).begin(),(c).end()
#define forall(it,v) for(auto it=v.begin();it!=v.end();++it)
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)
 
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;

int const MAXN = 2e5+5;
int const MAXX = 1e6+5;

vi G[MAXN];
bitset<MAXN> done;
bitset<MAXX> comp;
int spf[MAXX], fac[MAXX];

int dfs(int st) {
    done[st] = true;

    int cnt = 0;
    for (auto &i : G[st])
        if (!done[i]) cnt += dfs(i);

    if (!cnt) return 1;
    return cnt;
}

void criba() {
    comp[0] = comp[1] = true;
    forn(i,MAXX) spf[i] = i;
    for (int i = 4; i < MAXX; i += 2) comp[i] = true, spf[i] = 2;
    for (int i = 3; i*i <= MAXX; i += 2)
        if (!comp[i])
            for (int j = i+i; j < MAXX; j += i)
                if (!comp[j])
                    comp[j] = true, spf[j] = i;
}

void op(int x, bool add) {
    forsn(i,1,x+1) {
        int auxi = i;
        while (auxi > 1) {
            fac[spf[auxi]] += (add ? 1 : -1);
            auxi /= spf[auxi];
        }
    }
}

int electricista(vector<int> tubosA, vector<int> tubosB, int x, int mod) {
    criba();

    int n = sz(tubosA);
    forn(i,n) G[tubosA[i]].pb(tubosB[i]), G[tubosB[i]].pb(tubosA[i]);
    int child = dfs(0);
    if (child > x) return -1;
    x -= child;
    if (!x) return 1;

    n -= child;
    if (n < x) return -1;

    // nCk(n,x)
    op(n,true);
    op(x,false);
    op(n-x,false);

    int rta = 1;
    forn(i,MAXX) 
        forn(j,fac[i]) rta = (rta * (ll)i)%mod;

    return rta;
}

#ifndef EVAL
    #include <iostream>

    int main() {
        int N,X,mod;
        cin >> N >> X >> mod;
        vector<int> tubosA, tubosB;
        tubosA.reserve(N);
        tubosB.reserve(N);
        for (int i=0;i<N;i++) {
            int a,b; cin >> a >> b;
            tubosA.push_back(a);
            tubosB.push_back(b);
        }
        cout << electricista(tubosA, tubosB, X, mod) << endl;
    }
#endif
