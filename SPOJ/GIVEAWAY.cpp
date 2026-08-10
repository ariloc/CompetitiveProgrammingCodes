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

int const MAXN = 5e5+5;
int const BLOCK = 710;

int arr[MAXN], ord[MAXN];

void fix(int i){
    int bl = i*BLOCK, br = min(MAXN,(i+1)*BLOCK);
    if (bl >= MAXN) return;
    forsn(i,bl,br) ord[i] = arr[i];
    sort(ord+bl,ord+br);
}

int query(int l, int r, int c) {
    int cnt = 0;
    int bl = l/BLOCK, br = r/BLOCK;

    if (bl == br) {
        forsn(i,l,r+1) if (arr[i] >= c) ++cnt;
        return cnt;
    }

    forsn(i,bl+1,br) {
        int idx = lower_bound(ord+i*BLOCK,ord+(i+1)*BLOCK,c)-ord-i*BLOCK;
        cnt += BLOCK-idx;
    }
    forsn(i,l,(bl+1)*BLOCK) if (arr[i] >= c) ++cnt;
    forsn(i,br*BLOCK,r+1) if (arr[i] >= c) ++cnt;
    return cnt;
}

void upd(int p, int v) {
    arr[p] = v;
    fix(p/BLOCK);
}

int main() {
    FAST_IO;

    int n; cin >> n;
    forn(i,n) cin >> arr[i];

    forn(i,BLOCK) fix(i);

    int q; cin >> q;
    forn(_,q) {
        int typ; cin >> typ;
        if (!typ) {
            int a,b,c; cin >> a >> b >> c; --a, --b;
            cout << query(a,b,c) << '\n';
        }
        else {
            int a,b; cin >> a >> b; --a;
            upd(a,b);
        }
    }

    return 0;
}
