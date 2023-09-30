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

int const MAXN = 1e5+5;
int const MAXST = (1<<(32-__builtin_clz(MAXN)));

struct mon {
    int cnt;
    int x0, x1;

    mon operator+ (const mon &o) const {
        return (mon){cnt + o.cnt, x0^o.x0, x1^o.x1};
    }
};

int arr[MAXN];
mon ST[2*MAXST];
bool lazy[2*MAXST];
int N;

void passLazy (int i, int tl, int tr) {
    if (lazy[i]) {
        ST[i].cnt = (tr-tl) - ST[i].cnt;
        swap(ST[i].x0, ST[i].x1);
    }

    if (2*i < 2*MAXST) {
        lazy[2*i] ^= lazy[i];
        lazy[2*i+1] ^= lazy[i];
    }

    lazy[i] = 0;
}

void update (int i, int bl, int br, int tl = 0, int tr = N) {
    passLazy(i,tl,tr);
    if (tl >= br || tr <= bl) return;
    if (tl >= bl && tr <= br) {
        lazy[i] ^= 1;
        passLazy(i,tl,tr);
        return;
    }
    int mid = (tl+tr)/2;
    update(2*i,bl,br,tl,mid);
    update(2*i+1,bl,br,mid,tr);
    ST[i] = ST[2*i] + ST[2*i+1];
}

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(_,t) {
        int n; cin >> n;
        forn(i,n) cin >> arr[i];
        string s; cin >> s;

        N = (1<<(32-__builtin_clz(n)));
        forn(i,2*N) lazy[i] = 0, ST[i] = {0,0,0};

        forn(i,n) {
            ST[i+N].cnt = (s[i] - '0');
            if ((s[i]-'0')) ST[i+N].x1 = arr[i];
            else ST[i+N].x0 = arr[i];
        }

        dforsn(i,1,N) ST[i] = ST[2*i] + ST[2*i+1];

        int q; cin >> q;
        forn(i,q) {
            int typ; cin >> typ;
            if (typ == 1) {
                int l,r; cin >> l >> r;
                update(1,l-1,r);
            }
            else {
                int g; cin >> g;
                if (g) cout << ST[1].x1 << ' ';
                else cout << ST[1].x0 << ' ';
            }
        }
        cout << '\n';
    }
    
    return 0;
}
