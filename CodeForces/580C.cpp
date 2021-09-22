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

const int MAXN = 1e5+4;

bitset<MAXN> cats;
bitset<MAXN> done;
vi G[MAXN];
int n,m,rta = 0;

int dfs (int st, int accum) {
    done[st] = true;

    int gone = 0;
    for (auto &i : G[st]) {
        if (done[i]) {gone++; continue;}
        if ((cats[i] ? accum+1 : 0) > m) continue;
        dfs(i,(cats[i] ? accum+1 : 0));
    }

    if (gone == G[st].size() and st != 0) rta++;
}

int main() {
    FAST_IO;

    cin >> n >> m;

    forn (i,n) {int x; cin >> x; cats[i] = (bool)x;}

    forn (i,n-1) {
        int a,b;
        cin >> a >> b; a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    dfs(0,(cats[0] ? 1 : 0)); cout << rta;

    return 0;
}