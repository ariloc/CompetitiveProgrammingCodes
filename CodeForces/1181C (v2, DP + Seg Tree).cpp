#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;
typedef long double ld;

int const MAXN = 1005;
int const INF = 2e9;

struct mon {
    int v;
    mon(int vv) : v(vv){};
    mon(){};

    mon operator+(const mon &o) const {
        return mon(min(v,o.v));
    }
};

string mat[MAXN];
int hi[MAXN][MAXN];
int le[MAXN][MAXN];
mon ST[2*MAXN];
int N;

void update(int p, int v) {
    p += N;
    ST[p].v = v;
    while (p > 1) p /= 2, ST[p] = ST[2*p] + ST[2*p+1];
}

mon query(int l, int r) {
    mon auxi = {INF};
    for(l += N, r += N; l < r; l /= 2, r /= 2) {
        if (l&1) auxi = auxi + ST[l++];
        if (r&1) auxi = auxi + ST[--r];
    }
    return auxi;
}

int main() {
    FAST_IO;

    int n,m; cin >> n >> m;

    forn(i,n) {
        cin >> mat[i];
        mat[i].pb('$'); // dummy
    }

    N = n+3;

    forn(j,m) hi[n-1][j] = 1;
    forn(j,m) dforn(i,n-1) {
        if(mat[i][j] == mat[i+1][j])
            hi[i][j] = hi[i+1][j]+1;
        else hi[i][j] = 1;
    }

    ll rta = 0;
    dforn(j,m) {
        forn(i,N) ST[i+N].v = INF;
        forn(i,n) {
            if (mat[i][j] == mat[i][j+1])
                le[i][j] = le[i][j+1]+1;
            else le[i][j] = 1;
        }


        forn(i,n) ST[i+N].v = le[i][j];
        dforsn(i,1,N) ST[i] = ST[2*i] + ST[2*i+1];

        dforn(i,n) {
            int st = hi[i][j];
            int cur = i;
            if (cur+st >= n || hi[cur+st][j] != st) continue;
            cur += st;
            if (cur+st >= n || hi[cur+st][j] < st) continue;

            cur += 2*st;

            int mini = query(i,cur).v;
            rta += mini;
        }
    }

    cout << rta << '\n';

    return 0;
}
