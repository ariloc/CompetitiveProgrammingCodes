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

int const MAXN = 3e4+5;
int const MAXQ = 2e5+5;
int const MAXE = 1e6+5;
int const BLOCK = 175;

struct query {
    int l,r,id;
};

bool byL (const query &lhs, const query &rhs) {
    if (lhs.l != rhs.l) return lhs.l < rhs.l;
    return lhs.r < rhs.r;
}

bool byR (const query &lhs, const query &rhs) {
    if (lhs.r != rhs.r) return lhs.r < rhs.r;
    return lhs.l < rhs.l;
}

int arr[MAXN], ap[MAXE];
query queries[MAXQ];
int rta[MAXQ];
int cnt = 0;

void add (int i) {
    if (!ap[i]) cnt++;
    ap[i]++;
}

void del (int i) {
    ap[i]--;
    if (!ap[i]) cnt--;
}

int main() {
    int n; scanf("%d",&n);
    forn(i,n) scanf("%d",&arr[i]);

    int q; scanf("%d",&q);
    forn(i,q) {
        int l,r; scanf("%d %d",&l,&r); l--, r--;
        queries[i] = {l,r,i};
    }

    sort(queries,queries+q,byL);

    int ind = 0;
    forn(i,q) {
        if (queries[i].l-queries[ind].l > BLOCK) {
            sort(queries+ind,queries+i,byR);
            ind = i;
        }
    }
    sort(queries+ind,queries+q,byR);

    int l = 0, r = 0;
    add(arr[0]);
    forn(i,q) {
        int dl = queries[i].l-l, dr = queries[i].r-r;
        while (l != queries[i].l) {
            if (dl > 0) del(arr[l++]);
            else add(arr[--l]);
        }
        while (r != queries[i].r) {
            if (dr > 0) add(arr[++r]);
            else del(arr[r--]);
        }
        rta[queries[i].id] = cnt;
    }

    forn(i,q) printf("%d\n",rta[i]);
 
    return 0;
}
