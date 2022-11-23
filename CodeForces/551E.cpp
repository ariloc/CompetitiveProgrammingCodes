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

// Let's try to solve it with Sqrt Decomposition!

const int MAXN = 5e5+5005;
const int MAXB = 710;
const int MAXY= 1e9;
const int INF = 2e9;

ll arr[MAXN], blockInc[MAXB];
map<int,ii> nearPerBlock[MAXB];

void update (int block, int val, int ind) {
    auto it = nearPerBlock[block].find(val);
    ii curr = {ind,ind};
    if (it != nearPerBlock[block].end()) {
        auto e = *it;
        curr.fst = min(curr.fst, e.snd.fst);
        curr.snd = max(curr.snd, e.snd.snd);
        (*it).snd = curr;
    }
    else nearPerBlock[block][val] = curr;
}

int main() {
    int n,q; scanf("%d %d", &n, &q);
    forn(i,n) scanf("%lld", &arr[i]);

    // build
    int len = sqrt(n) + 1;
    int block = 0, nxt = len;
    forn(i,n) {
        if (i >= nxt) block++, nxt += len;
        update(block, arr[i], i);
    }

    forn(_,q) {
        int typ; scanf("%d", &typ);
        if (typ == 1) {
            int l,r,x; scanf("%d %d %d", &l, &r, &x), l--, r--;

            int l_block = l / len, r_block = r / len;
            if (l_block == r_block) {
                int st = l_block*len, nd = (l_block+1)*len;
                nearPerBlock[l_block].clear();
                forsn(i,l,r+1) arr[i] += x;
                forsn(i,st,nd) 
                    if (arr[i] <= MAXY) 
                        update(l_block, arr[i], i); 
            }
            else {
                int st = l_block*len, nd = (l_block+1)*len;
                nearPerBlock[l_block].clear();
                forsn(i,l,nd) arr[i] += x;
                forsn(i,st,nd) update(l_block, arr[i], i);

                forsn(i,l_block+1, r_block)
                    blockInc[i] += x;

                st = r_block*len; nd = (r_block+1)*len;
                nearPerBlock[r_block].clear();
                forsn(i,st,r+1) arr[i] += x;
                forsn(i,st,nd) 
                    if (arr[i] <= MAXY) 
                        update(r_block, arr[i], i);
            }
        }
        else {
            int y; scanf("%d", &y);

            int mini = INF, maxi = -INF;
            for (int i = 0; i*len <= n; i++) {
                if (y - blockInc[i] < 0) continue;
                auto it = nearPerBlock[i].find(y-blockInc[i]);
                if (it != nearPerBlock[i].end()) {
                    auto e = *it;
                    mini = min(mini, e.snd.fst);
                    maxi = max(maxi, e.snd.snd);
                }
            }

            if (mini == INF) printf("-1\n");
            else printf("%d\n",maxi-mini);
        }
    }
            
    return 0;
}

