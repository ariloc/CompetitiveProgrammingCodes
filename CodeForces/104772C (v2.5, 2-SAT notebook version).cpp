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

int col[MAXN];
bitset<MAXN> done;
vi percol[MAXN];
int n;

vi G[MAXN];

//We have a vertex representing a var and other for his negation.
//Every edge stored in G2 represents an implication. To add an equation of the form a||b, use addor(a, b)
//MAXN=max cant var, n=cant var
#define addor(a, b) (G2[neg(a)].pb(b), G2[neg(b)].pb(a))
vector<int> G2[MAXN*2];
//idx[i]=index assigned in the dfs
//lw[i]=lowest index(closer from the root) reachable from i
int lw[MAXN*2], idx[MAXN*2], qidx;
stack<int> q;
int qcmp, cmp[MAXN*2];
//verdad[cmp[i]]=valor de la variable i
bool verdad[MAXN*2+1];

int neg(int x) { return x>=n? x-n : x+n;}
void tjn(int v){
	lw[v]=idx[v]=++qidx;
	q.push(v), cmp[v]=-2;
	forall(it, G2[v]){
		if(!idx[*it] || cmp[*it]==-2){
			if(!idx[*it]) tjn(*it);
			lw[v]=min(lw[v], lw[*it]);
		}
	}
	if(lw[v]==idx[v]){
		int x;
		do{x=q.top(); q.pop(); cmp[x]=qcmp;}while(x!=v);
		verdad[qcmp]=(cmp[neg(v)]<0);
		qcmp++;
	}
}
//remember to CLEAR G2!!!
bool satisf(){//O(n)
    qidx = qcmp = 00;
    forn(i,2*n) idx[i] = 0, cmp[i] = -1;
	forn(i, n){
		if(!idx[i]) tjn(i);
		if(!idx[neg(i)]) tjn(neg(i));
	}
	forn(i, n) if(cmp[i]==cmp[neg(i)]) return false;
	return true;
}


void dfs2(int st, int p = -1) {
    done[st] = true;

    if (p != -1) G2[st].pb(p), G2[neg(p)].pb(neg(st));

    for (auto &i : G[st]) 
        if (!done[i])
            dfs2(i,st);
}

vi go(int rt) {
    forn(i,n) done[i] = false;
    forn(i,2*n) G2[i].clear();

    dfs2(rt);
    forn(i,n/2) {
        addor(percol[i][0],percol[i][1]);
        addor(neg(percol[i][0]),neg(percol[i][1]));
    }

    if (!satisf())
        return {};

    vi ret;
    forn(i,n) if (verdad[cmp[i]]) ret.pb(i);
    return ret;
}

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(_,t) {
        int N; cin >> N;
        forn(i,2*N) cin >> col[i];

        forn(i,N) percol[i].clear();
        forn(i,2*N) percol[col[i]-1].pb(i);

        forn(i,2*N) G[i].clear();
        forn(i,2*N-1) {
            int u,v; cin >> u >> v; --u, --v;
            G[u].pb(v), G[v].pb(u);
        }

        n = 2*N;
        vi rta;
        for (auto &i : percol[0]) {
            vi r = go(i);
            if (!r.empty()) {
                rta = r; break;
            }
        }

        if (rta.empty()) cout << "-1\n";
        else {
            for (auto &i : rta) cout << i+1 << ' ';
            cout << '\n';
        }
    }

    return 0;
}
