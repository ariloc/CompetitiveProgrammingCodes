#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

const int MAXN = 55;
const int X[] = {0,1,0,-1};
const int Y[] = {1,0,-1,0};

char dice[MAXN][MAXN];
int id[MAXN][MAXN];
bool done[MAXN][MAXN], done2[MAXN][MAXN];

int main() {
    FAST_IO;

    int w,h,t = 0;
    while (cin >> w >> h) {
        if (!w and !h) break;
        memset(done,0,sizeof(done));
        memset(done2,0,sizeof(done2));
        forn(i,h) cin >> dice[i];

        int prox_libre = 1;
        forn(i,h) forn(j,w) if (!done2[i][j] and dice[i][j] == 'X') { // divide in unique ids
            queue<ii> Q; Q.push({i,j}); done2[i][j] = true;
            while(!Q.empty()) {
                ii e = Q.front(); Q.pop();
                id[e.fst][e.snd] = prox_libre;
                forn(k,4) {
                    int tY = Y[k]+e.fst, tX = X[k]+e.snd;
                    if (tY >= h or tX >= w or tY < 0 or tX < 0) continue;
                    if (done2[tY][tX] or dice[tY][tX] != 'X') continue;
                    done2[tY][tX] = true; Q.push({tY,tX});
                }
            }
            prox_libre++;
        }

        vi allDice;
        forn(i,h) forn(j,w) if (!done[i][j] and dice[i][j] != '.') {
            set<int> ids;
            queue<ii> Q; Q.push({i,j}); done[i][j] = true;
            while(!Q.empty()) {
                ii e = Q.front(); Q.pop();
                if (done2[e.fst][e.snd]) ids.insert(id[e.fst][e.snd]);
                forn(k,4) {
                    int tY = Y[k]+e.fst, tX = X[k]+e.snd;
                    if (tY >= h or tX >= w or tY < 0 or tX < 0) continue;
                    if (done[tY][tX] or dice[tY][tX] == '.') continue;
                    done[tY][tX] = true; Q.push({tY,tX});
                }
            }
            allDice.pb(ids.size());
        }

        sort(all(allDice));
        cout << "Throw " << ++t << '\n';
        forn(e,allDice.size()) {cout << allDice[e]; if (e+1 < allDice.size()) cout << ' ';}
        cout << "\n\n";
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
