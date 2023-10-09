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
int const MAXB = 19;

struct shower {
    int l,r,a;
};

vi owned[MAXN];
int req[MAXN];
shower events[MAXN];
ii querying[MAXN];
vi toCheck[MAXN];
ll FT[MAXN];

void setFT (int p, ll v) {
    p += 2;
    for (int i = p; i < MAXN; i += i & -i)
        FT[i] += v;
}

ll getFT (int p) {
    p += 2;
    ll r = 0;
    for (int i = p; i; i -= i & -i)
        r += FT[i];
    return r;
}

int main() {
    int n,m; scanf("%d %d",&n,&m);
    forn(i,m) {
        int x; scanf("%d",&x); --x;
        owned[x].pb(i);
    }
    forn(i,n) scanf("%d",&req[i]);
    int k; scanf("%d",&k);
    forn(i,k) {
        int l,r,a; scanf("%d %d %d",&l,&r,&a); --l, --r;
        events[i] = {l,r,a};
    }

    forn(i,n) querying[i] = {-1,k};

    forn(_,MAXB) {
        forn(i,m+5) FT[i] = 0;
        forn(i,n) {
            int l = querying[i].fst, r = querying[i].snd;
            if (r-l > 1) {
                int mid = (l+r)/2;
                toCheck[mid].pb(i);
            }
        }
        forn(i,k) {
            if (events[i].l <= events[i].r) {
                setFT(events[i].l,events[i].a);
                setFT(events[i].r+1,-events[i].a);
            }
            else {
                setFT(events[i].l,events[i].a);
                setFT(m,-events[i].a);

                setFT(0,events[i].a);
                setFT(events[i].r+1,-events[i].a);
            }

            for (auto &o : toCheck[i]) {
                ll s = 0;
                for (auto &p : owned[o]) {
                    s += getFT(p);
                    if (s >= req[o]) break;
                }
                if (s >= req[o]) querying[o].snd = i;
                else querying[o].fst = i;
            }
            toCheck[i].clear();
        }
    }

    forn(i,n) 
        if (querying[i].snd == k) puts("NIE");
        else printf("%d\n",querying[i].snd+1);

    return 0;
}
