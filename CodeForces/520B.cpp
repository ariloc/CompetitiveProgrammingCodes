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

const int MAXN = 1e5+5;

bool done[MAXN];

int main() {
    FAST_IO;

    int n,m; cin >> n >> m;

    queue<ii> Q;
    Q.push({n,0});
    done[n] = true;

    while (!Q.empty()) {
        auto e = Q.front(); Q.pop();

        if (e.fst == m) return cout << e.snd, 0;

        if (2*e.fst < MAXN && !done[2*e.fst]) done[2*e.fst] = true, Q.push({2*e.fst, e.snd+1});
        if (e.fst-1 >= 0 && !done[e.fst-1]) done[e.fst-1] = true, Q.push({e.fst-1, e.snd+1});
    }

    cout << -1;

    return 0;
}