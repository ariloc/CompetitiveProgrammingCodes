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

int const MAXN = 2e5+5;

int go[MAXN], disc[MAXN];
map<ii,int> reg;

int main() {
    FAST_IO;

    int n; cin >> n;
    forn(i,n) cin >> go[i+1];

    ll turns = 0;
    forn(i,n) turns += go[i+1];

    int q; cin >> q;
    forn(_,q) {
        int s,t,u; cin >> s >> t >> u;
        
        auto it = reg.find({s,t});
        if (it != reg.end()) {
            int up = (*it).snd;
            turns -= max(0,go[up]-disc[up]);
            disc[(*it).snd]--;
            reg.erase(it);
            turns += max(0,go[up]-disc[up]);
        }

        if (u > 0) {
            turns -= max(0,go[u]-disc[u]);
            disc[u]++;
            reg[{s,t}] = u;
            turns += max(0,go[u]-disc[u]);
        }

        cout << turns << '\n';
    }
   
    return 0;

}
