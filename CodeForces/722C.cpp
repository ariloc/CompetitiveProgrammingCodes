#include <bits/stdc++.h>

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

const int INF = 1e9+2;
const int MAXN = 1e5+2;

struct DS {
    vi r,p;

    void init(int N) {
        p.resize(N,-1);
        r.resize(N,-1);
    }

    int find (int x) {return ((p[x] == -1) ? x : (p[x] = find(p[x])));}

    void join (int a, int b) {
        int x = find(a), y = find(b);
        if (x == y) return;
        if (r[x] > r[y]) p[y] = x;
        else {
            p[x] = y;
            if (r[x] == r[y]) r[y]++;
        }
    }
};

int num[MAXN], ord[MAXN];
ll groups[MAXN];
set<int> add;
int prox_libre = 0;

int main() {
    FAST_IO;

    int N; cin >> N;

    DS UF;
    UF.init(MAXN);

    forn (i,N) cin >> num[i];
    forn (i,N) {cin >> ord[i]; ord[i]--;}

    ll maxS = 0;
    vector<ll> r;
    r.pb(maxS);
    add.insert(ord[N-1]);
    groups[ord[N-1]] = num[ord[N-1]];
    maxS = num[ord[N-1]];

    dforsn (i,1,N-1) {
        ll toSum = num[ord[i]];
        r.pb(maxS);
        add.insert(ord[i]);
        auto it = add.lower_bound(ord[i]);
        if (it != add.begin() and ord[i]-*prev(it) == 1) {
            int aux = UF.find(*prev(it));
            toSum += groups[aux]; UF.join(*prev(it),ord[i]);
        }
        if (next(it) != add.end() and *next(it)-ord[i] == 1) {
            int aux = UF.find(*next(it));
            toSum += groups[aux]; UF.join(*next(it),ord[i]);
        };
        maxS = max(maxS, (groups[UF.find(ord[i])] = toSum) );
    }
    r.pb(maxS);

    if (N == 1) r.pop_back();
    dforn (i,r.size()) cout << r[i] << '\n';

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!