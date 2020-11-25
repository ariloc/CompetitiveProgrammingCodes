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

const int MAXN = 2002;
const int INF = 1e9;

ii rob[MAXN], lightsX[MAXN];
int distsReg[MAXN];
multiset<int> distsU;
priority_queue<ii,vector<ii>,greater<ii>> distsD;

int main() {
    int n,m; scanf("%d %d",&n,&m);
    forn(i,n) scanf("%d %d",&rob[i].fst,&rob[i].snd);
    forn(i,m) scanf("%d %d",&lightsX[i].fst,&lightsX[i].snd);
    sort(lightsX,lightsX+m);

    dforn(i,m) lightsX[i].snd = max(lightsX[i].snd,lightsX[i+1].snd);

    int mini = INF, delta = 0;
    forn(i,n) {distsD.push({0,i}); distsU.insert({0});}
    //int cnt = 10; //tmp
    while (true) {
        int ult = distsD.top().fst;
        while (!distsD.empty() && distsD.top().fst == ult) {
               // if (cnt-- >= 0) cerr << ult << ' ' << delta << endl;
            auto x = distsD.top();
            distsU.erase(distsU.find(distsReg[x.snd]));
            distsD.pop();

            ii e = rob[x.snd]; e.fst += delta;
            int h = lower_bound(lightsX,lightsX+m,e) - lightsX;
            if (h == m || e.snd > lightsX[h].snd) continue;
            distsU.insert(lightsX[h].snd-e.snd+1);;
            distsReg[x.snd] = lightsX[h].snd-e.snd+1;
            distsD.push({lightsX[h].fst-e.fst+1 + delta,x.snd}); // sumo delta porque el resto está desactualizado
        }
        mini = min(mini,delta+(distsU.empty() ? 0 : (*(distsU.rbegin()))));
        if (distsU.empty()) break;
        //if (cnt-- >= 0) cout << delta << ' ' << (*distsD.begin()).fst << ' ' << (*distsD.begin()).snd << endl;
        delta += (distsD.top().fst-delta);
    }
    if (mini == INF) mini = 0;

    printf("%d",mini);

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
