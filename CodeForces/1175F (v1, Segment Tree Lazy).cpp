#include<bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define fst first
#define snd second
#define pb push_back
#define sz(c) (int)c.size()
#define all(c) (c).begin(),(c).end()
#define FAST_IO ios::sync_with_stdio(false);

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

int const MAXN = 3e5+5;
int const INF = 2e9;

struct STree {
    vi st,lazy; int n;
    STree(int n) : st(4*n+5,0), lazy(4*n+n,0), n(n) {}
    void init(int k, int s, int e, int *a) {
        lazy[k] = -INF;
        if (s+1==e){st[k]=a[s];return;}
        int m=(s+e)/2;
        init(2*k,s,m,a);init(2*k+1,m,e,a);
        st[k]=st[2*k]+st[2*k+1];
    }
    void push(int k,int s,int e){
        if(lazy[k]<0)return;
        st[k]=(e-s)*lazy[k];
        if(s+1<e){
            lazy[2*k]=lazy[k];
            lazy[2*k+1]=lazy[k];
        }
        lazy[k]=0;
    }
    void upd(int k,int s,int e,int a,int b,int v){
        push(k,s,e);
        if(s>=b||e<=a)return;
        if(s>=a&&e<=b){
            lazy[k]=v;
            push(k,s,e);return;
        }
        int m=(s+e)/2;
        upd(2*k,s,m,a,b,v);upd(2*k+1,m,e,a,b,v);
        st[k]=st[2*k]+st[2*k+1];
    }
    int query(int k,int s,int e,int a,int b){
        if(s>=b||e<=a)return 0;
        push(k,s,e);
        if(s>=a&&e<=b)return st[k];
        int m=(s+e)/2;
        return query(2*k,s,m,a,b)+query(2*k+1,m,e,a,b);
    }
    void init(int *a){init(1,0,n,a);}
    void upd(int a,int b,int v){upd(1,0,n,a,b,v);}
    int query(int a,int b){return query(1,0,n,a,b);}
};

vector<ii> rang;
set<int> leftb;
set<int> freesp;
vi rangeach[MAXN];
vi toAdd[MAXN];

int main(){
    FAST_IO;

    int n; cin >> n;
    forn(i,n) {
        int x; cin >> x;
        rang.pb({x,i});
    }

    STree rmq(n);
    vi auxi(n,0);
    fill(all(auxi),1);
    rmq.init(auxi.data());

    sort(all(rang));

    forn(i,n) freesp.insert(i);
    forn(i,n) rangeach[rang[i].fst].pb(rang[i].snd);
    
    ll rta = 0;
    forn(k,n+1) {
        set<int> newset;
        for (auto &e : toAdd[k]) leftb.insert(e);
        for (auto &e : leftb) {
            if (e-1 >= 0 && rmq.query(e-1,e)) {
                rmq.upd(e-1,e,0);
                //cerr << e << ' ' << "!!" << endl;
                newset.insert(e-1);
            }
        }
        swap(newset, leftb);

        forsn(i,1,sz(rangeach[k])) {
            int l = rangeach[k][i-1], r = rangeach[k][i];
            int bl = max(0,r-k+1), br = l+1;
            if (br > bl) {
                rmq.upd(bl, br, 0);
                leftb.insert(bl);
            }
            else toAdd[k+bl-br+1].pb(l+1);
        }

        for (auto &i : rangeach[k]) freesp.erase(i);

        for (auto &i : rangeach[k]) {
            int minl = 0, maxr = n-1;

            auto it = freesp.lower_bound(i);
            if (it != freesp.end())
                maxr = min(maxr, (*it)-1);
            if (it != freesp.begin()) {
                --it;
                minl = max(minl, (*it)+1);
            }

            int l = max(0, max(minl,i-k+1));
            int r = min(i,maxr-k+1);

            //cerr << l << ' ' << r << ' ' << i << ' ' << k << endl;
            if (l <= r) {
                rta += rmq.query(l,r+1);
                //cerr << "OKI" << ' ' << rmq.query(l,r+1) << endl;
            }
        }
    }

    cout << rta << '\n';

    return 0;
}
