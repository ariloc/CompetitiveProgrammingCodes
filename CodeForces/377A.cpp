#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define snd second
#define fst first
#define pb push_back
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

int const MAXN = 505;
int const X[] = {0,1,0,-1};
int const Y[] = {1,0,-1,0};

char tab[MAXN][MAXN];
bool done[MAXN][MAXN];
int n,m,k;

void go(int i, int j) {
    vector<ii> pushed;
    queue<ii> Q;
    Q.push({i,j});
    done[i][j] = true;

    while (!Q.empty()) {
        ii e = Q.front(); Q.pop();
        pushed.pb({e.fst,e.snd});

        forn(k,4) {
            int ty = e.fst + Y[k], tx = e.snd + X[k];
            if (ty < 0 || tx < 0 || ty >= n || tx >= m)
                continue;
            if (tab[ty][tx] == '#') continue;
            if (done[ty][tx]) continue;
            done[ty][tx] = true;
            Q.push({ty,tx});
        }
    }
    while (k > 0 && !pushed.empty()) {
        ii e = pushed.back();
        pushed.pop_back();
        tab[e.fst][e.snd] = 'X';
        --k;
    }
}

int main(){
    FAST_IO;

    cin >> n >> m >> k;

    forn(i,n) forn(j,m) cin >> tab[i][j];

    forn(i,n) forn(j,m) if (tab[i][j] == '.') {
        go(i,j); break;
    }

    forn(i,n) {
        forn(j,m) cout << tab[i][j];
        cout << '\n';
    }

    return 0;
}
