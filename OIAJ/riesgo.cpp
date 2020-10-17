#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define all(c) (c).begin(),(c).end()

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;

const int MAXN = 1e5+5;
// pruebo todas las posibilidades que sean factibles, porque no son tantas
vector<vi> X = {{-1,0,0,1},{-2,-1,-1,0,0,1,1,2},{-3,-2,-2,-2,-2,-1,-1,0,0,1,1,2,2,2,2,3},{-4,-3,-3,-3,-3,-2,-2,-1,-1,0,0,1,1,2,2,3,3,3,3,4}};
vector<vi> Y = {{0,-1,1,0},{0,-1,1,-2,2,-1,1,0},{0,-2,-1,1,2,-2,2,-3,3,-2,2,-2,-1,1,2,0},{0,-2,-1,1,2,-3,3,-3,3,-4,4,-3,3,-3,3,-2,-1,1,2,0}};

map<ii,vi> pers;
map<ii,bool> done;
bitset<MAXN> ill;

vector<int> riesgo(vector<int> &x, vector<int> &y, int D, vector<int> &positivos) {
    vi rta((int)x.size()+1,0);
    int mk = 0;
    for(auto &i : positivos) {ill[i] = true; rta[0]++; mk++;}
    queue<ii> Q[2];
    forn(i,x.size()) {
        pers[{x[i],y[i]}].pb(i);
        if (ill[i]) {
            Q[0].push({x[i],y[i]}); done[{x[i],y[i]}] = true;
        }
    }

    int lvl = 1, ind = 0;
    while(!Q[0].empty() or !Q[1].empty()) {
        while (not Q[ind].empty()) {
            auto e = Q[ind].front(); Q[ind].pop();
            forn(j,D) forn(k,X[j].size()) {
                int tX = e.fst+X[j][k], tY = e.snd+Y[j][k];
                if (done.count({tX,tY})) continue;
                auto it = pers.find({tX,tY});
                if (it == pers.end()) continue;
                rta[lvl] += (int)it->snd.size(); mk += (int)it->snd.size();
                done[{tX,tY}] = true;
                Q[(ind+1)%2].push({tX,tY});
            }
        }
        ind = (ind+1)%2; lvl++;
    }
    rta[(int)x.size()] = (int)x.size()-mk;
    return rta;
}
