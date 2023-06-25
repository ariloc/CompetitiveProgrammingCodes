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

const int MAXN = 1e5+5;
const int MAXM = 1<<22;
const int BLOCK = 320;
const int INF = 2e9;

struct query {
    int l,r,id;
};

bool byX (const query &lhs, const query &rhs) {
    if (lhs.l != rhs.l) return lhs.l < rhs.l;
    return lhs.r < rhs.r;
}

bool inRange (const query &lhs, const query &rhs) {
    if (lhs.r != rhs.r) return lhs.r < rhs.r;
    return lhs.l < rhs.l;
}

int arr[MAXN];
vector<query> queries;
int cnt[MAXM];
ll rtaarr[MAXN];

int main() {
    int n,m,k; scanf("%d %d %d",&n,&m,&k);

    forn(i,n) scanf("%d",&arr[i+1]);

    forsn(i,1,n+1) arr[i] ^= arr[i-1];

    forn(i,m) {
        int l,r; scanf("%d %d",&l,&r);
        queries.pb({l,r,i});
    }

    sort(all(queries),byX); 

    int ind = 0;
    queries.pb({INF,INF,-1});
    forn(i,m+1) {
        if (queries[i].l > queries[ind].l + BLOCK) {
            sort(queries.begin()+ind,queries.begin()+i,inRange);
            ind = i;
        }
    }
    queries.pop_back();

    int l = 1, r = 1;
    ll rta = (arr[1] == k);
    cnt[0] = 1;
    for (auto &q : queries) {
        while (q.r != r) {
            int dir = abs(q.r-r) / (q.r-r);
            if (dir == 1) {
                cnt[arr[r]]++;
                r += dir;
                rta += cnt[arr[r]^k];
            }
            else {
                rta -= cnt[arr[r]^k];
                r += dir;
                cnt[arr[r]]--;
            }
        }
        while (q.l != l) {
            int dir = abs(q.l-l) / (q.l-l);
            if (dir == 1) {
                cnt[arr[l-1]]--;
                rta -= cnt[arr[l-1]^k];
                if (arr[r] == (arr[l-1]^k)) rta--;
                l += dir;
            }
            else {
                l += dir;
                rta += cnt[arr[l-1]^k];
                if (arr[r] == (arr[l-1]^k)) rta++;
                cnt[arr[l-1]]++;
            }
        }

        rtaarr[q.id] = rta;
    }

    forn(i,m) printf("%lld\n",rtaarr[i]);

      
    return 0;
}
