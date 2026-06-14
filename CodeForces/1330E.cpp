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

int const MAXN = (1<<21) + 10;

ii heap[MAXN];
vi ops;

void doit(int i, int g) {
    if (heap[2*i].fst == 0 && heap[2*i+1].fst == 0) {
        heap[i].fst = 0;
        heap[i].snd--;
    }
    else if (heap[2*i].fst > heap[2*i+1].fst) {
        heap[i].fst = heap[2*i].fst;
        doit(2*i, g-1);
    }
    else {
        heap[i].fst = heap[2*i+1].fst;
        doit(2*i+1,g-1);
    }
    if (heap[i].fst)
        heap[i].snd = heap[2*i].snd + heap[2*i+1].snd + 1;
}

bool can(int i, int g) {
    if (heap[2*i].fst == 0 && heap[2*i+1].fst == 0) {
        if (g > 0) return false;
        return true;
    }
    else if (heap[2*i].fst > heap[2*i+1].fst) {
        return can(2*i, g-1);
    }
    return can(2*i+1,g-1);
}


void go(int i, int g) {
    if (!g) return;
    while (can(i,g)) {
        doit(i,g);
        ops.pb(i);
    }
    if (heap[2*i].snd > (1<<(g-1))-1)
        go(2*i, g-1);
    if (heap[2*i+1].snd > (1<<(g-1))-1)
        go(2*i+1, g-1);
}

void mfill(int i, int h) {
    if (!h) return;
    heap[i].snd = (1<<h)-1;
    mfill(2*i,h-1);
    mfill(2*i+1,h-1);
}

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(_,t) {
        int h,g; cin >> h >> g;
        forn(i,(1<<(h+1)) + 5) heap[i] = {0,0};
        forn(i,(1<<h) - 1) cin >> heap[i+1].fst;

        mfill(1,h);

        ops.clear();
        go(1,g);

        ll s = 0;
        forn(i,(1<<g) - 1) s += heap[i+1].fst;
        cout << s << '\n';
        for (auto &i : ops) cout << i << ' ';
        cout << '\n';
    }

    return 0;
}
