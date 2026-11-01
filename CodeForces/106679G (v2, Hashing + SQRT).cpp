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

int const MAXG = 5e5+5;
int const MAXN = 1e5+5;
int const MAXK = 320;
int const MAXQ = 1e5+5;
int const MAXL = 1005;
int const INF = 2e9;

struct Hash {
	int P=1777771,MOD[2],PI[2];
	vector<int> h[2],pi[2];
	Hash(string& s){
		MOD[0]=999727999;MOD[1]=1070777777;
		PI[0]=325255434;PI[1]=10018302;
		forn(k,2)h[k].resize(s.size()+1),pi[k].resize(s.size()+1);
		forn(k,2){
			h[k][0]=0;pi[k][0]=1;
			ll p=1;
			forsn(i,1,s.size()+1){
				h[k][i]=(h[k][i-1]+p*s[i-1])%MOD[k];
				pi[k][i]=(1LL*pi[k][i-1]*PI[k])%MOD[k];
				p=(p*P)%MOD[k];
			}
		}
	}
	ll get(int s, int e){ // [s,e)
		ll h0=(h[0][e]-h[0][s]+MOD[0])%MOD[0];
		h0=(1LL*h0*pi[0][s])%MOD[0];
		ll h1=(h[1][e]-h[1][s]+MOD[1])%MOD[1];
		h1=(1LL*h1*pi[1][s])%MOD[1];
		return (h0<<32)|h1;
	}
};

vector<ii> queries[MAXN];
int rta[MAXQ];
int minipos[MAXN],bk[MAXN];
int block[MAXK];

vector<string> genes;
unordered_map<ll,int> hashes[MAXL];

int main() {
    FAST_IO;

    string s; cin >> s;
    int n = sz(s);

    vi lens;

    int g; cin >> g;
    forn(i,g) {
        string ge; cin >> ge;
        lens.pb(sz(ge));
        genes.pb(ge);
    }

    sort(all(lens));
    lens.erase(unique(all(lens)),lens.end());

    forn(i,sz(genes)) {
        int ind = lower_bound(all(lens),sz(genes[i]))-lens.begin();
        Hash auxi(genes[i]);
        hashes[ind][auxi.get(0,sz(genes[i]))] = i+1;
    }

    int q; cin >> q;
    forn(i,q) {
        int l,r; cin >> l >> r; --l, --r;
        queries[r].pb({l,i});
    }

    Hash cad(s);

    forn(i,n) minipos[i] = INF, bk[i] = i/MAXK;
    forn(i,MAXK) block[i] = INF;

    forn(i,n) {
        forn(j,sz(lens)) {
            int l = lens[j];
            int pos = i-l+1;
            if (pos < 0) break;
            ll val = cad.get(pos,i+1);
            auto it = hashes[j].find(val);
            if (it != hashes[j].end()) {
                int id = (*it).snd;
                minipos[pos] = min(minipos[pos],id);
                block[bk[pos]] = min(block[bk[pos]],id);
            }
        }

        for (auto &e : queries[i]) {
            int ret = INF;
            if (bk[e.fst] == bk[i]) forsn(j,e.fst,i+1) ret = min(ret,minipos[j]);
            else {
                int lb = e.fst/MAXK + 1, rb = i/MAXK - 1;
                int l = lb*MAXK, r = (rb+1)*MAXK-1; 
                forsn(j,e.fst,l) ret = min(ret,minipos[j]);
                forsn(j,lb,rb+1) ret = min(ret,block[j]);
                forsn(j,r+1,i+1) ret = min(ret,minipos[j]);
            }
            rta[e.snd] = ret == INF ? -1 : ret;
        }
    }

    forn(i,q) cout << rta[i] << '\n';

    return 0;
}
