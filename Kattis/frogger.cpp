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
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

const int MAXT = 1e5+5;
const int MAXL = 25;
const int MAXLEN = 55;

const int X[] = {0,1,0,-1,0};
const int Y[] = {1,0,-1,0,0};

char frogger[MAXL][MAXLEN];
bool done[MAXL][MAXLEN];

int main() {
    int t; scanf("%d",&t);

    forn(o,t) {
        int x; scanf("%d",&x);
        int n,m; scanf("%d %d",&n,&m);
        forn(i,n+2) scanf("%s",frogger[n+1-i]);

        queue<ii> Q[2];
        forn(i,m) if (frogger[0][i] == 'F') Q[0].push({0,i});

        bool act = 0; int used = 0;
        bool arrived = 0;
        while ( (!Q[0].empty() || !Q[1].empty()) && !arrived && ((used++) < x)) {
            forn(i,n+2) forn(j,m) done[i][j] = 0;
            while (!Q[act].empty()) {
                auto e = Q[act].front(); Q[act].pop();

                if (frogger[e.fst][e.snd] == 'G') {arrived = true; break;}

                forn(k,5) {
                    int tY = e.fst + Y[k], tX = e.snd + X[k];
                    if (tY < 0 || tX < 0 || tY >= n+2 || tX >= m) continue;
                    if (done[tY][tX]) continue;
                    if (frogger[tY][((tX + used*(tY&1 ? -1 : 1))%m + m)%m] == 'X') continue;
                    done[tY][tX] = true, Q[1^act].push({tY,tX});
                }
            }
            act ^= 1;
        }

        if (arrived) printf("The minimum number of turns is %d.\n",used-1);
        else puts("The problem has no solution.");
    }

    return 0;
}