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

const int MAXN = 2e5+2;
const int INF = 1e7;

struct nodo {
    int v,d;

    bool operator< (const nodo &o) const{
        return o.d < d;
    }
};

vector<nodo> G[MAXN];
set<int> fields;
vi fieldsArr;
vi D1,P1;
vi Drest;

void dijkstra (int st, vi &P, vi &D) {
    priority_queue<nodo> Q;
    D[st] = 0;
    Q.push({st,0});

    while (not Q.empty()) {
        auto x = Q.top(); Q.pop();

        for (auto &i : G[x.v]) {
            if (D[i.v] == -1 or D[i.v] > i.d + x.d) {
                P[i.v] = x.v;
                D[i.v] = i.d + x.d;
                Q.push({i.v,D[i.v]});
            }
        }
    }
}

int main() {
    FAST_IO;

    int n,m,k;
    cin >> n >> m >> k;

    D1.resize(n+1,-1);
    P1.resize(n+1,-1);

    if (k == 2) {
        int a,b;
        cin >> a >> b;
        G[a].push_back({b,1});
        G[b].push_back({a,1});
    }
    else {
        forn (i,k) {
            int f;
            cin >> f; f--;
            fields.insert(f);
            fieldsArr.push_back(f);
        }
    }

    forn (i,m) {
        int a,b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back({b,1});
        G[b].push_back({a,1});
    }

    dijkstra(0,P1,D1);

    if (k == 2) {cout << D1[n-1]; return 0;}

    vi pathF;
    int cnt = 0;
    bool found = false;
    for (int i = n-1; i != -1; i = P1[i]) {
        if (fields.count(i)) {
            if (!found) {
                found = true;
                pathF.push_back(INF);
                fields.erase(i);
            }
            else {pathF.push_back(cnt); cnt = 0;}
        }
        if (found) cnt++;
    }
    if (pathF.size() <= k-2) cout << D1[n-1];
    else if (pathF.size() == k) {
        sort(all(pathF));
        cout << D1[n-1]-(pathF[0]-1);
    }
    else {
        int a = -1;
        ii chosen = {-1,INF}; // v,d
        for (auto &i : fields) a = i;
        Drest.resize(n+1,-1);
        dijkstra(a,P1,Drest);

        for (auto &i : fieldsArr) {
            if (i == a) continue;
            if (Drest[i] < chosen.snd) {
                chosen = {i,Drest[i]};
            }
        }

        G[chosen.fst].push_back({a,1});
        G[a].push_back({chosen.fst,1});
        dijkstra(0,P1,D1);
        cout << D1[n-1];
    }

    return 0;
}