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
typedef pair<int,int> ii;
typedef long long ll;
typedef long double ld;

const int MAXN = 4005;
const int INF = 2e9;

vi G[MAXN], cmp[MAXN];
bitset<MAXN> done;
int deg[MAXN], col[MAXN];
int prox_libre = 0;

void dfs (int st) {
    done[st] = true;
    cmp[prox_libre].pb(st);
    col[st] = prox_libre;

    for (auto &i : G[st])
        if (!done[i]) dfs(i);
}

int isComplete (int ind) {
    int sz = (int)cmp[ind].size();
    int min_deg = INF, choose = -1;
    for (auto &i : cmp[ind])
        if (deg[i] < sz-1 && deg[i] < min_deg)
            min_deg = deg[i], choose = i;
    return choose;
}

int main() {
    FAST_IO;

    int t; cin >> t;

    forn(_,t) {
        int n; cin >> n;

        forn(i,n) G[i].clear(), deg[i] = 0, done[i] = false, cmp[i].clear(), col[i] = -1;
        prox_libre = 0;

        forn(i,n) {
            string s; cin >> s;
            forn(j,s.size()) {
                if (s[j]-'0' > 0) G[i].pb(j), G[j].pb(i), deg[i]++;
            }
        }

        forn(i,n) if (!done[i]) dfs(i), prox_libre++;

        if (prox_libre == 1) {cout << "0\n"; continue;}

        vi rta;
        forn(i,prox_libre) {
            int x = isComplete(i);
            if (x != -1) {
                rta.pb(x); break;
            }
        }

        int mini = INF, min_cmp = -1;
        if (rta.empty()) {
            forn(i,prox_libre)
                if ((int)cmp[i].size() < mini)
                    mini = (int)cmp[i].size(), min_cmp = i;

            if (prox_libre == 2 || (int)cmp[min_cmp].size() <= 2)
                rta = cmp[min_cmp];
            else {
                int node = cmp[min_cmp].back();
                rta.pb(node);
                int min_deg = INF, choose = -1;
                forn(i,n) if (col[i] != col[node]) {
                    deg[i]++;
                    if (deg[i] < min_deg) min_deg = deg[i], choose = i;
                }
                rta.pb(choose);
            }
        }

        cout << (int)rta.size() << '\n';
        for (auto &i : rta) cout << i+1 << ' ';
        cout << '\n';
    }
      
    return 0;
}

