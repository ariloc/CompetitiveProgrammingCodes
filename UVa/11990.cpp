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

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

int const MAXN = 2e5+5;
int const BLOCK = 450;
int const INF = 1e9;

int arr[MAXN],ord[MAXN],pos[MAXN];
int delcnt[BLOCK];
int n,m;
int lastblock;
ll inv = 0;

void fix(int i) {
    int bl = i*BLOCK, br = min(MAXN,(i+1)*BLOCK);
    if (bl >= MAXN) return;
    forsn(j,bl,br) ord[j] = arr[j];
    sort(ord+bl,ord+br);
}

void del(int p) {
    int val = arr[p];
    int bo = p/BLOCK;
    forn(i,bo) {
        int idx = lower_bound(ord+i*BLOCK,ord+(i+1)*BLOCK,val)-ord-i*BLOCK;
        inv -= BLOCK - idx;
    }
    forsn(i,bo+1,lastblock) {
        int idx = lower_bound(ord+i*BLOCK,ord+(i+1)*BLOCK,val)-ord-i*BLOCK;
        inv -= idx - delcnt[i];
    }
    forsn(i,max((bo+1)*BLOCK,lastblock*BLOCK),n) 
        if (arr[i] != -1 && arr[i] < val) --inv;

    forsn(i,bo*BLOCK,p) if (arr[i] != -1 && arr[i] > val) --inv;
    forsn(i,p+1,min(n,(bo+1)*BLOCK)) if (arr[i] != -1 && arr[i] < val) --inv;
    arr[p] = -1;
    delcnt[bo]++;
    fix(bo);
}

int main() {
    FAST_IO;

    while (cin >> n >> m) {
        forn(i,n) cin >> arr[i];
        forn(i,n) pos[arr[i]] = i;

        inv = 0;
        lastblock = (n-1)/BLOCK;
        forn(i,lastblock+1) fix(i), delcnt[i] = 0;

        ordered_set seen;
        dforn(i,n) {
            seen.insert(arr[i]);
            inv += seen.order_of_key(arr[i]);
        }

        forn(i,m) {
            int x; cin >> x;
            cout << inv << '\n';
            del(pos[x]);
        }
    }

    return 0;
}
