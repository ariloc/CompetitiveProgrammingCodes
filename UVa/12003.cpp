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

int const MAXN = 3e5+5;
int const MAXV = 1e9+20;
int const BLOCK = 550;

ll arr[MAXN];
ll sorted[MAXN];

int get(int l, int r, int v) {
    int ret = 0;

    int lb = l/BLOCK, rb = r/BLOCK;
    
    if (lb == rb) {
        forsn(i,l,r+1)
            if (arr[i] < v) ++ret;
        return ret;
    }

    forsn(i,lb+1,rb)
        ret += lower_bound(sorted+i*BLOCK,sorted+(i+1)*BLOCK,v)-(sorted+i*BLOCK);

    int top = (lb+1)*BLOCK;
    forsn(i,l,top)
        if (arr[i] < v) ++ret;

    int inf = rb*BLOCK;
    forsn(i,inf,r+1)
        if (arr[i] < v) ++ret;
    return ret;
}

void fix(int bl) {
    int ml = bl*BLOCK, mr = min(MAXN,(bl+1)*BLOCK);
    if (ml >= MAXN) return;
    forsn(i,ml,mr) sorted[i] = arr[i];
    sort(sorted+ml,sorted+mr);
}

int main() {
    FAST_IO;

    int n,m,u; cin >> n >> m >> u;
    forn(i,n) cin >> arr[i];

    forn(i,n) sorted[i] = arr[i];

    forn(i,BLOCK) fix(i);

    forn(i,m) {
        int l,r,v,p; cin >> l >> r >> v >> p;
        --l,--r,--p;

        int k = get(l,r,v);
        arr[p] = ((ll)u*k / (r-l+1));
        fix(p/BLOCK);
    }

    forn(i,n) cout << arr[i] << '\n';

    return 0;
}
