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

const int MAXN = 22;
vi G[MAXN];
bitset<MAXN> done;

int dfs(int st) {
    done[st] = true;

    int sum = 0;
    for (auto &i : G[st])
        if (!done[i]) sum += dfs(i);

    return sum+1;
}

int main() {
    FAST_IO;

    int t; cin >> t;

    forn (i,t) {
        done.reset(); forn(j,MAXN) G[j].clear(); // reset
        int n; cin >> n;

        string a,b; cin >> a >> b;

        bool posib = true;
        forn (j,a.size()) {
            if (a[j] > b[j]) {posib = false; break;}
            if (a[j] != b[j]) {
                G[b[j]-'a'].pb(a[j]-'a');
                G[a[j]-'a'].pb(b[j]-'a');
            }
        }

        if (!posib) {cout << "-1\n"; continue;}

        int rta = 0;
        forn (j,MAXN) if (!done[j]) rta += max(0,dfs(j)-1);

        cout << rta << '\n';
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!