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

int const MAXN = 105;
int const MAXM = 210;

ii edges[MAXM];
int n,m;
int deg[MAXN];

vector<int> inout(vector<int> &t, vector<int> &e) {
    int op = (int)t.size();
    n = 2; m = 1;
    edges[1] = {1,2};
    forn(i,op) {
        ii cur = edges[e[i]];
        if (t[i] == 1) {
            edges[e[i]] = {++n,cur.snd};
            edges[++m] = {cur.fst,n};
        }
        else {
            edges[++m] = {cur.fst,++n};
            edges[++m] = {n,cur.snd};
        }
    }
    forn(i,m) deg[edges[i+1].fst]++, deg[edges[i+1].snd]--;
    vi ret;
    forn(i,n) ret.pb(deg[i+1]);
    return ret;
}
