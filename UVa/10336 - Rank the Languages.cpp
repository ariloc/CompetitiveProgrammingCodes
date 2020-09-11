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

const int X[] = {0,1,0,-1};
const int Y[] = {1,0,-1,0};
const int MAXA = 26;

pair<int,char> blocks[MAXA];

int main() {
    FAST_IO;

    int t; cin >> t;

    forn(o,t) {
        vector<string> lang;
        forn(i,MAXA) blocks[i] = {0,i}; // reset
        int n,m; cin >> n >> m;
        if (!n or !m) {cout << "World #" << o+1 << '\n'; continue;}
        forn(i,n) {string s; cin >> s; lang.pb(s);}
        vector<vector<bool>> done(lang.size(),vector<bool>(lang[0].size(),0));

        forn(i,lang.size()) forn(j,lang[0].size()) {
            if (!done[i][j]) {
                queue<ii> Q;
                done[i][j] = true; blocks[lang[i][j]-'a'].fst++;
                Q.push({i,j});

                while (not Q.empty()) {
                    auto e = Q.front(); Q.pop();

                    forn(k,4) {
                        int tY = e.fst+Y[k], tX = e.snd+X[k];
                        if (tY >= (int)lang.size() or tX >= (int)lang[0].size() or tY < 0 or tX < 0) continue;
                        if (done[tY][tX]) continue;
                        if (lang[tY][tX] != lang[e.fst][e.snd]) continue;
                        done[tY][tX] = true;
                        Q.push({tY,tX});
                    }
                }
            }
        }

        cout << "World #" << o+1 << '\n';
        sort(blocks,blocks+MAXA,[](const ii &a, const ii &b){if (a.fst == b.fst) return a.snd > b.snd; return a.fst < b.fst;});
        dforn(i,MAXA) {
            if (!blocks[i].fst) break;
            cout << (char)(blocks[i].snd+'a') << ": " << blocks[i].fst << '\n';
        }
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
