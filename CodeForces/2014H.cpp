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
int const MAXV = 1e6+5;

int arr[MAXN];
bitset<MAXV> od;
bitset<MAXV> seen;
int cntod;
vi toreset;

int n,sq,nq; // array size, sqrt(array size), #queries
struct qu{int l,r,id;};
qu qs[MAXN];
bitset<MAXN> ans;
bool qcomp(const qu &a, const qu &b){
    if(a.l/sq!=b.l/sq) return a.l<b.l;
    return (a.l/sq)&1?a.r<b.r:a.r>b.r;
}

void init(){
    cntod=0;
    for (auto &i : toreset) od[i] = seen[i] = false;
    toreset.clear();
}
void add(int i) {
    if (od[arr[i]]) cntod--; else cntod++;
    if (!seen[arr[i]]) seen[arr[i]] = true, toreset.pb(arr[i]);
    od[arr[i]]=!od[arr[i]];
}
void remove(int i) {add(i);}
bool get_ans(){return !cntod;}
void mos(){
    forn(i,nq)qs[i].id=i;
    sq=sqrt(n)+.5;
    sort(qs,qs+nq,qcomp);
    int l=0,r=0;
    init();
    forn(i,nq){
        qu q=qs[i];
        while(l>q.l)add(--l);
        while(r<q.r)add(r++);
        while(l<q.l)remove(l++);
        while(r>q.r)remove(--r);
        ans[q.id]=get_ans();
    }
}

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(_,t) {
        cin >> n >> nq;
        forn(i,n) cin >> arr[i];

        forn(i,nq) cin >> qs[i].l >> qs[i].r, --qs[i].l;

        mos();

        forn(i,nq) cout << (ans[i] ? "YES" : "NO") << '\n';
    }
 
    return 0;
}
