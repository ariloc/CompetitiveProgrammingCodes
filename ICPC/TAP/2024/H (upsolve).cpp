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

int const MAXN = 2e5+5;
int const MAXFT = 3*MAXN + 30;

struct seg {
    int x;
    int y1,y2;
    int ind;
    bool st;

    bool operator< (const seg &o) const {
        if (x != o.x)
            return x < o.x;
        return st < o.st;
    }
};

struct node {
    ll sum;
    int cnt;
};

int n,m;
vector<seg> rect;
vector<ii> at;
vi X,Y;
int FT[MAXFT];
vi G[MAXN];
node nodes[MAXN];
int P[3*MAXN+10];

int srchx(int x) { return lower_bound(all(X),x)-X.begin(); }
int srchy(int y) { return lower_bound(all(Y),y)-Y.begin(); }

void setFT (int p, int v) {
    p += 2;
    for (int i = p; i < MAXFT; i += i & -i)
        FT[i] += v;
}

int getFT (int p) {
    p += 2;
    int r = 0;
    for (int i = p; i; i -= i & -i)
        r += FT[i];
    return r;
}

ll solve(int st) {
    ll rta = 0;
    ll s = 0;
    int cnt = 0;
    if (!G[st].empty()) {
        for (auto &i : G[st])
            rta += solve(i);

        vector<pair<ll,int>> dp(G[st].size(),{0,0});
        dforn(i,G[st].size()) {
            s += nodes[G[st][i]].sum;
            cnt += nodes[G[st][i]].cnt;
            dp[i] = {s,cnt};
        }

        forn(i,G[st].size()-1)
            rta += dp[i+1].fst * nodes[G[st][i]].cnt + dp[i+1].snd * nodes[G[st][i]].sum;
    
        rta += s * nodes[st].cnt;
    }

    nodes[st].cnt += cnt;
    nodes[st].sum += s;
    nodes[st].sum += nodes[st].cnt;

    return rta;
}

int main() {
    FAST_IO;

    cin >> n >> m;

    forn(i,n) {
        int x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2;
        X.pb(x1); X.pb(x2);
        Y.pb(y1); Y.pb(y2);
        rect.pb({x1,y1,y2,i+1,true});
        rect.pb({x2,y1,y2,i+1,false});
    }

    forn(i,m) {
        int x,y; cin >> x >> y;
        at.pb({x,y});
        X.pb(x);
        Y.pb(y);
    }

    sort(all(X));
    sort(all(Y));
    X.erase(unique(all(X)), X.end());
    Y.erase(unique(all(Y)), Y.end());

    for (auto &k : rect) {
        k.x = srchx(k.x);
        k.y1 = srchy(k.y1);
        k.y2 = srchy(k.y2);
    }

    for (auto &k : at) {
        k.fst = srchx(k.fst);
        k.snd = srchy(k.snd);
    }

    sort(all(rect));
    sort(all(at));

    // dummy
    int dind = (int)X.size()+3;
    P[dind] = 0;
    rect.pb({dind,0,0,dind,false});

    int cur = 0;
    for (auto &k : rect) {
        //cerr << "OKA" << endl;
        while (cur < m && at[cur].fst < k.x) {
            int actrect = getFT(at[cur].snd);
            nodes[actrect].cnt++;
            ++cur;
        }

        if (k.st) {
            int parent = getFT(k.y1);
            G[parent].pb(k.ind);
            P[k.ind] = parent;
            int dif = k.ind-parent;
            setFT(k.y1, dif);
            setFT(k.y2+1, -dif);
        }
        else {
            int val = P[k.ind];
            int dif = val-getFT(k.y1);
            setFT(k.y1, dif);
            setFT(k.y2+1, -dif);
        }
    }

    ll retsum = solve(0);
    cout << fixed << setprecision(15) << (retsum*2LL)/(ld)((m*(ll)m)) << '\n';

    return 0;
}
