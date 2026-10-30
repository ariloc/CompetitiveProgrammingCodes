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

typedef struct item *pitem;
struct item {
	int pr,key,cnt;
	pitem l,r;
	item(int key):key(key),pr(rand()),cnt(1),l(0),r(0) {}
};
int cnt(pitem t){return t?t->cnt:0;}
void upd_cnt(pitem t){if(t)t->cnt=cnt(t->l)+cnt(t->r)+1;}
void split(pitem t, int key, pitem& l, pitem& r){ // l: < key, r: >= key
	if(!t)l=r=0;
	else if(key<t->key)split(t->l,key,l,t->l),r=t;
	else split(t->r,key,t->r,r),l=t;
	upd_cnt(t);
}
void insert(pitem& t, pitem it){
	if(!t)t=it;
	else if(it->pr>t->pr)split(t,it->key,it->l,it->r),t=it;
	else insert(it->key<t->key?t->l:t->r,it);
	upd_cnt(t);
}
void merge(pitem& t, pitem l, pitem r){
	if(!l||!r)t=l?l:r;
	else if(l->pr>r->pr)merge(l->r,l->r,r),t=l;
	else merge(r->l,l,r->l),t=r;
	upd_cnt(t);
}
void erase(pitem& t, int key){
	if(t->key==key)merge(t,t->l,t->r);
	else erase(key<t->key?t->l:t->r,key);
	upd_cnt(t);
}
pair<int,int> lb(pitem t, int key){ // position and value of lower_bound
	if(!t)return {0,1<<30}; // (special value)
	if(key>t->key){
		auto w=lb(t->r,key);w.fst+=cnt(t->l)+1;return w;
	}
	auto w=lb(t->l,key);
	if(w.fst==cnt(t->l))w.snd=t->key;
	return w;
}

int const MAXN = 2e5+5;

pitem bycol[2*MAXN];
int arr[MAXN];
vi nums;
vector<ii> quer;

int main() {
    FAST_IO;

    int n,q; cin >> n >> q;
    forn(i,n) cin >> arr[i], nums.pb(arr[i]);

    forn(i,q) {
        int p,a; cin >> p >> a;
        quer.pb({p,a});
        nums.pb(a);
    }

    sort(all(nums));
    nums.erase(unique(all(nums)),nums.end());

    forn(i,n) arr[i] = lower_bound(all(nums),arr[i])-nums.begin();
    forn(i,q) quer[i].snd = lower_bound(all(nums),quer[i].snd)-nums.begin();

    forn(i,n) insert(bycol[arr[i]],new item(i));

    forn(i,q) {
        auto [p,a] = quer[i];
        erase(bycol[arr[p]],p);
        arr[p] = a;
        insert(bycol[arr[p]], new item(p));
        cout << lb(bycol[arr[p]],p).fst << '\n';
    }

    return 0;
}
