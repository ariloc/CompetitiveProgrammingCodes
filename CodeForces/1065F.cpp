 #include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define pb push_back
#define fst first
#define snd second
#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> ii;

int const MAXN = 1e6+5;

vi G[MAXN];
bitset<MAXN> done;
int dp[MAXN][2];
int n,k;

multiset<int> dfs(int st, int l = 0) {
    done[st] = true;

    bool ok = true;
    
    vector<ii> vals;
    multiset<int> child;
    for (auto &i : G[st]) {
        if (!done[i]) {
            multiset<int> ch = dfs(i,l+1);
            ok = false;

            while (!ch.empty() && (*ch.rbegin()) - l > k) {
                ch.erase(prev(ch.end()));
            }

            vals.pb({i,sz(ch)});

            if (sz(ch) > sz(child)) swap(ch,child);
            for (auto &j : ch) child.insert(j);
        }
    }

    if (ok) {
        child.insert(l);
        dp[st][0] = dp[st][1] = 1;
        return child;
    }

    int acc = 0;
    for (auto &j : vals) if (j.snd) acc += dp[j.fst][1];
    dp[st][1] = acc;
    
    for (auto &j : vals) {
        if (j.snd) dp[st][0] = max(dp[st][0], acc - dp[j.fst][1] + dp[j.fst][0]);
        else dp[st][0] = max(dp[st][0], acc + dp[j.fst][0]);
    }

    return child;
}

int main() {
    FAST_IO;

    cin >> n >> k;

    forn(i,n-1) {
        int x; cin >> x;
        --x;
        G[x].pb(i+1), G[i+1].pb(x);
    }

    dfs(0);

    cout << dp[0][0] << '\n';

    return 0;
}
