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

const int MAXN = 3e5+2;

int suspects[MAXN];
ii suspOrd[MAXN];
map<ii,int> vote;

int main() {
    FAST_IO;

    int n,p; cin >> n >> p;

    forn (i,n) suspOrd[i].snd = i;
    forn (i,n) {
        int a,b; cin >> a >> b; a--; b--;
        suspects[a]++; suspects[b]++;
        suspOrd[a].fst++; suspOrd[b].fst++;
        if (a > b) swap(a,b);
        vote[{a,b}]++;
    }

    sort(suspOrd,suspOrd+n);

    int l = 0;
    ll rta = 0;
    dforn (r,n) {
        while (l < r and suspOrd[r].fst+suspOrd[l].fst < p) l++;
        if (r == l) break;
        if (suspOrd[r].fst+suspOrd[l].fst >= p) rta += r-l;
    }

    for (auto &i : vote) {
        int calc = suspects[i.fst.fst]+suspects[i.fst.snd];
        if (calc < p) continue;
        if ((calc-i.snd) < p) rta--;
    }

    cout << rta;

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!