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

int const MAXN = 1e5+10;

vi G[MAXN];
bitset<MAXN> done;
int F[MAXN],T[MAXN],L[MAXN];
int tim = 0;

void dfs(int st) {
    done[st] = true;
    F[st] = L[st] = tim;
    T[tim++] = st;

    for (auto &i : G[st])
        if (!done[i]) {
            dfs(i);
            L[st] = tim-1;
        }
}

int FT1[MAXN],FT2[MAXN];

void setFT(int p, int v, int *FT) {
    p += 2;
    for (int i = p; i < MAXN; i += i & -i)
        FT[i] += v;
}

int getFT(int p, int *FT) {
    p += 2;
    int r = 0;
    for (int i = p; i; i -= i & -i)
        r += FT[i];
    return r;
}

int mod[MAXN];

vector<int> hoteles(vector<int>& padre, vector<int>& tipo, vector<int>& nodo) {
    int n = sz(padre);
    forn(i,n) G[i+1].pb(padre[i]), G[padre[i]].pb(i+1);
    dfs(0);

    forn(i,n+1) mod[i] = 1;
    
    vi rta;
    forn(i,sz(tipo)) {
        if (mod[nodo[i]] == tipo[i]) { rta.pb(0); continue; }
        if (!tipo[i]) {
            if (getFT(L[nodo[i]],FT1)-getFT(F[nodo[i]]-1,FT1)) {
                rta.pb(0); continue;
            }
            if (getFT(F[nodo[i]],FT2)) {
                rta.pb(0); continue;
            }
            setFT(F[nodo[i]],1,FT1);
            setFT(F[nodo[i]],1,FT2);
            setFT(L[nodo[i]]+1,-1,FT2);
            mod[nodo[i]] = 0;
            rta.pb(1);
        }
        else {
            rta.pb(1);
            setFT(F[nodo[i]],-1,FT1);
            setFT(F[nodo[i]],-1,FT2);
            setFT(L[nodo[i]]+1,1,FT2);
            mod[nodo[i]] = 1;
        }
    }
    return rta;
}
