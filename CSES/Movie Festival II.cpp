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

const int MAXN = 2e5;

ii movies[MAXN];

int main() {
    int n,k,rta = 0; scanf("%d %d",&n,&k);
    forn(i,n) scanf("%d %d",&movies[i].fst,&movies[i].snd);
    sort(movies,movies+n,[](const ii &lhs, const ii &rhs){if (lhs.snd == rhs.snd) return lhs.fst < rhs.fst; return lhs.snd < rhs.snd;});

    multiset<int> ends;
    forn(i,n) {
        auto it = ends.upper_bound(movies[i].fst); bool flag = false;
        if (it != ends.begin() and *prev(it) <= movies[i].fst) {ends.erase(prev(it)); flag = true;}
        if (flag or (int)ends.size() < k) {ends.insert(movies[i].snd); rta++;}
    }

    printf("%d",rta);

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
