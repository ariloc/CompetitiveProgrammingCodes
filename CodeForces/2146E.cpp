#include<bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;

int const MAXN = 3e5+5;
int const MAXST = (1<<(32-__builtin_clz(MAXN)));
int const INF = 2e9;

struct mon {
    int s,maxi;

    mon operator+ (const mon &o) const {
        return {s+o.s,max(maxi,o.maxi)};
    }
};

mon ST[2*MAXST];
int lazy[2*MAXST];
int arr[MAXN];

void pushLazy(int i) {
    ST[i].s += lazy[i];
    ST[i].maxi += lazy[i];
    if (2*i < 2*MAXST) lazy[2*i] += lazy[i];
    if (2*i+1 < 2*MAXST) lazy[2*i+1] += lazy[i];
    lazy[i] = 0;
}

void update(int i, int bl, int br, int tl, int tr, const int &add) {
    pushLazy(i);
    if (tl >= br || tr <= bl) return;
    if (tl >= bl && tr <= br) {
        lazy[i] += add;
        pushLazy(i);
        return;
    }
    int mid = (tl+tr)/2;
    update(2*i,bl,br,tl,mid,add);
    update(2*i+1,bl,br,mid,tr,add);
    ST[i] = ST[2*i] + ST[2*i+1];
}

int get(int i, int tl, int tr, const int &p) {
    pushLazy(i);
    if (tr-tl == 1) return ST[i].maxi;
    int mid = (tl+tr)/2;
    if (p < mid)
        return get(2*i,tl,mid,p);
    return get(2*i+1,mid,tr,p);
}

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(_,t) {
        int n; cin >> n;
        forn(i,n) cin >> arr[i];
        
        int N = (1<<(32-__builtin_clz(n+1)));
        forn(i,2*N) ST[i] = {0,0}, lazy[i] = 0;

        forn(i,n) {
            int v = get(1,0,N,arr[i]);
            update(1,arr[i],arr[i]+1,0,N,-v);
            if (arr[i] > 0) update(1,0,arr[i],0,N,1);
            pushLazy(1);
            cout << ST[1].maxi << ' ';
        }
        cout << '\n';
    }

    return 0;
}
