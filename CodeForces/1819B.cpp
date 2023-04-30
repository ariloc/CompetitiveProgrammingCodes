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

const int MAXN = 2e5+5;
const ll INF = 9e18;

struct rect {
    ll s1,s2; int ind;

    bool operator!= (const rect &o) const {
        return (s1 != o.s1) || (s2 != o.s2);
    }
};

int n;
ii arr[MAXN];
rect stash1[MAXN], stash2[MAXN];
map<int,bool> seen;

rect solve (int a, int b, bool cut, rect me) {
    if (a >= n || b >= n) return me;
    while (a < n && seen.count(stash1[a].ind)) a++;
    while (b < n && seen.count(stash2[b].ind)) b++;
    if (a >= n || b >= n) return me;

    if (!cut) {
        if (me.s1 == stash1[a].s1) {
            seen[stash1[a].ind] = true;
            return {me.s1, solve(a+1,b,cut,stash1[a]).s2 + me.s2};
        }
        seen[stash2[b].ind] = true;
        rect aux = solve(a,b+1,1^cut,stash2[b]);
        if (aux.s1 != me.s1) return {-INF,-INF};
        return {me.s1, me.s2 + aux.s2};
    }

    // cut == 1
    if (me.s2 == stash2[b].s2) {
        seen[stash2[b].ind] = true;
        return {me.s1 + solve(a,b+1,cut,stash2[b]).s1, me.s2};
    }
    seen[stash1[a].ind] = true;
    rect aux = solve(a+1,b,1^cut,stash1[a]);
    if (aux.s2 != me.s2) return {-INF, -INF};
    return {me.s1 + aux.s1, me.s2};
}

int main() {
    int t; scanf("%d",&t);

    forn(_,t) {
        scanf("%d", &n);
        forn(i,n) scanf("%d %d",&arr[i].fst,&arr[i].snd);
        forn(i,n) stash1[i] = stash2[i] = {arr[i].fst, arr[i].snd, i};

        sort(stash1,stash1+n,[](const rect &lhs, const rect &rhs) {
            if (lhs.s1 != rhs.s1) return lhs.s1 > rhs.s1;
            return lhs.s2 > rhs.s2;
        });
        sort(stash2,stash2+n,[](const rect &lhs, const rect &rhs){
            if (lhs.s2 != rhs.s2) return lhs.s2 > rhs.s2;
            return lhs.s1 > rhs.s1;
        });

        seen.clear();
        seen[stash1[0].ind] = true;
        rect ans1 = solve(1,0,false,stash1[0]);
        seen.clear();
        seen[stash2[0].ind] = true;
        rect ans2 = solve(0,1,true,stash2[0]);

        vector<rect> rta;
        if (ans1.s1 >= 0 && ans1.s2 >= 0) rta.pb(ans1);
        if (ans2.s1 >= 0 && ans2.s2 >= 0 && ans1 != ans2) rta.pb(ans2);

        printf("%d\n",(int)rta.size());
        for (auto &i : rta) printf("%lld %lld\n",i.s1,i.s2);
    }

    return 0;
}
