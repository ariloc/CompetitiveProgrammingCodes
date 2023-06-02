#include <algorithm>
#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define dbg(x) cerr << #x << " = " << x << endl;
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;
typedef long double ld;

const int MAXN = 3e4+10;
const int MAXQ = 2e5+10;

struct query {
    int l,r,k,id;

    bool operator< (const query &o) const {
        return k < o.k;
    }
};

int arr[MAXN], FT[MAXN];
vi pts;
vector<query> queries;
vector<ii> updates;
int rta[MAXQ];

void update (int &x) {
    x = lower_bound(all(pts),x)-pts.begin();
}

void setFT (int p, int v) {
    p += 5;
    for (int i = p; i < MAXN; i += i &-i)
        FT[i] += v;
}

int getFT (int p) {
    p += 5;
    int r = 0;
    for (int i = p; i; i -= i & -i)
        r += FT[i];
    return r;
}

int main() {
    int n; scanf("%d",&n);

    queries.reserve(MAXQ);
    updates.reserve(MAXN);
    pts.reserve(MAXN);

    forn(i,n) scanf("%d",&arr[i]);

    forn(i,n) pts.pb(arr[i]);
    sort(all(pts));
    pts.erase(unique(all(pts)), pts.end());

    forn(i,n) update(arr[i]);

    int q; scanf("%d",&q);
    forn(i,q) {
        int l,r,k; scanf("%d %d %d",&l,&r,&k);
        l--, r--;
        k++;
        update(k);
        queries.pb({l,r,k,i});
    }

    sort(all(queries));
    reverse(all(queries));

    forn(i,n) updates.pb({arr[i],i});
    sort(all(updates));
    reverse(all(updates));

    int ind = 0;
    for (auto &i : queries) {
        while (ind < n && updates[ind].fst >= i.k) {
            setFT(updates[ind].snd, 1);
            ind++;
        }
        rta[i.id] = getFT(i.r) - getFT(i.l-1);
    }

    forn(i,q) printf("%d\n",rta[i]);

    return 0;
}
