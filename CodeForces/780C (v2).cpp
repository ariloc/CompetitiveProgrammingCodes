#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define snd second
#define fst first
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;

int const MAXN = 2e5+5;

vi G[MAXN];
bitset<MAXN> done,done2;
int cmp[MAXN];

int dfs(int st) {
    done[st] = true;

    for (auto &i : G[st]) {
        if (!done[i]) return dfs(i);
    }

    return st;
}

void dfs2(int st, int col=1, int p=-1) {
    done2[st] = true;
    cmp[st] = col;

    int cnt = 0;
    for (auto &i : G[st])
        if (!done2[i]) {
            cnt++;
            if (col == cnt || cnt == p) cnt++;
            if (col == cnt || cnt == p) cnt++;
            dfs2(i,cnt,col);
        }
}

int main() {
    FAST_IO;
    
    int n; cin >> n;

    forn(i,n-1) {
        int x,y; cin >> x >> y; --x, --y;
        G[x].pb(y), G[y].pb(x);
    }

    int st = dfs(0);
    dfs2(st);

    int maxi = 0;
    forn(i,n) maxi = max(maxi,cmp[i]);
    cout << maxi << '\n';
        
    forn(i,n) cout << cmp[i] << " \n"[i == n-1];

    return 0;
}
