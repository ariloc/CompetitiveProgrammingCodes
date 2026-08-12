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
int const MAXV = 1<<20;

ll cnt = 0;
int arr[MAXN];
int reg[MAXV];
int dp[MAXN];

int n,m,k;
int sq,nq; // array size, sqrt(array size), #queries
struct qu{int l,r,id;};
qu qs[MAXN];
ll ans[MAXN]; // ans[i] = answer to ith query
bool qcomp(const qu &a, const qu &b){
    if(a.l/sq!=b.l/sq) return a.l<b.l;
    return (a.l/sq)&1?a.r<b.r:a.r>b.r;
}

void add(int i) {
    cnt += reg[dp[i+1]^k];
    reg[dp[i+1]]++;
}

void remove(int i) {
    reg[dp[i+1]]--;
    cnt -= reg[dp[i+1]^k];
}

ll get_ans(int l){
    return cnt + (l ? reg[dp[l]^k] : reg[k]);
}

void mos(){
    sq=sqrt(n)+.5;
    sort(qs,qs+nq,qcomp);
    int l=0,r=0;
    forn(i,nq){
        qu q=qs[i];
        while(l>q.l)add(--l);
        while(r<q.r)add(r++);
        while(l<q.l)remove(l++);
        while(r>q.r)remove(--r);
        ans[q.id]=get_ans(l);
    }
}

int main() {
    FAST_IO;

    cin >> n >> m >> k;
    forn(i,n) cin >> arr[i];

    nq = m;
    forn(i,m) {
        int l,r; cin >> l >> r; l--;
        qs[i] = {l,r,i};
    }

    forn(i,n) dp[i+1] = dp[i]^arr[i];

    mos();

    forn(i,m) cout << ans[i] << '\n';

    return 0;
}
