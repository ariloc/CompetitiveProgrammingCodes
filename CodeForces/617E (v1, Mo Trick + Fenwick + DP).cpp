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

const int MAXN = 1e5+10;
const int MAXA = 1<<21;

struct query {
    int l,r,id;

    bool operator< (const query &o) const {
        if (r != o.r) return r < o.r;
        return l > o.l;
    }
};

int arr[MAXN], cnt[MAXA];
vector<query> queries;
vi appear[MAXA];
vi grp1;
bitset<MAXA> ingrp, inarr;
int dp1[MAXN], dp2[MAXN];
ll rta[MAXN];
int FT[MAXN];

void setFT (int p, int v) {
    p += 4;
    for (int i = p; i < MAXN; i += i & -i)
        FT[i] += v;
}


int getFT (int p) {
    p += 4;
    int r = 0;
    for (int i = p; i; i -= i & -i)
        r += FT[i];
    return r;
}

int main() {
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);

    forn(i,n) scanf("%d",&arr[i]);

    forn(i,m) {
        int l,r; scanf("%d %d",&l,&r); l--, r--;
        queries.pb({l,r,i});
    }

    sort(all(queries));

    forsn(i,1,n) arr[i] ^= arr[i-1], inarr[arr[i]] = true;
    forn(i,n) cnt[arr[i]]++;
    forn(i,MAXA) {
        if (!inarr[i]) continue;
        if (i < (i^k)) continue;
        ll pairs = cnt[i] * (ll)cnt[i^k];
        if (pairs >= n)
            grp1.pb(i), ingrp[i] = true;
    }

    for (auto &e : grp1) {
        forn(i,n+5) dp1[i] = dp2[i] = 0;

        if (!e) dp1[1] = dp1[2] = 1;
        if (!(e^k)) dp2[1] = dp2[2] = 1;

        int ind = 0;
        forn(i,n) {
            if (arr[i] == e) dp1[i+2]++;
            if (arr[i] == (e^k)) dp2[i+2]++;

            while (ind < m && queries[ind].r < i) ind++;
            while (ind < m && queries[ind].r == i) {
                int cnt1 = dp1[i+2] - dp1[queries[ind].l];
                int cnt2 = dp2[i+2] - dp2[queries[ind].l];
                ll val = (ll)cnt1 * cnt2;
                if (!k) val = ((ll)cnt1 * (cnt1-1))/2LL;
                rta[queries[ind].id] += val;
                ind++;
            }

            dp1[i+3] += dp1[i+2];
            dp2[i+3] += dp2[i+2];
        }
    }

    int ind = 0;
    appear[0].pb(-1);
    forn(i,n) {
        if (!ingrp[arr[i]] && !ingrp[arr[i]^k]) {
            for (auto &j : appear[arr[i]^k]) 
                setFT(j+1,1);
            
            appear[arr[i]].pb(i);
        }
        
        while (ind < m && queries[ind].r < i) ind++;
        while (ind < m && queries[ind].r == i) {
            rta[queries[ind].id] += getFT(queries[ind].r) - getFT(queries[ind].l-1);
            ind++;
        }
    }

    forn(i,m) printf("%lld\n",rta[i]);
    
    return 0;
}
