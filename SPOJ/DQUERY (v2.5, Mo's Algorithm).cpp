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

int const MAXN = 3e4+5;
int const MAXQ = 2e5+5;
int const MAXV = 1e6+5;

int arr[MAXN];
int rta = 0;
int occur[MAXV];

void init(){}
void add(int i){
    if (!occur[arr[i]]) rta++;
    occur[arr[i]]++;
}
void remove(int i) {
    if (occur[arr[i]] == 1) --rta;
    occur[arr[i]]--;
}
int get_ans(){return rta;}

int n,sq,nq; // array size, sqrt(array size), #queries
struct qu{int l,r,id;};
qu qs[MAXQ];
ll ans[MAXQ]; // ans[i] = answer to ith query
bool qcomp(const qu &a, const qu &b){
    if(a.l/sq!=b.l/sq) return a.l<b.l;
    return (a.l/sq)&1?a.r<b.r:a.r>b.r;
}
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

    cin >> n;
    forn(i,n) cin >> arr[i];
    cin >> nq;
    forn(i,nq) cin >> qs[i].l >> qs[i].r, --qs[i].l;

    mos();

    forn(i,nq) cout << ans[i] << '\n';

    return 0;
}
