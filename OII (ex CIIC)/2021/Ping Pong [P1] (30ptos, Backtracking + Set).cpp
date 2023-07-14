#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define pb push_back
#define fst first
#define snd second
#define all(c) (c).begin(),(c).end()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

const int MAXN = 32;

int val[MAXN][MAXN];

ll recur (set<int> &posib) {
    if (posib.empty()) return 0;

    int aux = *posib.begin(); posib.erase(posib.begin());
    vi vals;
    for (auto &i : posib) vals.pb(i);

    ll maxi = 0;
    for (auto &i : vals) {
        posib.erase(i);
        maxi = max(maxi,recur(posib)+val[aux][i]);
        posib.insert(i);
    }

    posib.insert(aux);
    return maxi;
}

int main() {
    int n; scanf("%d",&n);

    forn(i,n) forn(j,n) scanf("%d",&val[i][j]);

    set<int> posib;
    forn(i,n) posib.insert(i);
    printf("%lld",recur(posib));

    return 0;
}