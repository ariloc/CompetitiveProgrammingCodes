#include<bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;

int const MAXN = 1e5+5;

vi G[MAXN];
vi lst;
bitset<MAXN> done;

int dfs(int st){
    done[st] = true;
    int cnt = 0;
    bool leaf = true;
    for (auto &i : G[st])
        if (!done[i])
            cnt += dfs(i), leaf = false;
    cnt += leaf;
    lst.pb(cnt);
    return cnt;
}

int main() {
    FAST_IO;

    int n; cin >> n;

    forn(i,n-1) {
        int x; cin >> x; --x;
        G[i+1].pb(x), G[x].pb(i+1);
    }

    dfs(0);

    sort(all(lst));

    for (auto &i : lst)
        cout << i << ' ';

    return 0;
}
