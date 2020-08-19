#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

const int MAXN = 2*1e5+2;

vi G[MAXN];
bitset<MAXN> done;
vi padres;
set<ii> edges;

ii furthest(int st, bool registrar = false) {
    ii best = {st,0}; // node || distance
    queue<ii> Q;
    Q.push({st,0});
    done[st] = true;

    while (not Q.empty()) {
        auto x = Q.front(); Q.pop();

        if (best.snd < x.snd)
            best = {x.fst,x.snd};

        for (auto &i : G[x.fst]) {
            if (done[i]) continue;
            if (registrar) padres[i] = x.fst;
            done[i] = true;
            Q.push({i,x.snd+1});
        }
    }

    done.reset();
    return best;
}

int main() {
    FAST_IO;

    int n,a,b,c,dist;
    cin >> n;

    forn (i,n-1) {
        int x,y;
        cin >> x >> y;
        x--; y--;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    padres.resize(n+1,-1);

    ii tmp = furthest(0);
    a = tmp.fst+1;
    tmp = furthest(a-1,true);
    b = tmp.fst+1; dist = tmp.snd;

    if (dist == n-1) {
        forn (i,n)
            if (i+1 != a and i+1 != c)
                {c = i+1; break;}
        cout << dist << '\n' << a << ' ' << b << ' ' << c;
    }
    else {
        int prev = -1;
        ii bestDist = {-1,-1}; // node || distance
        queue<ii> Q;
        for (int i = b-1; i != -1; i = padres[i]) {
            Q.push({i,0});
            done[i] = true;

            // registro aristas entre b y a
            if (prev == -1) prev = i;
            else {
                edges.insert({min(prev,i),max(prev,i)});
                prev = i;
            }
        }
        while (not Q.empty()) {
            auto &x = Q.front(); Q.pop();

            if (x.snd > bestDist.snd)
                bestDist = x;

            for (auto &i : G[x.fst]) {
                if (done[i]) continue;
                done[i] = true;
                Q.push({i,x.snd+1});
            }
        }
        c = bestDist.fst+1;

        cout << dist + bestDist.snd << '\n' << a << ' ' << b << ' ' << c;
    }

    return 0;
}