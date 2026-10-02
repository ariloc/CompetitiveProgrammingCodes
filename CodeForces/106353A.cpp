#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < n; i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define sz(c) (int)(c).size()
#define pb push_back
#define fst first
#define snd second
#define all(c) (c).begin(),(c).end()

using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;

int const MAXN = 1005;
int const INF = 2e9;

vector<ii> op;
int a[MAXN];

void mov(int a, int b, int *arr, int n, int off, bool domov = true) {
    vi auxi;
    forn(i,n) if (i < a || i > a+2) auxi.pb(arr[i]);
    vi auxi2;
    forn(i,b) auxi2.pb(auxi[i]);
    forsn(i,a,a+3) auxi2.pb(arr[i]);
    forsn(i,b,n-3) auxi2.pb(auxi[i]);
    forn(i,n) arr[i] = auxi2[i];

    if (domov) op.pb({a+off,b+off});
}

set<vi> vis;
map<vi,vector<pair<ii,vi>>> posib;
map<vi,pair<ii,vi>> P;

void bfs(int *arr, int off) {
    queue<vi> Q;
    vector<ii> auxi;
    forn(i,5) auxi.pb({arr[i],i});
    sort(all(auxi));
    vi auxi2(5);
    forn(i,5) auxi2[auxi[i].snd] = i;

    vi start = auxi2;
    vi fin = {0,1,2,3,4};

    Q.push(start);
    vis.insert(start);
    while (!Q.empty()) {
        auto e = Q.front(); Q.pop();

        if (e == fin) {
            break;
        }

        auto &ref = posib[e];
        for (auto &dest : ref) {
            if (!vis.count(dest.snd)) {
                vis.insert(dest.snd);
                P[dest.snd] = {{dest.fst.fst+off,dest.fst.snd+off},e};
                Q.push(dest.snd);
            }
        }
            
    }

    vector<ii> ops;
    while (fin != start) {
        ops.pb(P[fin].fst);
        fin = P[fin].snd;
    }
    reverse(all(ops));
    for (auto &i : ops) op.pb(i);
}

void solve(int *arr, int n, int off = 0) {
    if (n == 5) {
        bfs(arr,off);
        return;
    }
    ii mini = {INF,-1};
    forn(i,n) mini = min(mini,{arr[i],i});
    vi auxi;
    if (mini.snd <= n-3) {
        mov(mini.snd,0,arr,n,off);
    }
    else if (mini.snd <= n-2) {
        mov(mini.snd-1,mini.snd-2,arr,n,off);
        mov(mini.snd-1,0,arr,n,off);
    }
    else {
        mov(mini.snd-2,mini.snd-4,arr,n,off);
        mov(mini.snd-2,0,arr,n,off);
    }

    solve(arr+1,n-1,off+1);
}

int main() {
    vi perm = {0,1,2,3,4};
    do {
        forn(i,3) forn(j,3) if (i != j) {
            int auxi[5];
            forn(k,5) auxi[k] = perm[k];
            mov(i,j,auxi,5,0,false);
            vi ret;
            forn(k,5) ret.pb(auxi[k]);
            posib[perm].pb({{i,j},ret});
        }
    } while (next_permutation(all(perm)));

    int n; cin >> n;

    forn(i,n) cin >> a[i];

    solve(a,n);

    
    cout << sz(op) << '\n';
    for (auto &i : op) cout << i.fst+1 << ' ' << i.snd+1 << '\n';
    

    return 0;
}
