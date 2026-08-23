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

int const MAXN = 1e5+5;

vector<string> bank;
string a,dupa;
int n,m;

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

int quer[2*MAXN];

bool can(int w) {
    unordered_set<ll> seen;

    for (auto &s : bank) {
        Hash sh = Hash(s);
        forn(i,sz(s)-w+1) seen.insert(sh.get(i,i+w));
    }

    forn(i,2*n) quer[i] = 0;

    Hash h(dupa);
    forn(i,2*n-w+1)
        if (seen.count(h.get(i,i+w)))
            quer[max(0,i+w-n)]++, quer[i+1]--;
    
    int s = 0;
    forn(i,n) {
        s += quer[i];
        if (!s) return true;
    }
    return false;
}

int main() {
    FAST_IO;

    cin >> n >> m;
    cin >> a;
    dupa = a + a;
    forn(i,m) {
        string s; cin >> s;
        bank.pb(s);
    }

    int lo = -1, hi = n;
    while (hi-lo > 1) {
        int mid = (hi+lo)/2;
        if (can(mid)) hi = mid;
        else lo = mid;
    }

    cout << hi-1 << '\n';

    return 0;
}
